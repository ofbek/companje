#include "testApp.h"

//--------------------------------------------------------------
bool isMouseMoving() {
    static ofPoint pmouse;
    ofPoint mouse(ofGetMouseX(),ofGetMouseY());
    bool mouseIsMoving = (mouse!=pmouse);
    pmouse = mouse;
    return mouseIsMoving;
}

//--------------------------------------------------------------
void testApp::setup() {
	ofBackground(0,0,0);
	ofSetFrameRate(60);
    ofEnableAlphaBlending();
    
    for (int i=0; i<10; i++) {
        obstacles.push_back(Obstacle());
    }
    
    pig.loadImage("pig.png");
    pig.setAnchorPercent(.5, .5);
    eagle.loadImage("eagle.gif");
    eagle.setAnchorPercent(.5, .5);
    
}

//--------------------------------------------------------------
void testApp::update() {
    
    //boids avoid the mouse if the is moving
    if (isMouseMoving()) {
        for(int i=0; i<flock.boids.size(); i++) {            
            flock.boids[i].avoid(ofPoint(mouseX,mouseY), .25);
        }
    }
    
    //boids avoid all obstacles
    for(int i=0; i<flock.boids.size(); i++) {
        for(int j=0; j<obstacles.size(); j++) {            
            
            ofPoint obsPos = obstacles[j].position;
            ofPoint boidPos = flock.boids[i].loc;
            
            float size = obstacles[j].size;
            float dist = ofDist(obsPos.x, obsPos.y, boidPos.x, boidPos.y);
            
            dist = dist - size; // bigger objects are closer
           
            if (dist==0) {
                
                flock.boids[i].alive = false;
                
            } else {
                
                if (flock.boids[i].alive) {
                    
                    float fear = 10/dist;   //based on obs size and distance
                    flock.boids[i].avoid(obstacles[j].position, fear);  //fear between 0..1
                }
            }
        }
    }
    
	flock.update();
}

//--------------------------------------------------------------
void testApp::draw() {

    for(int i=0; i<flock.boids.size(); i++) {
        
        float angle = (float)atan2(-flock.boids[i].vel.y, flock.boids[i].vel.x);
        float heading2D = ofRadToDeg(-angle)+90;
        
        ofPushMatrix();
        ofTranslate(flock.boids[i].loc);
        ofRotateZ(heading2D);
        eagle.draw(0,0);
        ofPopMatrix();
    }
    
    for (int i=0; i<obstacles.size(); i++) {
        pig.draw(obstacles[i].position);
        obstacles[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {
	flock.addBoid(x,y);
    
    //let's kill something
    if (flock.boids.size()>100) flock.boids.erase(flock.boids.begin());
}






