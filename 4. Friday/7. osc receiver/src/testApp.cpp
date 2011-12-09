#include "testApp.h"

testApp::testApp() {
}

void testApp::setup(){
	ofBackground(33);
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	
	receiver.setup(1234);
	mouse_x = -1;
}


void testApp::update(){
	while(receiver.hasWaitingMessages()) {
		ofxOscMessage m;
		receiver.getNextMessage(&m);
		
		if(m.getAddress() == "/ball") {
			mouse_x = m.getArgAsInt32(0);
			mouse_y = m.getArgAsInt32(1);
		}
	}
}


void testApp::draw(){
	ofSetColor(0,255,10);
	ofCircle(mouse_x, mouse_y, 10);
}
