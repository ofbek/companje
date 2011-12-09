#pragma once

#include "ofMain.h"

class Particle {
public:
    
    Particle();
    
    void draw();
    void update();
    void addForce(ofVec3f force);
    
    ofVec2f position;
    ofVec2f velocity;
    ofVec2f acceleration;
    
    float mass;
};

