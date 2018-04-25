#pragma once


class DNA {
public:
    class Gene {
        double cx_, cy_;        //center coordinate
        double rad_;            //radius
        double r_, g_, b_, a_;  //pixel in rgba format
        double n_;              //blank section for garbage mutations
    public:
        Gene();
        Gene(double cx, double cy, double rad,
            double r, double g, double b, double a);

        const double& operator[](unsigned i) const; //access specific field by index
        const double& operator[](double p) const;   //access random field with random p

        double& operator[](unsigned i);             //access specific field by index (non const)
        double& operator[](double p);               //access random field with random p (non const)

        //getters
        const double& cx() const;
        const double& cy() const;
        const double& rad() const;
        const double& r() const;
        const double& g() const;
        const double& b() const;
        const double& a() const;

        //setters
        void cx(double cx);
        void cy(double cy);
        void rad(double rad);
        void r(double r);
        void g(double g);
        void b(double b);
        void a(double a);




    };

    DNA(unsigned size, unsigned img_width, unsigned img_height);

    const unsigned& size() const;               //get size
    const unsigned& img_width() const;          //get image width
    const unsigned& img_height() const;         //get image height

    Gene& operator[](unsigned i);               //access specific gene by index (non const)
    Gene& operator[](double p);                 //access random gene with random p (non const)

    const Gene& operator[](unsigned i) const;   //access specific gene by index
    const Gene& operator[](double p)   const;   //access random gene with random p

    friend void randomize(DNA& dna);            //fills this DNA with random values

private:
    unsigned size_;
    unsigned img_width_;
    unsigned img_height_;
    Gene* genome_;

};
