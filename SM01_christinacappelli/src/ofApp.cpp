#include "ofApp.h"

//Isolation: a live ⬜ cell with less than 2 live neighbors will die 😥.
//Overcrowding: a live ⬜ cell with 4 or more neighbors will die 😵.
//Reproduction: a dead ⬛ cell with exactly 3 live neighbors will live 🐣.


//--------------------------------------------------------------
void ofApp::setup()
{
    img.allocate(ofGetWidth(),ofGetHeight(), OF_IMAGE_GRAYSCALE); // calls memory of an image
    ofSetWindowShape(img.getWidth(),img.getHeight());
   
    imgPix = img.getPixels(); // gets pixels from a copy of the array
    //pixels.setFromPixels(newPixels,w,h,newType);
    
    
    //int liveN = countLiveNeighbors(x,y); // this line of code = a function
    
    // for all cols and rows
       for (int y = 0; y < img.getHeight(); y++)
       {
           for (int x = 0; x < img.getWidth(); x++)
           {
               if (ofRandomuf() < 0.2) // > half the time ...
               {
                   imgPix.setColor(x,y, ofColor(255)); // set color black; compare colors to colors
               }
               else
               {
                   imgPix.setColor(x,y, ofColor(0));// set color white
               }
           }
       }
       img.setFromPixels(imgPix); // update pixels
       newImgPix = imgPix; // new pixels = prior pixel image?
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
    img.draw(0, 0); // draw at top left
    
    // one array to read; read from the old
    // one array to write; write to the new
    // dont want to read yourself
    
    
    // for the edges
    //when it gets to the side reverse it; -1

     //for (each cell in image):
     for (int y = 0; y < img.getHeight(); y++)
     {
         for (int x = 0; x < img.getWidth(); x++)
         {
             
             int count = 0;
             ofColor color = img.getColor(x,y); // get color of pixels in image
             ofSetColor(color); // color = color of pixel
             ofDrawRectangle(x*gridSize, y*gridSize, gridSize, gridSize); // set size of grid
             
             //for all cells in grid
             for (int i = y - 1; i < y + 2; i++)
             {
                 for (int j = x - 1; j < x + 2; j++)
                 {
                     if (imgPix.getColor(i, j) == 255) // if cell is alive
                     {
                         count++; // count live pixels
                     }
                 }
             }
             
             // if (cell is live):
             if (color == 255)
             {
                 if (count < 3 || count > 4) // live neighbors < 2 OR > 3
                 {
                     newImgPix.setColor(x, y, ofColor(0)); // cell dies
                 }

             }
             else //if (cell is dead)
             {
                 if (count == 3) // has 3 live neighbors
                 {
                     newImgPix.setColor(x, y, ofColor(255)); // cell lives
                 }
             }
         }
     }
     imgPix = newImgPix; //update pixels using old pixels
     img.setFromPixels(newImgPix);
}

