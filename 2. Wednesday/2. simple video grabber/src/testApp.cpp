#include "testApp.h"

//-----------------------------------------
void testApp::setup(){
    
    //webcam.listDevices();  //show a list of all cams
    //webcam.setDeviceID(2); //use other webcam
    
    ofSetFullscreen(true);
    
    int width = ofGetScreenWidth();
    int height = ofGetScreenHeight();
    
    webcam.initGrabber(width, height);
}
   
//-----------------------------------------
void testApp::update(){
    webcam.update();
}

//-----------------------------------------
void testApp::draw() {
    webcam.draw(0,0);
}  
