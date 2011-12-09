#pragma once

#include "ofMain.h"

// include ofxOsc so the compiler knows about all the 
// features of the OSC addon.
#include "ofxOsc.h"

class testApp : public ofBaseApp{
public:
    testApp();
    void setup();
    void update();
    void draw();
    void mouseMoved(int x, int y );

    // Create an instance of the ofxOscSender class.
    ofxOscSender sender;
    int mouse_x;
    int mouse_y;
};
