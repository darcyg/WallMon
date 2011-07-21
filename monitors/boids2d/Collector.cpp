
#include <glog/logging.h>
#include "ProcessCollector.h"
#include "System.h"
#include "WallView.h"
#include "PortForwarder.h"

#define KEY		"BOIDS"
#define SAMPLE_FREQUENCY_MSEC 	1000

extern "C" ProcessCollector *create_collector()
{
	ProcessCollector *p = new ProcessCollector();
	p->context->key = KEY;

	if (System::IsRocksvvCluster()) {
		vector<string> servers = WallView(2, 1, 3, 3).GetGrid();
		p->context->AddServers(servers);
	}
	else if (System::GetHostname().compare(0, 5, "arild") == 0) {
		p->context->AddServer("localhost");
	}
	else {
		// Currently assumed to be ice cluster
		p->context->AddServer("129.242.19.61");
		//p->context->AddServers(PortForwarder::HostnamesToRocksvvRootNodeMapping(servers));
	}
	p->context->sampleFrequencyMsec = SAMPLE_FREQUENCY_MSEC;
	p->filter->set_processname("");
	p->filter->set_pid(0);
	p->filter->set_usercpuutilization(0);
	p->filter->set_systemcpuutilization(0);
	p->filter->set_memoryutilization(0);

	if (System::HasSupportForProcPidIo()) {
		LOG(INFO) << "support for /proc/<pid>/io detected, monitoring it";
		p->filter->set_networkinutilization(0);
		p->filter->set_networkoututilization(0);
	}
	return p;
}

extern "C" void destroy_collector(ProcessCollector *p)
{
	delete p;
}
