#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofSetFrameRate(500);
    //ofSetVerticalSync(true);
    ofSetWindowTitle("My First Program");
}

//--------------------------------------------------------------
void testApp::update(){
    //ofSetWindowTitle(ofToString(mouseX));
    
    //some of the different datatypes you can use:
    int myNumber = 5;  // for whole numbers (integer values)
    float myDecimalNumber = 6.6;    // for decimal numbers like 7.887897234
    string test = "this is a test";  // for text strings like "Your Name"
    
    
    string street = "C. Sundt Gate";
    int houseNumber = 55;
    
    string address = street + " " + ofToString(houseNumber);
    
    ofSetWindowTitle(address);
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255, 0, 0);
    
    int x = ofGetMouseX();
    int y = ofGetMouseY();
           
    ofCircle(x, y, 50);
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

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}