#include "testApp.h"

int ofxIndex(float x, float y, float w) {
    return y*w+x;
}

ofPoint ofxLerp(ofPoint start, ofPoint end, float amt) {
    return start + amt * (end - start);
}
             
void drawTexture(ofBaseHasTexture &tex, ofPoint lt, ofPoint rt, ofPoint rb, ofPoint lb, int rows=10, int cols=10) {

    float tw = tex.getTextureReference().getWidth();
    float th = tex.getTextureReference().getHeight();
    
    ofMesh mesh;
            
    for (int x=0; x<=cols; x++) {
        float f = float(x)/cols;
        ofPoint vTop(ofxLerp(lt,rt,f));
        ofPoint vBottom(ofxLerp(lb,rb,f));

        ofPoint tTop(ofxLerp(ofPoint(0,0),ofPoint(tw,0),f));
        ofPoint tBottom(ofxLerp(ofPoint(0,th),ofPoint(tw,th),f));
        
        for (int y=0; y<=rows; y++) {
            float f = float(y)/rows;

            ofPoint v = ofxLerp(vTop,vBottom,f);
            //v.z = sin(f*TWO_PI)*50;
            mesh.addVertex(v);
            
            mesh.addTexCoord(ofxLerp(tTop,tBottom,f));
       }
    }
    
    for (float y=0; y<rows; y++) {
        for (float x=0; x<cols; x++) {
            mesh.addTriangle(ofxIndex(x,y,cols+1), ofxIndex(x+1,y,cols+1), ofxIndex(x,y+1,cols+1));
            mesh.addTriangle(ofxIndex(x+1,y,cols+1), ofxIndex(x+1,y+1,cols+1), ofxIndex(x,y+1,cols+1));
        }
    }
        
    tex.getTextureReference().bind();
    mesh.draw();
    tex.getTextureReference().unbind();
    mesh.drawVertices();
}

//--------------------------------------------------------------
void testApp::setup(){
    cur = 0;
    
    ofSetFrameRate(60);

    mov.initGrabber(320,240);
    
    corners[0].set(0,0);
    corners[1].set(320,0);
    corners[2].set(320,240);
    corners[3].set(0,240);
}

//--------------------------------------------------------------
void testApp::update(){
    mov.update();
}


//--------------------------------------------------------------
void testApp::draw() {
    
    ofSetColor(255);
    mov.draw(ofGetWidth()-320,0,320,240);

    ofSetColor(255);
    drawTexture(mov, corners[0], corners[1], corners[2], corners[3]);

    ofSetColor(255, 0, 255);
    ofSetLineWidth(1);
    ofNoFill();
    ofBeginShape();
    for (int i=0; i<4; i++) {
        ofVertex(corners[i]);
    }
    ofEndShape();
    ofFill();
    for (int i=0; i<4; i++) {
        ofCircle(corners[i],5);
    }
}  

void testApp::mousePressed(int x, int y, int button) {
    for (int i=0; i<4; i++) {
        if (ofDist(x,y,corners[i].x,corners[i].y)<10) {
            cur = &corners[i];
        }
    }
}

void testApp::mouseDragged(int x, int y, int button) {
    if (cur) {
        cur->set(x,y);   
    }
}

void testApp::mouseReleased(int x, int y, int button) {
    cur = 0;
}

void testApp::keyPressed(int key) {

}
