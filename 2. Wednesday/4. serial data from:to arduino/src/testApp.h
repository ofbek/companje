#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void mousePressed(int x, int y, int button);

    //void gotMessage(ofMessage msg);
    
    ofSerial serial;

};
