#include "evolve_image.h"
#include "ofMain.h"

void EvolveImage::update() {
    ofSetColor(ofColor(0, 0, ofRandom( 128, 255 )));
    ofDrawCircle(150,150,100);
}
