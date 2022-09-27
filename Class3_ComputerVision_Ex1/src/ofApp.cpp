#include "ofApp.h"

//     -------------------- CLASS 03 NOTES ----------------------

// kinect does image segmentation ot identify objects in various colors
// video build into OF -- do not need add ons

// GPU (graphics) + CPU (comp brain) --> ofImage hits both of these --> makes graphic and updates its texture for the CPU

// when you are projection mapping you need to think about your location --> you need to be able to distingush the people from the background



//--------------------------------------------------------------
void ofApp::setup()
{
    //grabber.listDevices(); // this will list all cameras the code sees
    //grabber.setDeviceID(0); // you can add the ID in () of the camera you want from the above list
    
    grabber.setup (1280, 720); // resolution inside brackets; want resolution compatible with your camera
    resultImg.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_GRAYSCALE);
    
    thresholdBrightness = 127; // halfway
    ofSetWindowShape(grabber.getWidth(), grabber.getHeight()); // make the window shape the same size as the grabber image
}

//--------------------------------------------------------------
void ofApp::update()
{
    grabber.update(); // need to call update very frame so it can be constantly grabbing images
    
    thresholdBrightness = ofMap(mouseX,0, ofGetWidth(), 0, 255);
    
    // grab pixels from video --> process them --> draw them to screen 
    ofPixels grabPix = grabber.getPixels(); // taking all pixels
    ofPixels resultPix = resultImg.getPixels(); // copy pixels (giving you a duplicate to manipulate)
    
    // ------> ofPixels& resultPixels = grabber.getPixels(); // using &after says = give me the exact pixels and not a copy
    
    // play with pixels
    for (int y = 0; y < grabPix.getHeight(); y++)
    {
      for (int x = 0; x < grabPix.getWidth(); x++)
      {
          ofColor currCol = grabPix.getColor(x, y); // variable for pixel color
          
          if (currCol.getBrightness() < thresholdBrightness) // if color is less than threshold brightness
          {
              resultPix.setColor(x, y, ofColor(0));
          }
          else
          {
              resultPix.setColor(x, y, ofColor(255));
          }
         // resultPixels.setColor(x, y, currCol);
      }
    }
    resultImg.setFromPixels(resultPix); // want to update the "duplicate" so that you can update your changes
    // update pixels 
    //resultImg.update(); // syncs up CPU and GPU
  }

//--------------------------------------------------------------
void ofApp::draw()
{
    resultImg.draw(0,0, ofGetWidth(), ofGetHeight()); //draw your "duplicate" to see your changes
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
