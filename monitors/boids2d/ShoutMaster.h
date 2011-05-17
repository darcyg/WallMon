/*
 * ShoutEventRouter.h
 *
 *  Created on: May 13, 2011
 *      Author: arild
 */

#ifndef SHOUTEVENTROUTER_H_
#define SHOUTEVENTROUTER_H_

#include <vector>
#include <boost/tuple/tuple.hpp>
#include <boost/thread.hpp>
#include <shout/event-types/touch-events.h>
#include "Queue.h"
#include "Scene.h"

using namespace std;

class TouchEvent {
public:
	Scene *scene;
	float sceneX, sceneY, realX, realY;
	TouchEvent() {}
	virtual ~TouchEvent() {}

};

class ShoutMaster {
public:
	ShoutMaster();
	virtual ~ShoutMaster();
	void Start();
	void Stop();
	Queue<TouchEvent> *GetOutputQueue();
	void Register(Scene *scene);
private:
	boost::thread _thread;
	bool _running;
	Queue<TouchEvent> *_outputQueue;
	vector<Scene *> _scenes;
	void _HandleShoutEventsForever();
	void _ParseShoutEvent(shout_event_t *event);
	Scene *_GlobalCoordsToScene(float x, float y);
};

#endif /* SHOUTEVENTROUTER_H_ */
