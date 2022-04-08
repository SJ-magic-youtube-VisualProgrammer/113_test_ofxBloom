/************************************************************
■P-A-N/ofxBloom
	https://github.com/P-A-N/ofxBloom
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include "ofMain.h"
#include "ofxBloom.h"
#include "ofxGui.h"

/************************************************************
************************************************************/
class ofApp : public ofBaseApp{
private:
	/****************************************
	****************************************/
	enum{
		MAIN_WINDOW_W = 1920,
		MAIN_WINDOW_H = 1080,
		
		FBO_W = 1280,
		FBO_H = 720,
	};
	
	/****************************************
	****************************************/
	ofxPanel gui;
		ofxGuiGroup Group_DrawContents;
			ofxFloatSlider PutRadius;
			ofxFloatSlider CircleRadius;
			ofxFloatSlider draw_saturation;
			ofxFloatSlider draw_value;
		ofxGuiGroup Group_Bloom;
			ofxFloatSlider scale;
			ofxFloatSlider thresh;
			ofxFloatSlider brightness;
			ofxToggle b_EnableBloom;
	
	float time;
	ofxBloom bloom;
	ofFbo fbo;
	
	/****************************************
	****************************************/
	void setup_GUI();
	
public:
	/****************************************
	****************************************/
	ofApp();
	~ofApp();
	void exit();

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
	
};
