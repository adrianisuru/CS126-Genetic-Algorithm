#include "dna.h"
#include <cstdlib>
#include <limits>
#include <cstdint>

DNA::Gene::Gene() : cx_(0), cy_(0), rad_(0), r_(0), g_(0), b_(0), a_(0) {

}

DNA::Gene::Gene(int cx, int cy, int rad,
    int r, int g, int b, int a)
: cx_(cx), cy_(cy), rad_(rad), r_(r), g_(g), b_(b), a_(a) {

}

const int& DNA::Gene::operator[](unsigned i) const {
    switch (i % 8) {
        case 0: return cx_;
        case 1: return cy_;
        case 2: return rad_;
        case 3: return r_;
        case 4: return g_;
        case 5: return b_;
        case 6: return a_;
        case 7: return n_;
        default: return n_;
    }
    return n_;
}


int& DNA::Gene::operator[](unsigned i) {
    switch (i % 8) {
        case 0: return cx_;
        case 1: return cy_;
        case 2: return rad_;
        case 3: return r_;
        case 4: return g_;
        case 5: return b_;
        case 6: return a_;
        case 7: return n_;
        default: return n_;
    }
    return n_;
}

int& DNA::Gene::operator[](double p) {
    return (*this)[(unsigned) (p * 8)];
}

const int& DNA::Gene::operator[](double p) const {
    return (*this)[(unsigned) (p * 8)];
}

const int& DNA::Gene::cx() const {
    return cx_;
}

const int& DNA::Gene::cy() const {
    return cy_;
}

const int& DNA::Gene::rad() const {
    return rad_;
}

const int& DNA::Gene::r() const {
    return r_;
}

const int& DNA::Gene::g() const {
    return g_;
}

const int& DNA::Gene::b() const {
    return b_;
}

const int& DNA::Gene::a() const {
    return a_;
}

void DNA::Gene::cx(int cx) {
    cx_ = cx;
}

void DNA::Gene::cy(int cy) {
    cy_ = cy;
}

void DNA::Gene::rad(int rad) {
    rad_ = rad;
}

void DNA::Gene::r(int r) {
    r_ = r;
}

void DNA::Gene::g(int g) {
    g_ = g;
}

void DNA::Gene::b(int b) {
    b_ = b;
}

void DNA::Gene::a(int a) {
    a_ = a;
}

void mutate(DNA& dna, unsigned gene, unsigned field, double amount) {
    if(dna.size_ == 0) return;
    gene = gene % dna.size_;
    field = field % 8;

    unsigned min = 0;
    unsigned max = (field == 0) ?  dna.img_width_  :
                   (field == 1) ?  dna.img_height_ :
                   (field == 2) ? (dna.img_width_ + dna.img_height_) / 4 :
                   (field == 3) ? 255 :
                   (field == 4) ? 255 :
                   (field == 5) ? 255 :
                   (field == 6) ? 127 :
                   (field == 7) ? std::numeric_limits<std::uint32_t>::max(): 0;
    if (max == 0) return;

    amount = amount - (int) amount; //if amount > 1 take just the decimal

    dna[gene][field] = (int)(dna[gene][field] + dna[gene][field] * amount);

    dna[gene][field] = (dna[gene][field] - min) % (max - min) + min;


}


DNA::DNA(unsigned size, unsigned img_width, unsigned img_height) : size_(size), img_width_(img_width),
    img_height_(img_height), genome_(new Gene[size_]) {

}

DNA::DNA(const DNA& source) {
    deep_copy(source);
}

DNA::DNA(DNA&& source) noexcept {
    shallow_copy(source);
}

DNA::~DNA() {
    clear();
}

DNA& DNA::operator=(const DNA& source) {
    clear();
    deep_copy(source);
    return *this;
}

DNA& DNA::operator=(DNA&& source) noexcept {
    shallow_copy(source);
    return *this;
}

void DNA::shallow_copy(const DNA& source) {
    size_ = source.size_;
    img_width_ = source.img_width_;
    img_height_ = source.img_height_;
    genome_ = source.genome_;
}

void DNA::deep_copy(const DNA& source) {
    size_ = source.size_;
    img_width_ = source.img_width_;
    img_height_ = source.img_height_;
    genome_ = new Gene[size_];
    for (unsigned i = 0; i < size_; i++) {
        genome_[i] = source.genome_[i];
    }
}

void DNA::clear() {
    delete[] genome_;
    genome_ = nullptr;
}

const unsigned& DNA::size() const {
    return size_;
}

const unsigned& DNA::img_width() const {
    return img_width_;
}

const unsigned& DNA::img_height() const {
    return img_height_;
}


DNA::Gene& DNA::operator[](unsigned i) {
    return genome_[i % size_];
}

DNA::Gene& DNA::operator[](double p) {
    return (*this)[(unsigned) (p * size_)];
}

const DNA::Gene& DNA::operator[](unsigned i) const {
    return genome_[i % size_];
}

const DNA::Gene& DNA::operator[](double p) const {
    return (*this)[(unsigned) (p * size_)];
}

void randomize(DNA& dna) {
    for (unsigned i = 0; i < dna.size_; i++) {
        dna[i].cx(rand() % dna.img_width_ );
        dna[i].cy(rand() % dna.img_height_);
        dna[i].rad(rand() % ((dna.img_width_ + dna.img_height_) / 4));
        dna[i].r(rand() % 255);
        dna[i].g(rand() % 255);
        dna[i].b(rand() % 255);
        dna[i].a(rand() % 127);
    }
}
