#include "dna.h"

DNA::Gene::Gene() : cx_(0), cy_(0), rad_(0), r_(0), g_(0), b_(0), a_(0) {

}

DNA::Gene::Gene(double cx, double cy, double rad,
    double r, double g, double b, double a)
: cx_(cx), cy_(cy), rad_(rad), r_(r), g_(g), b_(b), a_(a) {

}

const double& DNA::Gene::operator[](unsigned i) const {
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


double& DNA::Gene::operator[](unsigned i) {
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

double& DNA::Gene::operator[](double p) {
    return (*this)[(unsigned) (p * 8)];
}

const double& DNA::Gene::operator[](double p) const {
    return (*this)[(unsigned) (p * 8)];
}

const double& DNA::Gene::cx() const {
    return cx_;
}

const double& DNA::Gene::cy() const {
    return cy_;
}

const double& DNA::Gene::rad() const {
    return rad_;
}

const double& DNA::Gene::r() const {
    return r_;
}

const double& DNA::Gene::g() const {
    return g_;
}

const double& DNA::Gene::b() const {
    return b_;
}

const double& DNA::Gene::a() const {
    return a_;
}

void DNA::Gene::cx(double cx) {
    cx_ = cx;
}

void DNA::Gene::cy(double cy) {
    cy_ = cy;
}

void DNA::Gene::rad(double rad) {
    rad_ = rad;
}

void DNA::Gene::r(double r) {
    r_ = r;
}

void DNA::Gene::g(double g) {
    g_ = g;
}

void DNA::Gene::b(double b) {
    b_ = b;
}

void DNA::Gene::a(double a) {
    a_ = a;
}


DNA::DNA(unsigned size) : size_(size), genome_(new Gene[size_]) {

}

const unsigned& DNA::size() const {
    return size_;
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
