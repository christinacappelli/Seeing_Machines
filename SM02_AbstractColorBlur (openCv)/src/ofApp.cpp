#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    // set up video
    grabber.setup(1280, 720);

    // define parameters
    captureBackground.set("Capture BG", true); // name, value
    briThreshold.set("Bri Thresh", 120 , 0, 255);
    blurAmount.set("Blur Amount", 120, 0, 255);

    // set up gui panel
    guiPanel.setup();
    guiPanel.add(captureBackground);
    guiPanel.add(briThreshold);
    guiPanel.add(blurAmount);
 
    // set resolution to same as window size
    ofSetWindowShape(1280, 720);
}


//--------------------------------------------------------------
void ofApp::update()
{
    // update video grabber
    grabber.update();
    
    // check if there is a new frame.. if so, do all this stuff;
    if (grabber.isFrameNew())
    {
        grabberColorImg.setFromPixels(grabber.getPixels());
       
        //ofxCv::copyGray(grabberColorImg, grabberNewImg); // only copies gray image;
        ofxCv::medianBlur(grabberColorImg, grabberNewImg, 40); // only copies blur image;
        
        if (captureBackground)
        {
            backgroundImg = grabberNewImg;
            captureBackground = false;
        }
        
        //absolute difference image
        ofxCv::absdiff(backgroundImg, grabberNewImg, resultImg); // x-image, y-image, result image

        // thresholding turns it on of off; instead of looping through pixels, call threshold
        ofxCv::threshold(resultImg, briThreshold);
    }

    //Update the image to draw it
    resultImg.update();
    

    
//
//       // Threshold the difference image.
//       ofxCv::threshold(resultMat, particleThreshold);
//
//       // Convert the result CV image back to OF space.
//       ofxCv::toOf(resultMat, resultImg);
//

     }


//--------------------------------------------------------------
void ofApp::draw()
{
    resultImg.draw(0, 0, ofGetWidth(), ofGetHeight()); // draw result image
    guiPanel.draw(); // draw gui on top
}



