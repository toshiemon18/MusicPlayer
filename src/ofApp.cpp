#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // General settings
    ofEnableSmoothing();
    ofSetCircleResolution(64);
    ofBackground(255);

    player.loadSound("05\ ROOKiEZ\ is\ PUNK\'D\ -\ IN\ MY\ WORLD.mp3");
    // Initialize parameters
    isPlay = false;
    playPosition = 0;
    playButton.set(350, 150);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    displayPlayButton(isPlay, playButton, radiusPlayButton);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    // if pressed the space key, toggle playing music
    switch (key) {
        case ' ':
            togglePlay(isPlay, true);
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    float clickedPoint = (playButton.x-x)*(playButton.x-x) + (playButton.y-y)*(playButton.y-y);
    bool isInternal = (clickedPoint <= radiusPlayButton*radiusPlayButton);
    togglePlay(isPlay, isInternal);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::togglePlay(bool isPlayed, bool isInternal) {
    if (isPlay && isInternal) {
        isPlay = false;
        playPosition = player.getPosition();
        player.stop();
    } else if (!isPlay && isInternal) {
        isPlay = true;
        player.play();
        player.setPosition(playPosition);
    }
}

// -------------------------------------------------------------
void ofApp::displayPlayButton(bool isPlay, ofVec2f p, int radius) {
    if (!isPlay)  { ofSetColor(255); }
    else          { ofSetColor(0);   }
    ofCircle(p, radius);
}
