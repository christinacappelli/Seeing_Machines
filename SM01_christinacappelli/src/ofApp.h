#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
  
    int gridSize = 5;
    ofImage img;
    ofPixels imgPix;
    ofPixels newImgPix;

};
