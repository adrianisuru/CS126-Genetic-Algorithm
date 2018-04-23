#include "evolve_app.h"
#include "ofMain.h"
#include "ofxGui.h"
#include "evolve_image.h"


void EvolveApp::setup() {
    ofSetVerticalSync(true);


    //Derrived from OF/examples/gui/

	// we add this listener before setting up so the initial circle resolution is correct
//	circleResolution.addListener(this, &EvolveApp::circleResolutionChanged);
//	ringButton.addListener(this, &EvolveApp::ringButtonPressed);

	gui_.setup();

    open_btn_.addListener(this, &EvolveApp::show_dialog);

	gui_.add(open_btn_.setup("open"));
    gui_.add(start_btn_.setup("start"));



}

void EvolveApp::draw() {
    original_.draw(0, 0);
    evolving_.draw(200, 200);
    gui_.draw();
}

void EvolveApp::update() {
    evolving_.update();
    original_.update();
}

void EvolveApp::show_dialog() {
    ofFileDialogResult openFileResult = ofSystemLoadDialog("Select a png.");
    if (!openFileResult.bSuccess) {

    } else if (!load_image(openFileResult)) {
        //error loading image
    }
}

bool EvolveApp::load_image(ofFileDialogResult fileResult) {
    ofFile file(fileResult.getPath());

    if (file.exists()) {
        string fileExtension = ofToUpper(file.getExtension());
        if (fileExtension == "PNG") {
            original_.load(fileResult.getPath());
            return true;
        }
    }

    return false;
}
