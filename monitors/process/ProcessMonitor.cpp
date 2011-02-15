/*
 * ProcessMonitorHandler.cpp
 *
 *  Created on: Feb 1, 2011
 *      Author: arild
 */

#include <glog/logging.h>
#include "ProcessMonitor.h"
#include "System.h"

#define KEY		"TestKey"

void printb(unsigned char *a, int len)
{
	LOG(INFO) << "PRINTB";
	for (int i = 0; i < len; i++)
		LOG(INFO) << "-> " << (unsigned int) a[i];
}

void ProcessMonitorHandler::OnStart()
{
	_dataPacket = new DataPacket();
}

void ProcessMonitorHandler::OnStop()
{
	delete _dataPacket;
}

string ProcessMonitorHandler::GetKey()
{
	return KEY;
}

void ProcessMonitorHandler::Handle(unsigned char *data, int length)
{
	if (_dataPacket->ParseFromArray(data, length) == false)
		LOG(ERROR) << "Protocol buffer parsing failed: ";
	LOG(INFO) << "Num threads: " << _dataPacket->numthreads();
	LOG(INFO) << "User time  : " << _dataPacket->usertime();
}

void ProcessMonitorCollector::OnStart()
{
	int pid = System::GetPid("spotify");
	if (pid == -1)
		LOG(ERROR) << "process name not found";

	_monitor = new LinuxProcessMonitor(pid);
	_dataPacket = new DataPacket();
	_buffer = new unsigned char[1024];
	memset(_buffer, 0, 1024);
}

void ProcessMonitorCollector::OnStop()
{
	delete _monitor;
	delete _dataPacket;
	delete _buffer;
}

string ProcessMonitorCollector::GetKey()
{
	return KEY;
}

int ProcessMonitorCollector::GetScheduleIntervalInMsec()
{
	return 2000;
}

int ProcessMonitorCollector::Sample(unsigned char **data)
{
	_monitor->update();
	int numThreads = _monitor->num_threads();
	double userTime = _monitor->getUserTime();
	double systemTime = _monitor->getSystemTime();
	double userCpuLoad = _monitor->getUserCPULoad();
	double systemCpuLoad = _monitor->getSystemCPULoad();

	_dataPacket->set_numthreads(numThreads);
	_dataPacket->set_usertime(userTime);
	_dataPacket->set_systemtime(systemTime);
	_dataPacket->set_usercpuload(userCpuLoad);
	_dataPacket->set_systemcpuload(systemCpuLoad);

	if (_dataPacket->SerializeToArray(_buffer, 1024) != true)
		LOG(ERROR) << "Protocol buffer serialization failed";
	*data = _buffer;
	return _dataPacket->ByteSize();
}

// class factories - needed to bootstrap object orientation with dlfcn.h
extern "C" ProcessMonitorHandler *create_handler()
{
	return new ProcessMonitorHandler;
}

extern "C" void destroy_handler(ProcessMonitorHandler *p)
{
	delete p;
}

extern "C" ProcessMonitorCollector *create_collector()
{
	return new ProcessMonitorCollector;
}

extern "C" void destroy_collector(ProcessMonitorCollector *p)
{
	delete p;
}
