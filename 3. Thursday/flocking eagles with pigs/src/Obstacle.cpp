//this is the obstacle's sourcefile

#include "Obstacle.h"

Obstacle::Obstacle() {
    position.set(ofRandomWidth(), ofRandomHeight());
    size = ofRandom(10, 50);
}


void Obstacle::draw() {
    
    //this obstacle can draw itself
    
    ofNoFill();
    ofCircle(position, size);
    
}