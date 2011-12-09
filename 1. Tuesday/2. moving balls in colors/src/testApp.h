#pragma once

#include "ofMain.h"

#define NUM 100

class Ball {
public:
    ofPoint pos;    //it's better to use ofVec3f instead of ofPoint
    ofPoint vel;
    ofColor color;
    int curSize;
    int orgSize;
};

class testApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
	
	//Ball ball;
    Ball balls[NUM];
    
};








