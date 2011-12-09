#pragma once

#include "ofMain.h"
#include "ofxIniSettings.h"

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    ofxIniSettings ini;
    
    ofPoint circle;
    int circleSize;
};
