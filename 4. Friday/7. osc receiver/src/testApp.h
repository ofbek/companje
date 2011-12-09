#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

class testApp : public ofBaseApp{
public:
    testApp();
    void setup();
    void update();
    void draw();

    ofxOscReceiver receiver;
    int mouse_x;
    int mouse_y;
};
