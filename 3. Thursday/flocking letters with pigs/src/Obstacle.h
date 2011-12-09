#pragma once

#include "ofMain.h"

class Obstacle {
public:
    
    Obstacle(); //constructor (has no type)
    void draw();
    
    ofVec2f position;
    float size;
    
};