#ifndef TESTAPP_H
#define TESTAPP_H

#include "ofMain.h"
#include "ofxFlocking.h"
#include "Obstacle.h"

class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	void mouseDragged(int x, int y, int button);
	
	ofxFlocking flock;
    
    ofImage pig,eagle;
    
    vector<Obstacle> obstacles;

};

#endif
