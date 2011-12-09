/*
 *  testApp.cpp
 *  openFrameworks
 *
 *  ofxFlocking created by Jeffrey Crouse on 3/30/10.
 *
 */
 
 #include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	ofBackground(0,0,0);
	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void testApp::update() {
    
    
    ofPoint mouse(ofGetMouseX(),ofGetMouseY());
    
    bool mouseIsMoving = (mouse!=prevMouse);
    
    prevMouse = mouse;
    
	for(int i=0; i<flock.boids.size(); i++) {
        
        if (mouseIsMoving) {
            flock.boids[i]->avoid(mouse);
        }
    }
    
	flock.update();
}

//--------------------------------------------------------------
void testApp::draw() {
	flock.draw();
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {
	flock.addBoid();
}






