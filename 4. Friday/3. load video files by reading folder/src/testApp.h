#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    
    vector<ofVideoPlayer*> movies;

    ofDirectory dir;
};
