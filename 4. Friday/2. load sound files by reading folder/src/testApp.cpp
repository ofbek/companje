#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    int numFiles = dir.listDir("sounds");   //reads the contents of the datafolder
                                            //use listDir(".") to read data folder
    
    printf("number of files found: %d\n", numFiles);
        
    for (int i=0; i<numFiles; i++) {
        
        printf("file %d: %s\n", i, dir.getPath(i).c_str());
        
        //this creates a new ofSoundPlayer somewhere in memory
        //the address of the new ofSoundPlayer is stored in the 'sound' variable.
        //the value of the sound variable is stored in the vector
        
        ofSoundPlayer *sound = new ofSoundPlayer();
        sound->loadSound(dir.getPath(i));
        sounds.push_back(sound);
        
        //to clear the memory of the ofSoundPlayer object at the end of the program
        //call 'delete sounds[i]'. The address will than still be in the vector so you
        //also need the call the sounds.erase function to remove it from there.
        
        //but in this program you don't need to because we want to use the sounds
        //during the whole program.
        
    }
    

}

//--------------------------------------------------------------
void testApp::update(){
  
}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key>='0' && key<'7') {
        sounds[key-'0']->play();
    }
}
