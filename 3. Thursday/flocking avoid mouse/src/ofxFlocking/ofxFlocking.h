/*
 *  Flock.h
 *  flock
 *
 *  Created by Jeffrey Crouse on 3/30/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *  Modified by Rick Companje
 */

#ifndef OFX_FLOCKING_H
#define OFX_FLOCKING_H

#include "ofMain.h"
#include "Boid.h"

class ofxFlocking {
public:
	ofxFlocking();
	void update();
	void draw();
	void addBoid();
    	
	vector<Boid*> boids;
};

#endif