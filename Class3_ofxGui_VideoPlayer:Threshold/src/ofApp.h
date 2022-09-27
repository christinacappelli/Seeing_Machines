#pragma once

#include "ofMain.h"
#include "ofxGui.h" // use the gui add on --> need to add this!

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

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
    
        ofParameter<int> thresholdBrightness;
        // threshold = how bright image is is going to be the threshold
        //ofParameter<type>
            // is a class that can work with <floats> <int> <string>
            // you need to tell it which type is working with
            // acts as a wrapper
            // int in gui and an int for threshold are different BUT ofParameter wraps them to work together
            // still have to add parameters to gui in the c+ ofApp
            // Superpowers: 1. give it a name, min + max, event notification --> when theres a change it notices it and applies it
    
    
        ofVideoGrabber grabber; // variable for main image
        ofImage backgroundImg; // background image
        ofImage resultImg; // image of your "duplicate" -- the one you are going to be manipulating
        ofxPanel guiPanel; // #include at top
		
};
