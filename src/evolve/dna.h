#pragma once


class DNA {
public:
    class Gene {
        double cx_, cy_;        //center coordinate
        double rad_;            //radius
        double r_, g_, b_, a_;  //pixel in hlsa format
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

    DNA(unsigned size);

    const unsigned& size() const;               //get size

    Gene& operator[](unsigned i);               //access specific gene by index (non const)
    Gene& operator[](double p);                 //access random gene with random p (non const)

    const Gene& operator[](unsigned i) const;   //access specific gene by index
    const Gene& operator[](double p) const;     //access random gene with random p

private:
    const unsigned size_;
    Gene* genome_;

};
