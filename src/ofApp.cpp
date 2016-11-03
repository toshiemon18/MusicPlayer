#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // General settings
    ofEnableSmoothing();
    ofSetCircleResolution(128);
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
    ofSetColor(0);
    ofFill();
    ofCircle(p, radius);
    ofSetColor(255);
    if (isPlay) {
        ofVec2f d;
        d.set(10, 20);
        ofRect(p.x - d.x, p.y - d.y, d.x * 0.75, d.y * 2);
        ofRect(p.x + d.x*0.5, p.y - d.y, d.x * 0.75, d.y * 2);
    }
    else {
        float pi = 4.0 * atan(1.0);
        ofBeginShape();
        for (int i = 0; i < 3; i++) {
            ofVertex(radius * 0.7 * cos((360*i/3)*(pi/180.0)) + p.x,
                     radius * 0.7 * sin((360*i/3)*(pi/180.0)) + p.y);
        }
        ofEndShape();
    }
}
