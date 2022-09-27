#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup()
{
   
    grabber.setup (1280, 720);
    resultImg.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_GRAYSCALE);
    
    thresholdBrightness.set("BriThreshold", 127, 0, 255);
    ofSetWindowShape(grabber.getWidth(), grabber.getHeight());
    
    guiPanel.setup("BG"); // set up gui
    guiPanel.add(thresholdBrightness); // adding gui to threshold
}

//--------------------------------------------------------------
void ofApp::update()
{
    grabber.update();
    thresholdBrightness = ofMap(mouseX,0, ofGetWidth(), 0, 255);

    ofPixels& grabPix = grabber.getPixels();
    ofPixels& resultPix = resultImg.getPixels();
    
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
      }
    }
    resultImg.update();
  }

//--------------------------------------------------------------
void ofApp::draw()
{
    resultImg.draw(0,0, ofGetWidth(), ofGetHeight()); //draw your "duplicate" to see your changes
    guiPanel.draw(); // draw it
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
