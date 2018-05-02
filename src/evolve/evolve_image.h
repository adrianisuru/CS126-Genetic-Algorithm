#ifndef EVOLVE_EVOLVE_IMAGE_H_
#define EVOLVE_EVOLVE_IMAGE_H_

#include "ofMain.h"
#include "dna.h"

#define DRAW_SQUARES false //whether to draw squares or circles1

class EvolveImage : public ofImage {

public:

    EvolveImage();
    EvolveImage(DNA dna);

    void set_dna(const DNA& dna);
    DNA get_dna() const;

    void update();

    unsigned long long get_fitness(const ofImage& original) const;


private:

    DNA dna_;

    ofFbo buffer_;

    void alloc_buffer();

};

#endif
