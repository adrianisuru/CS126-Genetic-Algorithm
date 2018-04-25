#include "evolve_image.h"
#include "dna.h"
#include "ofMain.h"


EvolveImage::EvolveImage() : dna_(0, 0, 0) {

}

EvolveImage::EvolveImage(DNA dna) : dna_(dna) {
    alloc_buffer();
}

void EvolveImage::set_dna(const DNA& dna) {
    dna_ = dna;
    alloc_buffer();
}

DNA EvolveImage::get_dna() const {
    return dna_;
}

void EvolveImage::alloc_buffer() {
    buffer_.allocate(dna_.img_width(), dna_.img_height(), GL_RGBA);
}


void EvolveImage::update() {
    buffer_.begin();
    for (unsigned i = 0; i < dna_.size(); i++) {
        DNA::Gene& gene = dna_[i];
        ofSetColor(ofColor(gene.r(), gene.g(), gene.b(), gene.a()));
        ofDrawCircle(gene.cx(), gene.cy(), gene.rad());
    }
    buffer_.end();
    ofPixels pixels;
    buffer_.readToPixels(pixels);
    setFromPixels(pixels);
}

unsigned long EvolveImage::get_fitness(ofImage& original) const {
    return rand();
}
