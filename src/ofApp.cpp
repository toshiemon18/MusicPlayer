#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // General settings
    ofEnableSmoothing();
    ofSetCircleResolution(64);

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
    if (!isPlay)  { ofSetColor(255); }
    else          { ofSetColor(0);   }
    ofCircle(playButton, radiusOfPlayButton);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        togglePlay(isPlay, true);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    bool isInternal = ((playButton.x-x)*(playButton.x-x) +
                        (playButton.y-y)*(playButton.y-y) <= radiusOfPlayButton*radiusOfPlayButton);
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
