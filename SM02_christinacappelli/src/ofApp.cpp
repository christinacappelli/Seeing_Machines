#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    // ------------------- SOUND -------------------
    acid.load("acid.wav"); // load sound; .wav is best for looped sound
    acid.setVolume(0.5);
    acid.play();
    acid.setLoop(true);
    acid.setSpeed(0.4);
    acid.setPan(1.0);

    // ------------------- VIDEO -------------------
    grabber.setup(1280, 720);
    ofSetFrameRate(150); // slow frame rate
    ofSetWindowShape(1280, 720);   // set resolution to same as window size
    
    // ------------------- VIDEO PARAMETERS -------------------
    // define parameters
    //captureBackground.set("Capture BG", true); // name, value
    briThreshold.set("Bri Thresh", 120 , 0, 255);
    blurAmount.set("Blur Amount", 150, 0, 255); // max value, min, range, max range

    // ------------------- GUI PANEL -------------------
    // set up gui panel
    guiPanel.setup();
   // guiPanel.add(captureBackground);
    guiPanel.add(briThreshold);
    guiPanel.add(blurAmount);
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
        ofxCv::medianBlur(grabberColorImg, grabberNewImg, ofRandom(0,50)); // only copies blur image;
        
        if (captureBackground)
        {
            backgroundImg = grabberNewImg;
            //captureBackground = false;
        }
        
    //absolute difference image
    ofxCv::absdiff(backgroundImg, grabberNewImg, resultImg); // x-image, y-image, result image

    // thresholding turns it on of off; instead of looping through pixels, call threshold
        ofxCv::threshold(resultImg, briThreshold);
    }

    //Update the image to draw it
    resultImg.update();

     }


//--------------------------------------------------------------
void ofApp::draw()
{
    resultImg.draw(0, 0, ofGetWidth(), ofGetHeight()); // draw result image
    guiPanel.draw(); // draw gui on top
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
//    if (key == 'a')
//    {
//        cv::Vec3b convertColor(cv::Vec3b green,int code);
//        ofColor convertColor(ofColor color, int code);
//
//    } else if (key == 'b'){
//        ; // do something else
//    }
}



