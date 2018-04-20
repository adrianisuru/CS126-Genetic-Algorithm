#pragma once

#include "ofMain.h"

class EvolveApp : public ofBaseApp {

public:

	void setup();

	void update();

	void draw();

private:

	void show_dialog();

	ofImage load_image(ofFileDialogResult fileResult);

    ofImage myImage;

};
