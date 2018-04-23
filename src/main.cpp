#include "model.h"
#include "evolve_app.h"


#include "ofMain.h"


#define DISPLAY_MODE OF_WINDOW

#include <iostream>
int main() {
    std::cout << "Hello, World" << std::endl;


    ofSetupOpenGL(640, 480, DISPLAY_MODE);

    ofEnableAlphaBlending();

	ofRunApp(new EvolveApp());

}
