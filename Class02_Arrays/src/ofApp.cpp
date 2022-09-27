#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    unsigned char H = 72;
//    unsigned char i = 'i';
//    cout << H << i <<  "C" << endl;
//
//    // count << to insert content
//    // endl = end and start next line
    
    // ------------------------------------------
    
    //bool values[40][30];  // 40 columns by 30 rows of values tht can be true of false
    for (int y = 0; y < 30; y++) // how many rows
    {
      for (int x = 0; x < 40; x++) //how many columns
      {
          if (ofRandomuf() < 0.5)
              values[x][y] = true;
          else{
              values[x][y] = false;
          }// defining these values
          cout << values[x][y];
      }
        cout << endl; // just want to print out the values
    }
}

//--------------------------------------------------------------
void ofApp::update(){
  
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
