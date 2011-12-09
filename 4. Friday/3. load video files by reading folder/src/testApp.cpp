#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    int numFiles = dir.listDir(".");   //reads the contents of the datafolder
                                            //use listDir(".") to read data folder
    
    //printf("number of files found: %d\n", numFiles);
    
    //ofLogNotice sends a message to the output window
    //you can enter a string between the ()'s but you can also use 'streams' <<
    
    ofSetLogLevel(OF_LOG_ERROR);
    //ofLogVerbose
    //ofLogError
    //ofLogWarning
    //ofLogNotice("this is just text");
    //ofLogNotice() << "number of files: " << numFiles << " " << 5234.0;
    
    cout << "this is just text: " << numFiles << endl;
    
        
    for (int i=0; i<numFiles; i++) {
        
        //printf("file %d: %s\n", i, dir.getPath(i).c_str());
        
        cout << "file " << i << ": " << dir.getPath(i) << endl;

        ofVideoPlayer *mov = new ofVideoPlayer();
        mov->loadMovie(dir.getPath(i));
        mov->play();
        movies.push_back(mov);
         
    }
    

}

//--------------------------------------------------------------
void testApp::update(){
    for (int i=0; i<movies.size(); i++) {
        movies[i]->update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for (int i=0; i<movies.size(); i++) {
        movies[i]->draw(320*i,0,320,240);
        
        ofRect(320*i,250,movies[i]->getPosition()*320,5);
        
        string info = "frame: " + ofToString(movies[i]->getCurrentFrame());
        info += "   (numFrames: " + ofToString(movies[i]->getTotalNumFrames()) + ")"; 
        
        ofDrawBitmapString(info, 320*i+10, 280);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key>='0' && key<'7') {
        movies[key-'0']->play();
    }
}
