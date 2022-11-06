// ofApp.h
#pragma once

#include "ofMain.h"

#include "ofxCv.h"
#include "ofxGui.h"
#include "ofxKinect.h"

class ofApp : public ofBaseApp
{
public:
  void setup();
  void update();
  void draw();

  ofxKinect kinect;

  ofImage thresholdImg;

  ofParameter<float> nearThreshold;
  ofParameter<float> farThreshold;

  ofxPanel guiPanel;
};

