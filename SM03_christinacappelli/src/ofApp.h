#pragma once

#include "ofMain.h"
#include "ofxKinect.h"
#include "ofxCvHaarFinder.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();
    void exit();

        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
  
    //KINECT / FACE
    ofxKinect kinect;
    ofxCvColorImage color;
    ofxCvGrayscaleImage gray;
    ofxCvHaarFinder haar;
  
    int angle;
    
    ofFbo canvasFbo;
    ofParameter<ofColor> tintColor;
    ofParameter<bool> clearFbo;
    ofxPanel guiPanel;
};
