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

        // Own functions
        void togglePlay(bool isPlay, bool isInternal);
};
