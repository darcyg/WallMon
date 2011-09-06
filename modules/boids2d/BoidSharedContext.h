/*
 * BoidSharedContext.h
 *
 *  Created on: Apr 10, 2011
 *      Author: arild
 */

#ifndef BOIDSHAREDCONTEXT_H_
#define BOIDSHAREDCONTEXT_H_

#include <boost/thread/mutex.hpp>
#include "Entity.h"

using namespace std;

typedef boost::mutex::scoped_lock scoped_lock;

enum BoidView {
	BOID_TYPE_CORE,
	BOID_TYPE_PROCESS,
	BOID_TYPE_PROCESS_NAME,
	BOID_TYPE_NODE
};


class BoidSharedContext {
public:
	int red, green, blue;
	Shape boidShape;
	BoidView boidView;
	static float tailLength;

	// Which type of boids to show within a metric
	static bool showCpuBoid, showMemoryBoid, showNetworkBoid, showStorageBoid;
	static BoidView boidViewToShow; // Simple filter for the different metrics

	BoidSharedContext(int red_, int green_, int blue_, Shape shape_, BoidView boidType_);

	void SetDestination(float x, float y);
	void GetDestination(float *x, float *y);

	void SetTailLength(float length);
	float GetTailLength();

	void EnableHighlight();
	void DisableHighlight();
	bool IsHighlighted();
private:
	float _destx, _desty;
	float _tailLength;
	bool _isHighlighted;
	boost::mutex _mutex;
};
#endif /* BOIDSHAREDCONTEXT_H_ */