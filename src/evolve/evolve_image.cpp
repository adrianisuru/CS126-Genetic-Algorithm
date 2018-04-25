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
    ofClear(225, 255, 255, 0);
    for (unsigned i = 0; i < dna_.size(); i++) {
        DNA::Gene& gene = dna_[i];
        ofSetColor(ofColor(gene.r(), gene.g(), gene.b(), gene.a()));
        ofDrawCircle(gene.cx(), gene.cy(), gene.rad());
        //ofDrawRectangle (gene.cx() - gene.rad(), gene.cy() - gene.rad(), gene.rad(), gene.rad());
    }
    buffer_.end();
    ofPixels pixels;
    buffer_.readToPixels(pixels);
    setFromPixels(pixels);
}

unsigned long long EvolveImage::get_fitness(const ofImage& original) const {
    unsigned long long fitness = 0;
    const ofPixels& orig_pix = original.getPixels();
    ofPixels this_pix;
    buffer_.readToPixels(this_pix);
    this_pix.setImageType(OF_IMAGE_COLOR);

    ofPixels::const_iterator this_it = this_pix.begin();
    ofPixels::const_iterator orig_it = orig_pix.begin();

    while (this_it != this_pix.end() && orig_it != orig_pix.end()) {
        ofColor this_color = *this_it;
        ofColor orig_color = *orig_it;
        fitness += std::abs(this_color.r - orig_color.r);
        fitness += std::abs(this_color.g - orig_color.g);
        fitness += std::abs(this_color.b - orig_color.b);
        //fitness += std::abs(this_color.a - orig_color.a);
        ++this_it;
        ++orig_it;
    }

    return fitness;
}
