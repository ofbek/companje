#include "testApp.h"

int rows=30;
int cols=30;

int getIndex(float x, float y, float w) {
    return y*w+x;
}

float ofxDist(ofVec3f a, ofVec3f b) {
    return ofDist(a.x,a.y,b.x,b.y);
}

//--------------------------------------------------------------
void testApp::setup(){
    mov.initGrabber(640,480);
    tex.allocate(640,480,GL_RGB);
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    hover = 0;
    selected = 0;
    showWireframe = false;
    
    for (float y=0; y<=rows; y++) {
        for (float x=0; x<=cols; x++) {
            mesh.addVertex(ofVec3f(float(x)/cols*ofGetWidth(), float(y)/rows*ofGetHeight()));
            mesh.addTexCoord(ofVec3f(float(x)/cols*mov.getWidth(), float(y)/rows*mov.getHeight()));
        }
    }
    
    for (float y=0; y<rows; y++) {
        for (float x=0; x<cols; x++) {
            mesh.addTriangle(getIndex(x,y,cols+1), getIndex(x+1,y,cols+1), getIndex(x,y+1,cols+1));
            mesh.addTriangle(getIndex(x+1,y,cols+1), getIndex(x+1,y+1,cols+1), getIndex(x,y+1,cols+1));
        }
    }   
}
 
void testApp::solve(ofVec3f &a, ofVec3f &b) {

    float constraintLength = 32;
    
    ofVec3f dif = a-b;
    float distance = ofxDist(a,b);
    
    if (distance==0) return;
    
    dif = (dif / distance) * (constraintLength/2);
        
    a = (a+b)/2;
    b = (a-dif);
    a += dif;
}

//--------------------------------------------------------------
void testApp::update(){
    mov.update();
    
    hover = 0;
    
    for (int i=0; i<mesh.getVertices().size(); i++) {
        if (ofDist(mouseX,mouseY, mesh.getVertex(i).x, mesh.getVertex(i).y)<10) {
            hover = &mesh.getVertices()[i];            
        }                
    }
    
    if (selected!=0) {
        selected->set(mouseX, mouseY);
    }
    
    for (float y=0; y<rows; y++) {
        for (float x=0; x<cols; x++) {
            int i = getIndex(x,y,cols+1);
            
            ofVec3f &self = mesh.getVertices()[i];
            
            if (y<2 || y>rows-2 || x<2 || x>cols-2) {
                self.set(float(x)/cols*ofGetWidth(), float(y)/rows*ofGetHeight());
                continue;
            }
            
            
            ofVec3f &top = mesh.getVertices()[i-cols];
            ofVec3f &bottom = mesh.getVertices()[i+cols];
            ofVec3f &left = mesh.getVertices()[i-1];
            ofVec3f &right = mesh.getVertices()[i+1];
            
            solve(self,top);
            solve(self,bottom);
            solve(self,left);
            solve(self,right);
        }
    }
}


//--------------------------------------------------------------
void testApp::draw() {
  
    if (ofGetFrameNum()<100) return;
    
    mov.getTextureReference().bind();
    ofSetColor(255);
    mesh.draw();
    mov.getTextureReference().unbind();
    
    if (showWireframe) {
        glPointSize(2);
        ofSetColor(255, 255, 0);
        mesh.drawVertices();
        ofSetColor(255,50);
        glLineWidth(1);
        mesh.drawWireframe();
        ofSetColor(255,0,0);
        
        for (int j=0; j<mesh.getVertices().size(); j++) {
            int x = j % (cols+1);
            int y = j / (cols+1);
            
            if (y<1 || y>rows-1 || x<1 || x>cols-1) {
                ofSetColor(255,0,0);
            } else {
                ofSetColor(0,255,0);
            }
            ofFill();
            ofCircle(mesh.getVertices()[j], 3);
        }
        
        if (hover!=0) {
            ofNoFill();
            ofSetLineWidth(3);
            ofSetColor(255,0,0);
            ofCircle(*hover, 10);
        }
    }
}  

void testApp::mousePressed(int x, int y, int button) {
    if (hover!=0) selected = hover;
}

void testApp::mouseReleased(int x, int y, int button) {
    selected = 0;
}

void testApp::keyPressed(int key) {
    if (key=='w' || key==' ' || key==9) showWireframe=!showWireframe;
}
