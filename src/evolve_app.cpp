#include "evolve_app.h"
#include "ofMain.h"
#include "ofxGui.h"
#include "evolve_image.h"

#include <iostream>
#include <random>

#define PADDING 15
#define DNA_SIZE 100

EvolveApp::EvolveApp() : running_(false), generation_count_(0) {

    //sets range [-1, 1]
    range_ = std::uniform_real_distribution<double>(-1.0, 1.0);

    window_width_ = ofGetWidth();
    window_height_ = ofGetHeight();
    img_disp_width_ = (window_width_ - (4 * PADDING)) / 3;
    img_disp_height_ = (window_height_ - (3 * PADDING)) - font_.getSize();


    ofBackground(50, 50, 50);
}


void EvolveApp::init_evolving(unsigned dna_length) {
    generation_count_ = 0;
    DNA dna(dna_length, original_.getWidth(), original_.getHeight());
    randomize(dna);
    evolving_.set_dna(dna);
    best_ = evolving_;
}

void EvolveApp::genetic() {
    DNA dna = best_.get_dna();

    if (rand() % 2) {
        mutate(dna, mut_idx_, rand(), rand_double()); //mutates some random section by up to amount
    } else {
        swap(dna, mut_idx_, (unsigned)(mut_idx_ + ((double) mut_idx_ / evolving_.get_dna().size()) * rand_double()));
    }
    mut_idx_++;

    evolving_.set_dna(dna);
    evolving_.update();

    unsigned long long best_fit = best_.get_fitness(original_);
    unsigned long long evol_fit = evolving_.get_fitness(original_);
    //std::cout << "best: " << best_fit << " evol: " << evol_fit << std::endl;

    //higher fitness is worse (i know this is weird)
    if (best_fit >= evol_fit) {
        best_ = evolving_;
    }

    generation_count_++;

}

void EvolveApp::setup(){

    ofSetVerticalSync(true);


	gui_.setup();

    open_btn_.addListener(this, &EvolveApp::show_dialog);
    start_btn_.addListener(this, &EvolveApp::start);
    save_btn_.addListener(this, &EvolveApp::save);

	gui_.add(open_btn_.setup("open"));
    gui_.add(start_btn_.setup("start"));
    gui_.add(save_btn_.setup("save"));
    gui_.add(generations_.set("Generations: ", ""));

    font_.load("vag.ttf", 16);

}

void EvolveApp::start() {
    running_ = true;
}

void EvolveApp::draw() {
    ofSetupScreen();

    original_.draw(PADDING, PADDING, img_disp_width_, img_disp_height_);
    best_.draw(2 * PADDING + img_disp_width_, PADDING, img_disp_width_, img_disp_height_);
    evolving_.draw(3 * PADDING + 2 * img_disp_width_, PADDING, img_disp_width_, img_disp_height_);

    font_.drawString("Original", PADDING, 3 * PADDING + img_disp_height_);
    font_.drawString("Best", 2 * PADDING + img_disp_width_, 3 * PADDING + img_disp_height_);
    font_.drawString("Evolving", 3 * PADDING + 2 * img_disp_width_, 3 * PADDING + img_disp_height_);


    gui_.draw();
}

double EvolveApp::rand_double() {
    return range_(random_);
}

void EvolveApp::update() {
    if (!running_) return;
    genetic();

    //evolving_.update(); //its in genetic() so we dont have to update twice
    original_.update();
    best_.update();

    generations_ = ofToString(generation_count_);
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
            original_.setImageType(OF_IMAGE_COLOR);
            init_evolving(DNA_SIZE);
            return true;
        }
    }

    return false;
}

void EvolveApp::save() {
    running_ = false;
    ofFileDialogResult saveFileResult = ofSystemSaveDialog("Save file as png", "Save a file");
    if (saveFileResult.bSuccess) {
        ofFile file(saveFileResult.getPath());
        best_.save(file);
    }
}
