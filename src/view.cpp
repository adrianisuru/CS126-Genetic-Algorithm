#include "view.h"

void EvolveView::setup() {
    myImage.load("source.png");
    myImage.update();
}

void EvolveView::draw() {
    myImage.draw(0, 0);
}

void EvolveView::update() {
    myImage.update();
    return;
}
