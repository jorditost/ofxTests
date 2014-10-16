#include "ofApp.h"

using namespace cv;
using namespace ofxCv;

void ofApp::setup() {
	cam.initGrabber(640, 480);
	image.allocate(640, 480, OF_IMAGE_GRAYSCALE);
}

void ofApp::update() {
	cam.update();
	if(cam.isFrameNew()) {
        image.setFromPixels(cam.getPixelsRef());
        image.mirror(false, true);
		image.update();
	}
}

void ofApp::draw() {
	cam.draw(0, 0);
    image.draw(640, 0);
}
