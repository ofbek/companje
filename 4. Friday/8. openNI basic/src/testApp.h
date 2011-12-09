#pragma once

#include "ofMain.h"
#include "ofxOpenNI.h"
#include "ofxExtras.h"

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    ofxOpenNIContext openni;
    ofxImageGenerator image;
    ofxDepthGenerator depth;
    ofxUserGenerator users;
    
    ofImage marina;
};
