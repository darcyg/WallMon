/*
 * GeneralProcessInfo.cpp
 *
 *  Created on: Sep 7, 2011
 *      Author: arild
 */
#include <glog/logging.h>
#include <boost/algorithm/string.hpp>
#include "Ps.h"
#include "System.h"

Ps::Ps()
{
}

Ps::~Ps()
{
}

string Ps::PidToUser(int pid)
{
	vector<string> v = _Lookup(pid);
	if (v.size() == 0)
		return (string)"";
	return v[0];
}

string Ps::PidToStime(int pid)
{
	vector<string> v = _Lookup(pid);
	return v[1];
}

bool Ps::Update()
{
	if (_Update())
		return true;
	LOG(INFO) << "failed running ps command";
	return false;
}

bool Ps::_Update()
{
	// 'ps aux' format:
	// USER PID %CPU %MEM VSZ RSS TTY STAT START TIME COMMAND
	string cmd = "ps aux | awk '{print $1, $2, $9}'";
	FILE *fp = popen(cmd.c_str(), "r");
	if (fp == NULL)
		return false;
	char buf[1024 * 100];
	int numBytesRead = fread(buf, 1, 1024 * 100, fp);
	pclose(fp);
	vector<string> tokens;
	boost::split(tokens, buf, boost::is_any_of(" \n"));
	tokens.pop_back();
	if (tokens.size() % 3 != 0)
		return false;

	for (int i = 0; i < tokens.size(); i+=3) {
		vector<string> val;
		val.push_back(tokens[i]);
		val.push_back(tokens[i + 2]);
		_data[atoi(tokens[i + 1].c_str())] = val;
	}
	return true;
}

vector<string> Ps::_Lookup(int pid)
{
	map<int, vector<string> >::iterator it = _data.find(pid);
	if (it != _data.end())
		return it->second;
	Update();
	it = _data.find(pid);
	if (it != _data.end())
		return it->second;
	LOG(INFO) << "failed looking up pid from ps output";
	vector<string> v;
	return v;
}


