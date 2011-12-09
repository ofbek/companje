#include "testApp.h"

void testApp::setup() {
    
    ofSetFrameRate(30);
    
    w = 320;
    h = 240;
    
    mov.initGrabber(w,h);
    rgb.allocate(w,h);
    grey.allocate(w,h);
    
    gui.addFloat("brightness", brightness);
    gui.addFloat("contrast", contrast);
    gui.addFloat("minArea", minArea)->setMin(1)->setMax(100);
    gui.addFloat("maxArea", maxArea)->setMin(50)->setMax(w*h/2);
    
    gui.load();
}

void testApp::update() {
    mov.update();
    
    rgb.setFromPixels(mov.getPixels(),w,h);
    
    //rgb.mirror(false, true);
    //rgb.erode();    
    //rgb.dilate();
    
    rgb.erode();    
    rgb.erode();    
    rgb.erode();    
    
    grey = rgb; //convert to grayscale
    
//    float brightness = ofMap(mouseX, 0, ofGetWidth(), 0, 1);
//    float contrast = ofMap(mouseY, 0, ofGetHeight(), 0, 1);

    grey.brightnessContrast(brightness, contrast);
    
    grey.threshold(200); //light grey
    grey.invert();
    
    contours.findContours(grey, minArea, w*h/2, 10, false);

}

void testApp::draw() {
    mov.draw (0*w,0*h);
    rgb.draw (1*w,0*h);
    grey.draw(2*w,0*h);
    
    contours.draw(2*w,0*h);
    
    gui.draw();
}



