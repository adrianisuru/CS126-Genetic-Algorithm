#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "evolve_image.h"

class EvolveApp : public ofBaseApp {

public:

	void setup();

	void update();

	void draw();

private:

	void show_dialog();

	bool load_image(ofFileDialogResult fileResult);

    ofImage original_;

	ofImage best_;

	EvolveImage evolving_;

	ofxButton open_btn_;
	ofxButton start_btn_;


	ofxPanel gui_;

};
