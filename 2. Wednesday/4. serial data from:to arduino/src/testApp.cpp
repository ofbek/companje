#include "testApp.h"

string ofxGetSerialString(ofSerial &serial, char until) {
    static string str;
    stringstream ss;
    char ch;
    int ttl=1000;
    while ((ch=serial.readByte())>0 && ttl-->0 && ch!=until) {
        ss << ch;
    }
    str+=ss.str();
    if (ch==until) {
        string tmp=str;
        str="";
        return tmp;
    } else {
        return "";
    }
}

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    
    serial.listDevices();
    serial.setup(0, 9600);
}

//--------------------------------------------------------------
void testApp::update(){
    
//    while (serial.available()) {
//        char b = serial.readByte();
//        cout << b;
//        if (b=='\n') 
//    }
    
    string result = ofxGetSerialString(serial, '\n');
    
    if (result!="") {
        
        vector<string> params = ofSplitString(result,",");
        
        if (params.size()==4) {
                        
            int nr3 = ofToInt(params[3]);

            cout << nr3 << endl;

            if (nr3==10) {
                serial.writeByte('b');
            }
            

        }
        
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){

}

void testApp::mousePressed(int x, int y, int button) {
    serial.writeByte('b');
}

//
//only useful if there's a addon/class or function calling the ofNotifyEvent function
//void testApp::gotMessage(ofMessage msg) {
//    if (msg.message=="dataReceived") {
//        serial.writeByte('b');
//    }
//}
//


