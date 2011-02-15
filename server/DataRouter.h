/*
 * DataRouter.h
 *
 *  Created on: Jan 31, 2011
 *      Author: arild
 */

#ifndef DATAROUTER_H_
#define DATAROUTER_H_

#include <string>
#include <boost/unordered_map.hpp>
#include "IDataHandler.h"

using std::string;

typedef boost::unordered_map<string, IDataHandler *> handlerMap;

class DataRouter {
public:
	DataRouter();
	virtual ~DataRouter();
	void RegisterHandler(IDataHandler *handler);
	void Route(char *packet, int length);
private:
	handlerMap *_handlers;

};

#endif /* DATAROUTER_H_ */
