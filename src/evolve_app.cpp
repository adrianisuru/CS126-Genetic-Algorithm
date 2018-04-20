#include "evolve_app.h"


void EvolveApp::setup() {
    myImage.update();
    show_dialog();
}

void EvolveApp::draw() {
    myImage.draw(0, 0);
}

void EvolveApp::update() {
    myImage.update();
    return;
}

void EvolveApp::show_dialog() {
    ofFileDialogResult openFileResult = ofSystemLoadDialog("Select a jpg or png");
    if (openFileResult.bSuccess) {
        myImage = load_image(openFileResult);
    } else {

    }
}

ofImage EvolveApp::load_image(ofFileDialogResult fileResult) {
    ofFile file(fileResult.getPath());
    ofImage ret;
    if (file.exists()) {
        string fileExtension = ofToUpper(file.getExtension());
        ret.load(fileResult.getPath());
    }

    return ret;

}
