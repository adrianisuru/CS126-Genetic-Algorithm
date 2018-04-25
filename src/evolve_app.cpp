#include "evolve_app.h"
#include "ofMain.h"
#include "ofxGui.h"
#include "evolve_image.h"

#define PADDING 15
#define DNA_SIZE 50


EvolveApp::EvolveApp() {


    font_.load("vag.ttf", 16);

    window_width_ = ofGetWidth();
    window_height_ = ofGetHeight();
    img_disp_width_ = (window_width_ - (4 * PADDING)) / 3;
    img_disp_height_ = (window_height_ - (3 * PADDING)) - font_.getSize();


    ofBackground(50,50,50);
}


void EvolveApp::init_evolving(unsigned dna_length) {
    DNA dna(dna_length, original_.getWidth(), original_.getHeight());
    randomize(dna);
    evolving_.set_dna(dna);
    best_ = evolving_;
}

void EvolveApp::update_layout() {

}

void EvolveApp::setup(){

    ofSetVerticalSync(true);


	gui_.setup();

    open_btn_.addListener(this, &EvolveApp::show_dialog);

	gui_.add(open_btn_.setup("open"));
    gui_.add(start_btn_.setup("start"));

}

void EvolveApp::draw() {
    ofSetupScreen();

	//ofSetHexColor(0x999999);

	// lets show our window pos in pixels
	// macs actually start the Y pos from 40
//	font_.drawString("window size ("+ofToString(window_width_)+", "+ofToString( window_height_)+")", 10, 25);




    original_.draw(PADDING, PADDING, img_disp_width_, img_disp_height_);
    best_.draw(2 * PADDING + img_disp_width_, PADDING, img_disp_width_, img_disp_height_);
    evolving_.draw(3 * PADDING + 2 * img_disp_width_, PADDING, img_disp_width_, img_disp_height_);

    font_.drawString("Original", PADDING, 3 * PADDING + img_disp_height_);
    font_.drawString("Best", 2 * PADDING + img_disp_width_, 3 * PADDING + img_disp_height_);
    font_.drawString("Evolving", 3 * PADDING + 2 * img_disp_width_, 3 * PADDING + img_disp_height_);


    gui_.draw();
}

void EvolveApp::update() {

    DNA dna = best_.get_dna();

    //dna[rand()][rand()]

    if (best_.get_fitness(original_) <= evolving_.get_fitness(original_)) {
        best_ = evolving_;
    }

    evolving_.update();
    original_.update();
    best_.update();
}

void EvolveApp::windowResized(int w, int h){
    window_width_ = w;
    window_height_ = h;
    img_disp_width_ = (window_width_ - (4 * PADDING)) / 3;
    img_disp_height_ = (window_height_ - (3 * PADDING)) - font_.getSize();
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
            init_evolving(DNA_SIZE);
            return true;
        }
    }

    return false;
}
