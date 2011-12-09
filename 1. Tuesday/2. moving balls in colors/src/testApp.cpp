#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);             //limit framerate to 60
    ofSetBackgroundAuto(false);     //turn off automatic background clearing
    ofEnableAlphaBlending();        //enable transparency
    ofBackground(0);                //set background to black
    ofSetFullscreen(true);          //go fullscreen
    
    for (int i=0; i<NUM; i++) {
        balls[i].vel.set(ofRandom(-5,5), ofRandom(-5,5));
        balls[i].orgSize = ofRandom(15,50);
        
        float hue = ofRandom(255);
        float sat = 255;
        float bri = 255;
        float alpha = ofRandom(100,255);
                
        balls[i].color = ofColor::fromHsb(hue, sat, bri, alpha);
    }
}

//--------------------------------------------------------------
void testApp::update() {
    
    for (int i=0; i<NUM; i++) {
        balls[i].pos += balls[i].vel;

        //check if ball hits the sides of the screen, if so then bounce back
        if (balls[i].pos.x-balls[i].curSize > ofGetWidth()) balls[i].vel.x *= -1;   
        if (balls[i].pos.y-balls[i].curSize > ofGetHeight()) balls[i].vel.y *= -1;    
        if (balls[i].pos.x-balls[i].curSize < 0) balls[i].vel.x *= -1;
        if (balls[i].pos.y-balls[i].curSize < 0) balls[i].vel.y *= -1;
    }
}

//--------------------------------------------------------------
void testApp::draw(){

    //draw a semi transparent black rectangle
    ofSetColor(0,20);              
    ofRect(0,0,ofGetWidth(),ofGetHeight());
    
    //draw all circles
    for (int i=0; i<NUM; i++) {
        ofSetColor(balls[i].color);
        
        balls[i].curSize = balls[i].orgSize * sin(ofGetElapsedTimef()+i);
        ofSetCircleResolution(float(i)/NUM*10+3);
        ofCircle(balls[i].pos.x, balls[i].pos.y, balls[i].curSize);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    printf("window is resized %d,%d\n",w,h);
    
    for (int i=0; i<NUM; i++) {
        balls[i].pos.set(ofRandom(ofGetScreenWidth()), ofRandom(ofGetScreenHeight()));
    }
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}