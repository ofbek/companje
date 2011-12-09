#include "testApp.h"

void ofxSetColorHSB(float h, float s, float b, float a=255) {
    if (b==0) return ofSetColor(0,0,0,a); //black
    if (s==0) return ofSetColor(b,b,b,a); //gray
    
    h *= 6.0 / 255.0;
    s *= 1.0 / 255.0;
    
    float x = b * (1-s);
    float y = b * (1-s*(h-int(h)));
    float z = b * (1-s*(1-(h-int(h))));
    
    switch (int(h)) {
        case 0: return ofSetColor(b,z,x,a); //red
        case 1: return ofSetColor(y,b,x,a); //green
        case 2: return ofSetColor(x,b,z,a); 
        case 3: return ofSetColor(x,y,b,a); //blue
        case 4: return ofSetColor(z,x,b,a); 
        case 5: return ofSetColor(b,x,y,a); //back to red
    }
}

//--------------------------------------------------------------
void testApp::setup() {
	ofBackground(0);
	
	context.setupUsingXMLFile();
	depth.setup(&context);
	user.setup(&context, &depth);
	
	ofEnableSmoothing();
	ofEnableAlphaBlending();
	
	bone.setAnchorPercent(.5,.5);
	bone.loadImage("rainbow.png");

	head.setAnchorPercent(.5,.5);
	head.loadImage("asdf.gif");
		
	debug = false;
}

//--------------------------------------------------------------
void testApp::update(){
	context.update();
	user.update();
}

//--------------------------------------------------------------
void testApp::draw() {
	if (debug) {
		depth.draw(0,0,640,480);
		user.draw();
	}
	
	ofSetColor(255,255,255);
	//monster.draw(0,0,450,500);
	
	vector<ofxTrackedUser*> users = user.getTrackedUsers();
	
	for (int i=0; i<users.size(); i++) {
		ofxTrackedUser &user = *users[i];		
		
		//ofxSetColorHSB(float(i)/users.size()*255, 255, 255);
				
		ofxLimb limbs[] = {user.left_shoulder, user.right_shoulder, user.hip, user.neck, user.right_lower_torso, user.right_upper_torso, user.left_lower_torso, user.left_upper_torso, user.right_lower_arm, user.left_lower_arm, user.right_upper_arm, user.left_upper_arm, user.right_upper_leg, user.right_lower_leg, user.left_upper_leg,user.left_lower_leg};

		for (int i=0; i<16; i++) {
			ofxLimb limb = limbs[i];
			ofPushMatrix();
			ofTranslate(limb.center.x,limb.center.y);
			ofRotateZ(limb.rotation);
			ofSetColor(255,255,255,255);
			bone.draw(0,0,30,limb.length);
			ofPopMatrix();
		}
		
		ofPushMatrix();
		ofSetColor(255,255,255);
		ofTranslate(user.neck.begin.x, user.neck.begin.y);
		ofRotateZ(user.neck.rotation);
		head.draw(0,0, user.neck.length*2, user.neck.length*2);
		ofPopMatrix();
		

	}
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if (key=='d') debug=!debug;
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

