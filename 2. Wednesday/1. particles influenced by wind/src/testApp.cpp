#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(33);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofSetLineWidth(2);
    
    wind.set(.5,0);
}
   
//--------------------------------------------------------------
void testApp::update() {
        
    
    for (int i=0; i<particles.size(); i=i+1) {        
        particles[i].addForce(wind);
        particles[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofLine( 0,ofGetHeight()/2,    100,ofGetHeight()/2); //long
    ofLine(80,ofGetHeight()/2-10, 100,ofGetHeight()/2); //top
    ofLine(80,ofGetHeight()/2+10, 100,ofGetHeight()/2); //bottom
    
    ofDrawBitmapString("wind", 10, ofGetHeight()/2+20);
    
    for (int i=0; i<particles.size(); i++) {
        particles[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    Particle p;
    p.position.set(x,y);
    p.mass = ofRandom(3,20);
    p.velocity.set(ofRandom(-5,5), ofRandom(-5,5));
    particles.push_back(p);
    
    if (particles.size()>100) particles.erase(particles.begin());
}





