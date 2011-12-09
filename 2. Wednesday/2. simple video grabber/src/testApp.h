#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class testApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();

    ofVideoGrabber webcam;
};
