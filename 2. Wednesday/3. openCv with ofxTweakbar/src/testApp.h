#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxTweakbar.h"

class testApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
        
    ofVideoGrabber mov;
    ofxCvColorImage rgb;
    ofxCvGrayscaleImage grey;
    ofxCvContourFinder contours;
    
    int w,h;
    float contrast,brightness;
    float minArea, maxArea;
};

