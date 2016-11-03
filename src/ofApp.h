#pragma once

#include "ofMain.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void gotMessage(ofMessage msg);

        // Members
        ofSoundPlayer player;
        bool isPlay;
        float playPosition;
        ofVec2f playButton;
        int radiusPlayButton = 50;
        ofVec2f previousButton;
        int widthPreviousButton  = 80;
        int heightPreviousButton = 50;
        const string macMusicDirPrefix   = "";
        const string linuxMusicDirPrefix = "";

        // Own functions
        // Play button
        void togglePlay(bool isPlay, bool isInternal);
        void displayPlayButton(bool isPlay, ofVec2f p, int radius);
        void playButtonClickEvent(bool isPlay, ofVec2f p);
        // Previous button
        void setPositionToHEAD(bool isInternal);
        void displayPreviousyButton(ofVec2f p);
        void previousButtonClickEvent(ofVec2f p1, ofVec2f p2);
};
