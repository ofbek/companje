#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
    openni.setupUsingXMLFile();
    users.setup(&openni);
    image.setup(&openni);
    
    marina.loadImage("marina.png");
    marina.setAnchorPercent(.5, .5);
    
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){
    openni.update();
    image.update();
    users.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    image.draw(0,0,640,480);
    users.draw();

    
    for (int i=0; i<=users.getNumberOfTrackedUsers(); i++) {
        ofxTrackedUser *user = users.getTrackedUser(i);

        if (user!=NULL) {        
            
            cout << "USER: " << i << " " << user << endl;
            
            ofPoint start(user->neck.position[0].X,user->neck.position[0].Y);
            ofPoint end(user->neck.position[0].X,user->neck.position[0].Y);
            ofPoint center = start.middle(end);
            
            //marina.draw(start);
            ofSetColor(255,255,0);
            
            ofCircle(ofGetWidth()/2, ofGetHeight()/2, 20);
            ofSetLineWidth(5);
            ofLine(start,end);
            ofSetLineWidth(1);
        }
    }
    
    
}

