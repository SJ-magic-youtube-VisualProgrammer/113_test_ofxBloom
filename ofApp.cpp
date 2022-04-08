/************************************************************
************************************************************/
#include "ofApp.h"

/************************************************************
************************************************************/

/******************************
******************************/
ofApp::ofApp(){
}

/******************************
******************************/
ofApp::~ofApp(){
}

/******************************
******************************/
void ofApp::exit(){

}

/******************************
******************************/
void ofApp::setup(){
	/********************
	********************/
	ofSetBackgroundAuto(true);
	
	ofSetWindowTitle("Bloom");
	ofSetVerticalSync(true);
	ofSetFrameRate(30);
	ofSetWindowShape(MAIN_WINDOW_W, MAIN_WINDOW_H);
	ofSetEscapeQuitsApp(false);
	
	/********************
	■What does ofDisableArbTex() do?
		https://forum.openframeworks.cc/t/what-does-ofdisablearbtex-do/26377
		
	■ofEnableArbTex()
		https://openframeworks.cc/documentation/gl/ofTexture/#show_ofEnableArbTex
		
	■[openFrameworks] ofDisableArbTex() の挙動
		https://qiita.com/ayumu_nagamatsu/items/fdb6f1389e5e4e783b61
		
	■[openFrameworks]ofDisableArbTexの挙動，samper2Dとsampler2DRectの違い
		https://qiita.com/keito_takaishi/items/7ff86bd1e15b4185d9ab
	********************/
	//Src fbo's texcoord has to be normalized(0 - 1)
	ofDisableArbTex();
	fbo.allocate(FBO_W, FBO_H);
	ofEnableArbTex();
	
	bloom.setup(fbo.getWidth(), fbo.getHeight(), fbo);
	
	/********************
	********************/
	setup_GUI();
}

/******************************
******************************/
void ofApp::setup_GUI(){
	gui.setup();
	
	Group_DrawContents.setup("DrawContents");
		Group_DrawContents.add(PutRadius.setup("PutRadius", 200, 100, 500));
		Group_DrawContents.add(CircleRadius.setup("CircleRadius", 20, 10, 100));
		Group_DrawContents.add(draw_saturation.setup("draw_S", 255, 0, 255));
		Group_DrawContents.add(draw_value.setup("draw_V", 255, 0, 255));
	gui.add(&Group_DrawContents);
	
	Group_Bloom.setup("Bloom");
		Group_Bloom.add(scale.setup("Scale", 2.3f, 0.1f, 16.0f));
		Group_Bloom.add(brightness.setup("Brightness", 5.0f, 0.0f, 30.0f));
		Group_Bloom.add(thresh.setup("Threshold", 0.0f, 0.0f, 1.0f));
		Group_Bloom.add(b_EnableBloom.setup("b_EnableBloom", true));
	gui.add(&Group_Bloom);
	
	gui.minimizeAll();
}

/******************************
******************************/
void ofApp::update(){

	time = float(ofGetElapsedTimeMillis()) / 1000.0;
	
	fbo.begin();
		ofClear(0);
		
		ofColor color;
		color.setBrightness(draw_value);
		color.setSaturation(draw_saturation);
		
		for (float hue = 0; hue < 360; hue += 30) {
			color.setHueAngle(hue);
			ofSetColor(color);
			
			ofDrawCircle(	fbo.getWidth()/2  + PutRadius * cos(DEG_TO_RAD * hue),
							fbo.getHeight()/2 + PutRadius * sin(DEG_TO_RAD * hue),
							CircleRadius);
		}
	fbo.end();
	
	if(b_EnableBloom){
		bloom.setBrightness(brightness);
		bloom.setScale(scale);
		bloom.setThreshold(thresh);
		bloom.process();
	}
}

/******************************
******************************/
void ofApp::draw(){
	/********************
	********************/
	ofBackground(0, 0, 0, 255);
	
	/********************
	********************/
	ofSetColor(255);
	if(b_EnableBloom)	bloom.getResultFbo().draw(0, 0, ofGetWidth(), ofGetHeight());
	else				fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
	
	/********************
	********************/
	gui.draw();
}

/******************************
******************************/
void ofApp::keyPressed(int key){

}

/******************************
******************************/
void ofApp::keyReleased(int key){

}

/******************************
******************************/
void ofApp::mouseMoved(int x, int y ){

}

/******************************
******************************/
void ofApp::mouseDragged(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mousePressed(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseReleased(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseEntered(int x, int y){

}

/******************************
******************************/
void ofApp::mouseExited(int x, int y){

}

/******************************
******************************/
void ofApp::windowResized(int w, int h){

}

/******************************
******************************/
void ofApp::gotMessage(ofMessage msg){

}

/******************************
******************************/
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
