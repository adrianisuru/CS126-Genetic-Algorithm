#ifndef EVOLVE_APP_H_
#define EVOLVE_APP_H_

#include "ofMain.h"
#include "ofxGui.h"
#include "evolve_image.h"
#include <random>
#include <string>

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

	void genetic();

	double rand_double();

	void start();

	void save();

    ofImage original_;

	EvolveImage best_;

	EvolveImage evolving_;

	ofxButton open_btn_;
	ofxButton start_btn_;
	ofxButton save_btn_;

	ofParameter<std::string> generations_;

	ofTrueTypeFont font_;

	ofxPanel gui_;

	unsigned window_width_;
	unsigned window_height_;
	unsigned img_disp_width_;
	unsigned img_disp_height_;

	unsigned generation_count_;

	unsigned mut_idx_;

	//used for getting random double in range [-1, 1]
	std::uniform_real_distribution<double> range_;
   	std::default_random_engine random_;

	bool running_;

};

#endif
