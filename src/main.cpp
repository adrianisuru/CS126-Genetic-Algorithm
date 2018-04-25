#include "evolve_app.h"


#include "ofMain.h"
#include <cstdlib>


#define DISPLAY_MODE OF_WINDOW

#include <iostream>
int main() {
    std::cout << "Hello, World" << std::endl;
    srand(time(NULL));

    ofSetupOpenGL(1600, 480, DISPLAY_MODE);

    ofEnableAlphaBlending();

	ofRunApp(new EvolveApp());

}
