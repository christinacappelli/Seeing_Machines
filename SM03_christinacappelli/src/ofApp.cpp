// ofApp.cpp
#include "ofApp.h"


// ok so im struggling with this.. im just trying to get the color to change when in between the near and far threshold and then change to another color outside of it but its not working

void ofApp::setup()
{
  kinect.setRegistration(true);
  kinect.init();
  kinect.open();
    
  thresholdImg.allocate(kinect.getWidth(), kinect.getHeight(), OF_IMAGE_COLOR);

  nearThreshold.set("Near Threshold", 0.01f, 0.0f, 0.1f);
  farThreshold.set("Far Threshold", 0.02f, 0.0f, 0.1f);
    
  guiPanel.setup("Depth Threshold", "setting.json");
  guiPanel.add(nearThreshold);
  guiPanel.add(farThreshold);
}

void ofApp::update()
{
  kinect.update();
}

void ofApp::draw()
{
    if (kinect.isFrameNew())
    {
        //kinect.getDepthTexture().draw(0, 0);
        
        // Get the point distance using the SDK function.
        float distAtMouse = kinect.getDistanceAt(ofGetMouseX(), ofGetMouseY());
        ofDrawBitmapStringHighlight(ofToString(distAtMouse, 3), ofGetMouseX(), ofGetMouseY() - 10);
        
        // Get the point depth using the texture directly.
        ofShortPixels rawDepthPix = kinect.getRawDepthPixels();
               
        //ofDrawBitmapStringHighlight(ofToString(depthAtMouse), ofGetMouseX() + 10, ofGetMouseY() + 10);
        
        for (int y = 0; y < kinect.height; y ++){
            for (int x = 0; x < kinect.width; x++) {
            
            int depthAtMouse = rawDepthPix.getColor(x,y).g/255;
            
            if (nearThreshold < depthAtMouse && depthAtMouse > farThreshold) {
                thresholdImg.setColor(x, y, ofColor(255,0,0));
            } else {
                thresholdImg.setColor(x, y, ofColor(0, 0, 255));
                }
            }

            }
        }
        
    }
      
