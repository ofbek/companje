#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    for (int i=0; i<7; i++) {
        
        string filename = "drum" + ofToString(i+1) + ".wav";
        
        sounds[i].loadSound(filename);
    }

}

//--------------------------------------------------------------
void testApp::update(){
  
}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key>='0' && key<'7') {
        sounds[key-'0'].play();
    }
}
