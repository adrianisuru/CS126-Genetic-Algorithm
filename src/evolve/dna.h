#pragma once


class DNA {
public:
    class Gene {
        double cx_, cy_; //center coordinate
        double rad_; // radius
        double r_, g_, b_, a_; //pixel in hlsa format
        double n_; //blank section for garbage mutations
    public:
        Gene();
        Gene(double cx, double cy, double rad,
            double r, double g, double b, double a);

        const double& operator[](unsigned i) const;
        const double& cx() const;
        const double& cy() const;
        const double& rad() const;
        const double& r() const;
        const double& g() const;
        const double& b() const;
        const double& a() const;

        double& operator[](unsigned i);
        void cx(double cx);
        void cy(double cy);
        void rad(double rad);
        void r(double r);
        void g(double g);
        void b(double b);
        void a(double a);
    };

    DNA(unsigned size);

    const unsigned& size() const;

    Gene& operator[](unsigned i);
    const Gene& operator[](unsigned i) const;

private:
    const unsigned size_;
    Gene* genome_;

};
