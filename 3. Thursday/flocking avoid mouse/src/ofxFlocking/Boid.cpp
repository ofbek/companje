/*
 *  Boid.cpp
 *  boid
 *
 *  Created by Jeffrey Crouse on 3/29/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#include "Boid.h"

float ofDist(float x1, float y1, float z1, float x2, float y2, float z2) {
	return sqrt(double((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2))); //rick
}

Boid::Boid() {

    loc.x = ofRandomWidth();
	loc.y = ofRandomHeight();
	loc.z = 0; //ofRandomHeight();
	vel = 0;
	acc = 0;
    r = 3.0;
    maxspeed = 4;
    maxforce = 0.1;
}


// Method to update location
void Boid::update(vector<Boid*> boids) {
	
	flock(boids);
	
    vel += acc;   // Update velocity
    vel.x = ofClamp(vel.x, -maxspeed, maxspeed);  // Limit speed
	vel.y = ofClamp(vel.y, -maxspeed, maxspeed);  // Limit speed
    loc += vel;
    acc = 0;  // Reset accelertion to 0 each cycle
	
	if (loc.x < -r) loc.x = ofGetWidth()+r;
    if (loc.y < -r) loc.y = ofGetHeight()+r;
    if (loc.z < -r) loc.z = ofGetHeight()+r; //rick

    if (loc.x > ofGetWidth()+r) loc.x = -r;
    if (loc.y > ofGetHeight()+r) loc.y = -r;
    if (loc.z > ofGetHeight()+r) loc.z = -r; //rick

}

void Boid::seek(ofPoint target) {
    acc += steer(target, false);
}

void Boid::avoid(ofPoint target) {
    acc -= steer(target, false);
}

void Boid::arrive(ofPoint target) {
    acc += steer(target, true);
}

// A method that calculates a steering vector towards a target
// Takes a second argument, if true, it slows down as it approaches the target
ofPoint Boid::steer(ofPoint target, bool slowdown) {
    ofPoint steer;  // The steering vector
    ofPoint desired = target - loc;  // A vector pointing from the location to the target
    
	float d = ofDist(target.x, target.y, target.z, loc.x, loc.y, loc.z); // Distance from the target is the magnitude of the vector
	
	
	// If the distance is greater than 0, calc steering (otherwise return zero vector)
    if (d > 0) {
		
		desired /= d; // Normalize desired
		// Two options for desired vector magnitude (1 -- based on distance, 2 -- maxspeed)
		if ((slowdown) && (d < 100.0f)) {
			desired *= maxspeed * (d/100.0f); // This damping is somewhat arbitrary
		} else {
			desired *= maxspeed;
		}
		// Steering = Desired minus Velocity
		steer = desired - vel;
		steer.x = ofClamp(steer.x, -maxforce, maxforce); // Limit to maximum steering force
		steer.y = ofClamp(steer.y, -maxforce, maxforce); 
		steer.z = ofClamp(steer.z, -maxforce, maxforce);  //rick
		
    }
    return steer;
}

void Boid::draw() {
    // Draw a triangle rotated in the direction of velocity
	float angle = (float)atan2(-vel.y, vel.x);
    float theta =  -1.0*angle;
	float heading2D = ofRadToDeg(theta)+90;
	
	//ofEnableAlphaBlending();
    //ofSetColor(0, 0, 0);
	ofPushStyle();
    ofFill();
    ofPushMatrix();
    ofTranslate(loc.x, loc.y, loc.z);
    ofRotateZ(heading2D);
	ofBeginShape();
    ofVertex(0, -r*2);
    ofVertex(-r, r*2);
    ofVertex(r, r*2);
    ofEndShape(true);
	//glPointSize(1);
//	glBegin(GL_POINTS);
//	glVertex3f(0,0,0);
//	glEnd();
	
    ofPopMatrix();
	ofPopStyle();
	//ofDisableAlphaBlending();
}

void Boid::flock(vector<Boid*> boids) {
	ofPoint sep = separate(boids);
	ofPoint ali = align(boids);
	ofPoint coh = cohesion(boids);
	
	// Arbitrarily weight these forces
	sep *= 1.5;
	ali *= 1.0;
	coh *= 1.0;
	
	acc += sep + ali + coh;
	
}

// Separation
// Method checks for nearby boids and steers away
ofPoint Boid::separate(vector<Boid*> boids) {
    float desiredseparation = 25.0f;
    ofPoint steer;
    int count = 0;
	
    // For every boid in the system, check if it's too close
    for (int i = 0 ; i < boids.size(); i++) {
		Boid* other = boids[i];
		
		float d = ofDist(loc.x, loc.y, loc.z, other->loc.x, other->loc.y, other->loc.z);
		
		
		// If the distance is greater than 0 and less than an arbitrary amount (0 when you are yourself)
		if ((d > 0) && (d < desiredseparation)) {
			// Calculate vector pointing away from neighbor
			ofPoint diff = loc - other->loc;
			diff /= d;			// normalize
			diff /= d;        // Weight by distance
			steer += diff;
			count++;            // Keep track of how many
		}
    }
    // Average -- divide by how many
    if (count > 0) {
		steer /= (float)count;
    }
	
	
    // As long as the vector is greater than 0
	//float mag = sqrt(steer.x*steer.x + steer.y*steer.y);
	
	float mag = sqrt(steer.x*steer.x + steer.y*steer.y + steer.z*steer.z); //rick
    if (mag > 0) {
		// Implement Reynolds: Steering = Desired - Velocity
		steer /= mag;
		steer *= maxspeed;
		steer -= vel;
		steer.x = ofClamp(steer.x, -maxforce, maxforce);
		steer.y = ofClamp(steer.y, -maxforce, maxforce);
		steer.z = ofClamp(steer.z, -maxforce, maxforce); //rick
    }
    return steer;
}

// Alignment
// For every nearby boid in the system, calculate the average velocity
ofPoint Boid::align(vector<Boid*> boids) {
    float neighbordist = 50.0;
    ofPoint steer;
    int count = 0;
    for (int i = 0 ; i < boids.size(); i++) {
		Boid* other = boids[i];
		
		float d = ofDist(loc.x, loc.y, loc.z, other->loc.x, other->loc.y, other->loc.z);
		if ((d > 0) && (d < neighbordist)) {
			steer += (other->vel);
			count++;
		}
    }
    if (count > 0) {
		steer /= (float)count;
    }
	
    // As long as the vector is greater than 0
	float mag = sqrt(steer.x*steer.x + steer.y*steer.y);
    if (mag > 0) {
		// Implement Reynolds: Steering = Desired - Velocity
		steer /= mag;
		steer *= maxspeed;
		steer -= vel;
		steer.x = ofClamp(steer.x, -maxforce, maxforce);
		steer.y = ofClamp(steer.y, -maxforce, maxforce);
		steer.z = ofClamp(steer.z, -maxforce, maxforce);

    }
    return steer;
}

// Cohesion
// For the average location (i.e. center) of all nearby boids, calculate steering vector towards that location
ofPoint Boid::cohesion(vector<Boid*> boids) {
    float neighbordist = 50.0;
    ofPoint sum;   // Start with empty vector to accumulate all locations
    int count = 0;
    for (int i = 0 ; i < boids.size(); i++) {
		Boid* other = boids[i];
		float d = ofDist(loc.x, loc.y, loc.z, other->loc.x, other->loc.y, other->loc.z);
		if ((d > 0) && (d < neighbordist)) {
			sum += other->loc; // Add location
			count++;
		}
    }
    if (count > 0) {
		sum /= (float)count;
		return steer(sum, false);  // Steer towards the location
    }
    return sum;
}

