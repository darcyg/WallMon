/**
 * @file   Scheduler.cpp
 * @Author Arild Nilsen
 * @date   January, 2011
 *
 * Schedules user-defined collectors according to specified intervals.
 */

#include <glog/logging.h>
#include "Wallmon.pb.h"
#include "Scheduler.h"
#include "Streamer.h"

using namespace std;

/**
 * Container for user-data associated with timers.
 *
 * Timers in libev have a special attribute where the user (programmer)
 * can store arbitrary data. The timers used here stope an instance of this class.
 */
class CollectorEvent {
public:
	Context *ctx; // The context which is shared and known by the collector
	IDataCollector *collector; // The collector implementation itself
	IDataCollectorProtobuf *collectorProtobuf;
	int sockfd; // The file descriptor of associated streamer socket

	double timeStampInMsec;
	double divergenceinMsec; // Accumulated divergence on sample invocations
	unsigned int numSamples; // Number of times the collector has been invoked

	CollectorEvent()
	{
		timeStampInMsec = 0.;
		divergenceinMsec = 0.;
		numSamples = 0;
	}
};

Streamer *Scheduler::streamer;

Scheduler::Scheduler(Streamer *streamer)
{
	_loop = ev_default_loop(0);
	_timers = new TimerContainer();
	Scheduler::streamer = streamer;
}

Scheduler::~Scheduler()
{
	ev_loop_destroy(_loop);
	delete _timers;
}

void Scheduler::Start()
{
	_running = true;
	_thread = boost::thread(&Scheduler::_ScheduleForever, this);
	LOG(INFO) << "Scheduler started";
}

void Scheduler::Stop()
{
	LOG(INFO) << "stopping Scheduler...";
	_running = false;
	_loopCondition.notify_one(); // In case no timers are registered
	// Stop all timers, this will cause the event loop to terminate
	TimerContainer::iterator it;
	for (it = _timers->begin(); it != _timers->end(); it++) {
		ev_timer *timer = *it;
		ev_timer_stop(_loop, timer);

		// Release memory allocated in RegisterColllector()
		delete timer->data;
		delete timer;
	}
	_thread.join(); // Wait for event loop to terminate
	LOG(INFO) << "Scheduler stopped";
}

/**
 * Registers a given collector with an event timer that is
 * inserted into the global event loop.
 */
void Scheduler::RegisterColllector(IBase &collector, Context *ctx)
{
	ev_timer *timer = new ev_timer();
	int sockfd = streamer->SetupStream(ctx->server);

	double scheduleIntervalInSec = ctx->sampleFrequencyMsec / (double) 1000;
	ev_timer_init(timer, &Scheduler::_TimerCallback, scheduleIntervalInSec, 0.);
	timer->repeat = scheduleIntervalInSec;

	CollectorEvent *event = new CollectorEvent();
	event->ctx = ctx;
	event->collector = dynamic_cast<IDataCollector *>(&collector);
	event->collectorProtobuf = dynamic_cast<IDataCollectorProtobuf *>(&collector);
	event->sockfd = sockfd;

	timer->data = (void *) event;
	ev_timer_again(_loop, timer);
	_loopCondition.notify_one();

	// Book-keep for cleanup
	_timers->push_back(timer);
}

/**
 * Starts the event loop that schedules timer events.
 *
 * The ev_run() call blocks as long as there are one or more timers registered.
 * In order to avoid spinning when there are no timers registered, the RegisterCollector()
 * call will notify a shared condition variable whenever a new collector/timer is registered.
 */
void Scheduler::_ScheduleForever()
{
	LOG(INFO) << "Scheduler started and serving requests";
	while (_running) {
		_loopCondition.wait(_loopMutex);
		ev_run(_loop, 0);
	}
}

/**
 * This method serves as a callback when a timer is scheduled.
 */
void Scheduler::_TimerCallback(struct ev_loop *loop, ev_timer *w, int revents)
{
	ev_timer_again(loop, w); // Reschedule collector
	double timeStampNowInMsec = ev_now(loop);
	CollectorEvent *event = (CollectorEvent *) w->data;

	// Update statistics
	event->divergenceinMsec += (timeStampNowInMsec - event->timeStampInMsec);
	event->timeStampInMsec = timeStampNowInMsec;
	event->numSamples += 1;

	WallmonMessage msg;
	msg.set_key(event->ctx->key);

	if (event->collector) {
		void *data;
		int dataLen = event->collector->Sample(&data);
		msg.set_data(data, dataLen);
	}
	else if (event->collectorProtobuf) {
		event->collectorProtobuf->Sample(&msg);
	}
	else
		LOG(FATAL) << "unknown collector type";

	w->repeat = event->ctx->sampleFrequencyMsec / (double) 1000;

	// Compose network message
	StreamItem &item = * new StreamItem(msg.ByteSize());
	msg.SerializeToArray(item.GetPayloadStartReference(), msg.ByteSize());
	item.sockfd = event->sockfd;

	// Queue message for transmission
	Scheduler::streamer->Stream(item);

	if (event->numSamples % 100 == 0) {
		LOG(INFO) << "--- Statistics about collector. Key=" << event->ctx->key << " ---";
		LOG(INFO) << "Num samples        : " << event->numSamples;
		LOG(INFO) << "Total divergence   : " << event->divergenceinMsec << " msec";
		LOG(INFO) << "Average. divergence: " << event->divergenceinMsec
				/ (double) event->numSamples << " msec";
	}
}

