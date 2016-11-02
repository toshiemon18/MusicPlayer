#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    player.loadSound("05\ ROOKiEZ\ is\ PUNK\'D\ -\ IN\ MY\ WORLD.mp3");

}

//--------------------------------------------------------------
void ofApp::update(){
    // if (!isPlayed) {
    //     player.play();
    //     isPlayed = true;
    // }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (isPlayed) { ofSetColor(255); }
    else          { ofSetColor(0);   }
    ofCircle(100, 100, 50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    bool isInternal = ((100-x)*(100-x) + (100-y)*(100-y) <= 50*50);
    if (isPlayed && isInternal) {
        player.stop();
        isPlayed = false;
    } else if (!isPlayed && isInternal) {
        player.play();
        isPlayed = true;
    }
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
