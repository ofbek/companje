#include "testApp.h"

testApp::testApp() {
}

void testApp::setup(){
	ofBackground(33);
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	

	sender.setup("255.255.255.255", 1234);	
}

void testApp::update(){
}


void testApp::draw(){
	ofSetColor(255,0,30);
	ofCircle(mouse_x,mouse_y,10);
}


void testApp::mouseMoved(int x, int y ){		
	ofxOscMessage m;
	m.setAddress("/ball");
	m.addIntArg(x);
	m.addIntArg(y);
	sender.sendMessage(m);
	
	mouse_x = x;
	mouse_y = y;
}
