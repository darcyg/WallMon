/*
 * DataRouter.h
 *
 *  Created on: Jan 31, 2011
 *      Author: arild
 */

#ifndef DATAROUTER_H_
#define DATAROUTER_H_

#include <string>
//#include <boost/unordered_map.hpp>
#include <map>
#include "IDataHandler.h"

//using namespace std;
typedef std::map<string, IDataHandler *> handlerMap;

class DataRouter {
public:
	DataRouter();
	virtual ~DataRouter();
	void RegisterHandler(IDataHandler *handler);
	void Route(char *packet, int length);
private:
	handlerMap _handlers;
};

#endif /* DATAROUTER_H_ */
