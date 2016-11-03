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
    previousButton.set(150, 125);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    displayPlayButton(isPlay, playButton, radiusPlayButton);
    displayPreviousyButton(previousButton);
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
    ofVec2f p; p.set(x, y);
    playButtonClickEvent(isPlay, p);
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

// -------------------------------------------------------------
void ofApp::playButtonClickEvent(bool isPlay, ofVec2f p) {
    float clickedPoint = (playButton.x-p.x)*(playButton.x-p.x) + (playButton.y-p.y)*(playButton.y-p.y);
    bool isInternal = (clickedPoint <= radiusPlayButton*radiusPlayButton);
    togglePlay(isPlay, isInternal);
}

// -------------------------------------------------------------
void ofApp::setPositionToHEAD(bool isInternal) {
    if (isInternal) {
        player.setPosition(0);
        player.stop();
        isPlay = false;
    }
}

// -------------------------------------------------------------
void ofApp::displayPreviousyButton(ofVec2f p) {
    ofSetColor(0);
    ofFill();
    ofRect(p, widthPreviousButton, heightPreviousButton);
    ofSetColor(255);
    float pi = 4.0 * atan(1.0);
    ofVec2f c; c.set(p.x + 30, p.y + 25);
    for (int i = 0; i < 2; i++) {
        ofVec2f o; o.set(c.x + 25*i, c.y);
        ofPushMatrix();
        ofTranslate(o);
        ofRotateZ(180);
        ofBeginShape();
            for (int i = 0; i < 3; i++) {
                ofVertex(20 * cos((360*i/3)*(pi/180.0)),
                        20 * sin((360*i/3)*(pi/180.0)));
            }
        ofEndShape();
        ofPopMatrix();
    }
}

// -------------------------------------------------------------
void ofApp::previousButtonClickEvent(ofVec2f p) {

}
