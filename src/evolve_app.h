#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "evolve_image.h"

class EvolveApp : public ofBaseApp {

public:

	EvolveApp();

	void setup();

	void update();

	void draw();

	void windowResized(int w, int h);

private:

	void show_dialog();

	bool load_image(ofFileDialogResult fileResult);

	void init_evolving(unsigned dna_length);

	void update_layout();

    ofImage original_;

	EvolveImage best_;

	EvolveImage evolving_;

	ofxButton open_btn_;
	ofxButton start_btn_;


	ofTrueTypeFont 	font_;

	ofxPanel gui_;

	unsigned window_width_;
	unsigned window_height_;
	unsigned img_disp_width_;
	unsigned img_disp_height_;

	unsigned mut_idx_;

};
