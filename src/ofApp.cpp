#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    origImg.load("test.jpg");
    width = origImg.getWidth();
    height = origImg.getHeight();
    finalImg.allocate(width, height, OF_IMAGE_COLOR);
    fbo.allocate(width, height, GL_RGB);
}

//--------------------------------------------------------------
void ofApp::update() {
    fbo.begin();
    float spread = 1.1;
    origImg.draw(ofRandom(-spread, spread), ofRandom(-spread, spread));
    fbo.end();
    
    ofPixels pixels;
    fbo.readToPixels(pixels);
    
    unsigned char pixelsRaw[pixels.size()];
    std::copy(pixels.begin(), pixels.end(), pixelsRaw);

    int n = sizeof(pixelsRaw) / sizeof(pixelsRaw[0]);

    vector<unsigned char> pixelsRawVec(pixelsRaw, pixelsRaw+n);
    cout << "orig size: " << sizeof(pixelsRaw) << endl;

    vector<unsigned char> zippedFile = ofxZip::compress(pixelsRawVec);
    cout << "compressed size: " << zippedFile.size() << endl;

    vector<unsigned char> unZippedFile = ofxZip::uncompress(zippedFile);
    cout << "restored size: " << unZippedFile.size() << endl;

    unsigned char newPixelsRaw[unZippedFile.size()];
    std::copy(unZippedFile.begin(), unZippedFile.end(), newPixelsRaw);

    finalImg.setFromPixels(newPixelsRaw, width, height, OF_IMAGE_COLOR);
    ofSaveImage(finalImg, buffer, OF_IMAGE_FORMAT_JPEG, OF_IMAGE_QUALITY_LOW);
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
