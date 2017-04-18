#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Bullet");
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(0);

	camera.setPosition(ofVec3f(0, -7.f, -20.f));
	camera.lookAt(ofVec3f(0, 0, 0), ofVec3f(0, -1, 0));

	world.setup();
	world.enableGrabbing();
	world.enableDebugDraw();
	world.setCamera(&camera);

	ground.create(world.world, ofVec3f(0.0, 5.5, 0.0), 0.0, 15.0f, 1.0f, 15.0f);
	ground.setProperties(0.25, 0.95);
	ground.add();
}

//--------------------------------------------------------------
void ofApp::update(){

	if (ofGetFrameNum() % 5 == 0) {
		ofxBulletBox* box = new ofxBulletBox();
		box->create(world.world, ofVec3f(ofRandom(1), -10.0f, ofRandom(1)), 1.0, 0.5f, 0.5f, 0.5f);
		box->add();
		this->boxes.push_back(box);
	}

	world.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	glEnable(GL_DEPTH_TEST);
	camera.begin();

	ofSetLineWidth(1.f);
	ofSetColor(255, 0, 200);
	//world.drawDebug();

	ofSetColor(100, 100, 100);
	ground.draw();

	for (int i = 0; i < this->boxes.size(); i++) {
		ofColor body_color;
		body_color.setHsb(i % 255, 255, 255);
		ofSetColor(body_color);
		this->boxes[i]->draw();
	}

	camera.end();
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
