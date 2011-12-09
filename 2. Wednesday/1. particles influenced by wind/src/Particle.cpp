#include "Particle.h"

Particle::Particle() {
    mass = 3.0;
}

void Particle::addForce(ofVec3f force) {
    acceleration += (force / mass);
}

void Particle::update() {
    velocity += acceleration;
    position += velocity;
    acceleration.set(0,0); //acceleration needs to be recalculated in the next cycle
}

void Particle::draw() {
    
    //calculate the angle of rotation for the arrow
    float heading = atan2(velocity.y, velocity.x)-PI;
    
    ofPushMatrix();
    ofTranslate(position);            //move
    ofRotateZ(ofRadToDeg(heading));   //rotate
    ofTranslate(-mass/2,0);           //center
    ofLine(0,0,mass,0);               //draw arrow body
    ofLine(0,0,5,-5);                 //draw arrow head top
    ofLine(0,0,5,5);                  //draw arrow head bottom
    ofPopMatrix();
    
}




