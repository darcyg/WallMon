/*
 * LinuxProcessMonitorLight.h
 *
 *  Created on: Jul 2, 2011
 *      Author: arild
 */

#ifndef LINUXPROCESSMONITORLIGHT_H_
#define LINUXPROCESSMONITORLIGHT_H_

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <string>
//#include <linux/limits.h>
#include <sys/times.h>
#include <iomanip>
#include "Stat.h"

using namespace std;

class LinuxProcessMonitorLight {

public:
	LinuxProcessMonitorLight();
	virtual ~LinuxProcessMonitorLight();

	void SetStatistics(Stat<double> *readProcfs, Stat<double> *parseProcfs);
	bool Open(int pid=-1);
	bool Update();
	double SecondsSinceLastUpdate();
	bool IsFirstTime();

	// Set during constructor
	string GetUser();
	string GetStartTime();

	// stat
	double GetTotalNumPageFaultsPerSec();
	double GetUserTime();
	double GetSystemTime();
	double GetUserCpuLoad(); // in percentage
	double GetSystemCpuLoad(); // in percentage
	string GetProcessName();
	unsigned long minflt();
	unsigned long majflt();
	unsigned long utime();
	unsigned long stime();
	int pid();
	char* comm();
	long jiffy();
	unsigned int numthreads();

	// statm
	double GetTotalProgramSize(); // in megabytes
	uint64_t GetTotalProgramSizeBytes();
	unsigned long size();

	// io
	unsigned long GetTotalIoInBytes();
	unsigned long GetTotalIoOutBytes();
	unsigned long GetNetworkInBytes();
	unsigned long GetNetworkOutBytes();
	unsigned long GetStorageInBytes();
	unsigned long GetStorageOutBytes();
	float GetNumReadSysCallsPerSec();
	float GetNumWriteSysCallsPerSec();

	unsigned long rchar();
	unsigned long wchar();
	unsigned long syscr();
	unsigned long syscw();
	unsigned long readbytes();
	unsigned long writechar();
private:
	// User must call NewSample()
	Stat<double> *_statReadProcfs, *_statParseProcfs;

	// external variables
	string _user, _startTime;

	// /proc/<pid>/stat variables
	int _pid;
	char _comm[4096];
	unsigned long _minflt, _majflt, _utime, _stime;
	unsigned int _numThreads;

	// /proc/<pid>/statm variables
	unsigned long _size;

	// /proc/<pid>/io variables
	unsigned long _rchar, _wchar, _syscr, _syscw, _read_bytes, _write_bytes;
	unsigned long _prevRchar, _prevWchar, _prevSyscr, _prevSyscw, _prevReadBytes, _prevWriteBytes;

	long _jiffy; // (USER_HZ)
	long _timesinceboot;
	char _bufStat[300], _bufStatm[300], _bufIo[300];

	unsigned long _prevMinflt, _prevMajflt;
	unsigned long _prevUserTime;
	unsigned long _prevSystemTime;
	double _updateTime;
	double _prevUpdateTime;

	string _procstatfile;
	string _procstatmfile;
	string _prociofile;

	FILE *_procstat;
	FILE *_procstatm;
	FILE *_procio;

	unsigned long _totalNumBytesRead;
	unsigned long _totalNumSamples;
};
#endif /* LINUXPROCESSMONITORLIGHT_H_ */
