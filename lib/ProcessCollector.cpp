/*
 * Collector.cpp
 *
 *  Created on: Feb 1, 2011
 *      Author: arild
 */

#include <glog/logging.h>
#include <boost/foreach.hpp>
#include <vector>
#include "ProcessCollector.h"
#include "System.h"
#include "unistd.h"

#define MESSAGE_BUF_SIZE				(1024 * 1000) * 5
const double NETWORK_MAX_IN_AND_OUT_BYTES = 1024 * 1024 * 100;


ProcessCollector::ProcessCollector()
{
	context = new Context();
	filter = new ProcessesMessage::ProcessMessage;
}

/**
 * Tells the process collector to only look for defined process names
 * during its life-cycle
 */
void ProcessCollector::SetProcesses(list<string> processNames)
{
	_processNames = processNames;
}

void ProcessCollector::OnInit(Context *ctx)
{
	// The framework injects its own mutable instance of Context, therefore
	// the context instance that the user has been modifying must be copied
	ctx->key = context->key;
	ctx->sampleFrequencyMsec = context->sampleFrequencyMsec;
	ctx->servers = context->servers;

	delete context;
	context = ctx;

	_numCores = System::GetNumLogicalCores();
	_totalMemoryMb = (double)System::GetTotalMemory() / 1024.;
	_hasSupportForProcIo = System::HasSupportForProcPidIo();
	// Create a process monitor for each pid on system
	_monitors = new vector<LinuxProcessMonitor *>();
	_pidMonitor = new PidMonitor;
	_buffer = new char[MESSAGE_BUF_SIZE];
	memset(_buffer, 0, MESSAGE_BUF_SIZE);

	if (_processNames.size() == 0)
		_FindAllNewProcesses();
	else
		_AddDefinedProcesses();

	LOG(INFO) << "num cores detected: " << _numCores;
	LOG(INFO) << "total memory detected: " << _totalMemoryMb << " MB";
	LOG(INFO) << "num processes being monitored: " << _monitors->size();
}

void ProcessCollector::OnStop()
{
	delete _buffer;
	delete filter;
}

void ProcessCollector::Sample(WallmonMessage *msg)
{
	if (_processNames.size() == 0)
		_FindAllNewProcesses();

	ProcessesMessage processesMsg;
	// Drop the BOOST_FOREACH macro due to ~5% overhead. This loop is critical for performance
	for (vector<LinuxProcessMonitor *>::iterator it = _monitors->begin(); it != _monitors->end(); it++) {
		LinuxProcessMonitor *monitor = (*it);
		monitor->update();
		ProcessesMessage::ProcessMessage *processMsg = processesMsg.add_processmessage();

		double util;
		if (filter->has_processname()) {
			string processName = monitor->comm();
			// Remove '(' and ')' from the process name returned from comm()
			processName.erase(processName.length() - 1, 1);
			processName.erase(0, 1);
			processMsg->set_processname(processName);
		}
		if (filter->has_pid()) {
			processMsg->set_pid(monitor->pid());
		}
		if (filter->has_usercpuload())
			processMsg->set_usercpuload(monitor->getUserCPULoad());
		if (filter->has_systemcpuload())
			processMsg->set_systemcpuload(monitor->getSystemCPULoad());
		if (filter->has_usercpuutilization()) {
			util = monitor->getUserCPULoad() / (double)(_numCores * 100);
			processMsg->set_usercpuutilization(util * 100.);
		}
		if (filter->has_systemcpuutilization()) {
			util = monitor->getSystemCPULoad() / (double)(_numCores * 100);
			processMsg->set_systemcpuutilization(util * 100.);
		}
		if (filter->has_memoryutilization()) {
			util = monitor->getTotalProgramSize() / (double)_totalMemoryMb;
 			processMsg->set_memoryutilization(util * 100.);
		}
		if (filter->has_networkinutilization()) {
			util = monitor->GetNetworkInInBytes() / NETWORK_MAX_IN_AND_OUT_BYTES;
			processMsg->set_networkinutilization(util * 100.);
		}
		if (filter->has_networkoututilization()) {
			util = monitor->GetNetworkOutInBytes() / NETWORK_MAX_IN_AND_OUT_BYTES;
			processMsg->set_networkoututilization(util * 100.);
		}
	}

	if (processesMsg.SerializeToArray(_buffer, MESSAGE_BUF_SIZE) != true)
		LOG(ERROR) << "Protocol buffer serialization failed";
	msg->set_data(_buffer, processesMsg.ByteSize());
}

void ProcessCollector::_FindAllNewProcesses()
{
	_pidMonitor->Update();
	vector<int> pids = _pidMonitor->GetDifference();
	BOOST_FOREACH(int pid, pids)
		_AddProcess(pid);
}

void ProcessCollector::_AddDefinedProcesses()
{
	BOOST_FOREACH(string processName, _processNames)
		_AddProcess(System::GetPid(processName));
}

void ProcessCollector::_AddProcess(int pid)
{
	LinuxProcessMonitor *monitor = new LinuxProcessMonitor();
	if (monitor->open(pid) == false) {
		delete monitor;
		_pidMonitor->Ignore(pid);
		return;
	}
	if (_hasSupportForProcIo)
		monitor->OpenIo(pid);
	monitor->update();
	_monitors->push_back(monitor);
}


