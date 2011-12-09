#include "testApp.h"

vector<string> ofxLoadStrings(string filename) {
    ofBuffer settings = ofBufferFromFile(filename);
    vector<string> result;
    
    while (!settings.isLastLine()) {
        result.push_back(settings.getNextLine());
    }
    
    return result;
}

void ofxSaveStrings(string filename, vector<string> lines) {
    ofFile file;  
    if (file.open(filename, ofFile::WriteOnly, false)) {
        for (int i=0; i<lines.size(); i++) {
            file << lines[i] << endl;
        }
    }
}

//--------------------------------------------------------------
void testApp::setup(){
    
    vector<string> lines = ofxLoadStrings("settings.txt");

    cout << "num lines in the file: " << lines.size() << endl;
    cout << "line 0: " << lines[0] << endl;
    
    lines[0] = "this is the new value of line nr.0";
    
    ofxSaveStrings("settings.txt", lines);
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

}

