#include "evolve_app.h"


void EvolveApp::setup() {
    myImage.load("source.png");
    myImage.update();
}

void EvolveApp::draw() {
    myImage.draw(0, 0);
}

void EvolveApp::update() {
    myImage.update();
    return;
}
