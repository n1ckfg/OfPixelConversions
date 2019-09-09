#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    origImg.load("test.jpg");
    fbo.allocate(origImg.getWidth(), origImg.getHeight(), GL_RGB);
}

//--------------------------------------------------------------
void ofApp::update() {
    fbo.begin();
    float spread = 1.1;
    origImg.draw(ofRandom(-spread, spread), ofRandom(-spread, spread));
    fbo.end();
    
    ofPixels pixels;
    fbo.readToPixels(pixels);
    ofSaveImage(pixels, buffer, OF_IMAGE_FORMAT_JPEG, OF_IMAGE_QUALITY_LOW);
    origImg.load(buffer);
}

//--------------------------------------------------------------
void ofApp::draw() {
    fbo.draw(0,0);
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
