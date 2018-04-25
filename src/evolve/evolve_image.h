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

    unsigned long long get_fitness(const ofImage& original) const;



private:

    DNA dna_;

    ofFbo buffer_;

    void alloc_buffer();

};
