#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ini.load("settings.txt");
    
    cout << ini.get("speed",10) << endl;
    cout << ini.get("filename","test.png") << endl;
    
    ini.set("speed",50);
    
    bool fullscreen = ini.get("fullscreen",false);
    
    ofSetFullscreen(fullscreen);
    
    int bg = ini.get("backgroundColor",0);

    ofBackgroundHex(bg);
    
    circle = ini.get("circle.position",ofPoint(0,0));
    circleSize = ini.get("circle.size",10);
    
    ofxSetWindowRect(ini.get("window",ofRectangle(0,0,100,100)));
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofCircle(circle,circleSize);
}

