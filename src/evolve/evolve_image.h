#pragma once

#include "ofMain.h"
#include "dna.h"

class EvolveImage : public ofImage {

public:

    EvolveImage();
    EvolveImage(DNA dna);

    void set_dna(const DNA& dna);
    DNA get_dna() const;

    void update();

    unsigned long get_fitness(ofImage& original) const;



private:

    DNA dna_;

    ofFbo buffer_;

    void alloc_buffer();

};
