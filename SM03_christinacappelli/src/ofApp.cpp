#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //KINECT
    kinect.init();
    kinect.open();
  
    // FACE
    color.allocate(kinect.getWidth(), kinect.getHeight());
    gray.allocate(kinect.getWidth(), kinect.getHeight());
  
    haar.setup("haarcascade_frontalface_default.xml");
    haar.setScaleHaar(2);
    
    //FBO
    // Allocate the frame buffer.
    ofFboSettings settings;
    settings.width = 1024;
    settings.height = 768;
    canvasFbo.allocate(settings);

    // Setup the parameters.
    tintColor.set("Tint Color", ofColor(255, 182, 193));
    clearFbo.set("Clear Background", false);

}

//--------------------------------------------------------------
void ofApp::update(){
  kinect.update();
  
  if (kinect.isFrameNew()){
    color.setFromPixels(kinect.getPixels());
    gray = color;
    haar.findHaarObjects(gray);
      
    canvasFbo.begin();
  }
     {
       if (clearFbo)
       {
           ofBackground(0);
           clearFbo = false;
       }
     }
     canvasFbo.end();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //SCALE
    float scaleRatio = ofGetWidth() / kinect.getWidth();
    float drawX = 0;
    float drawHeight = kinect.getHeight() * scaleRatio;
    float drawY = (ofGetHeight() - drawHeight) / 1.0f;

    ofTranslate(drawX, drawY);
    ofScale(scaleRatio);
    
    //FACE FINDER
    color.draw(0, 0);
    for (int i = 0; i < haar.blobs.size(); i++) {
        ofSetColor(255);
        ofNoFill();
        ofDrawRectangle(haar.blobs[i].boundingRect);
    
        ofSetColor(tintColor);
        canvasFbo.draw(0, 0, kinect.getWidth(),kinect.getHeight());
        guiPanel.draw();
  }
}

//--------------------------------------------------------------
void ofApp::exit(){
  kinect.setCameraTiltAngle(0);
  kinect.close();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  switch (key) {
    case OF_KEY_UP:
      angle++;
      if (angle > 30) {
        angle = 30;
      }
      kinect.setCameraTiltAngle(angle);
      break;
    case OF_KEY_DOWN:
      angle--;
      if (angle < -30) {
        angle = -30;
      }
      kinect.setCameraTiltAngle(angle);
      break;
    case '0':
      angle = 0;
      if (angle == 0) {
        angle = 0;
      }
      kinect.setCameraTiltAngle(angle);
      break;
      
    default:
      break;
  }
    if (key == 'a')
    {
      clearFbo = true;
    }
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

