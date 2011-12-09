#pragma once

#include "ofMain.h"
#include "ofxMesh.h"

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void mouseDragged(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void keyPressed(int key);
    
    ofVideoGrabber mov;
    
    ofPoint corners[4];
    ofPoint *cur;
    
};
