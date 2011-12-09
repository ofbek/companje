#pragma once

#include "ofMain.h"
#include "ofxMesh.h"

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void keyPressed(int key);
    
    ofVideoGrabber mov;
    ofxMesh mesh;
    ofTexture tex;
    
    bool showWireframe;
    
    void solve(ofVec3f &a, ofVec3f &b);

    
    ofVec3f *hover,*selected;
};
