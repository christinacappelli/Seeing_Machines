
#pragma once

#include "ofMain.h"

#include "ofxCv.h"
#include "ofxGui.h"

#include "ofConstants.h"
#include "ofSoundBaseTypes.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    ofSoundPlayer acid; // pair sound variable with ofSoundPlayer

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
    
    ofxPanel guiPanel; // where all sliders will live
        
};

