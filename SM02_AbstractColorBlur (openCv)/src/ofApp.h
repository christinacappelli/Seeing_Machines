
#pragma once

#include "ofMain.h"

#include "ofxCv.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

public:
  void setup();
  void update();
  void draw();
    
    ofVideoGrabber grabber; // grab camera video feed
    ofImage backgroundImg; // background
    ofImage resultImg; // final image
    
    ofImage grabberColorImg; // variabel for color image
    ofImage grabberNewImg; //variable for new blur image
   
    //cv::Mat grabberColorMat;
    //cv::Mat grabberGrayMat;
    //cv::Mat backgroundMat;
    //cv::Mat resultMat;

    ofParameter<bool> captureBackground;
    ofParameter<int> briThreshold; // to deal with the noise
    ofParameter<int> blurAmount;
    //ofParameter<int> particleThreshold;

    ofxPanel guiPanel; // where all sliders will live
        
};

