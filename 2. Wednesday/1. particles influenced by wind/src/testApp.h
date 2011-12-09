#pragma once

#include "ofMain.h"
#include "Particle.h"

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void mouseDragged(int x, int y, int button);
    
    vector<Particle> particles;   //this is an array with dynamic size

    ofVec2f wind;
};
