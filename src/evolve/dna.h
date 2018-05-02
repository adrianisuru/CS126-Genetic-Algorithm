#ifndef EVOLVE_DNA_H_
#define EVOLVE_DNA_H_

class DNA {
public:
    class Gene {
        int cx_, cy_;        //center coordinate
        int rad_;            //radius
        int r_, g_, b_, a_;  //pixel in rgba format
        int n_;              //blank section for garbage mutations
    public:
        Gene();
        Gene(int cx, int cy, int rad,
            int r, int g, int b, int a);

        const int& operator[](unsigned i) const; //access specific field by index
        const int& operator[](double p) const;   //access random field with random p

        int& operator[](unsigned i);             //access specific field by index (non const)
        int& operator[](double p);               //access random field with random p (non const)

        //getters
        const int& cx() const;
        const int& cy() const;
        const int& rad() const;
        const int& r() const;
        const int& g() const;
        const int& b() const;
        const int& a() const;

        //setters
        void cx(int cx);
        void cy(int cy);
        void rad(int rad);
        void r(int r);
        void g(int g);
        void b(int b);
        void a(int a);





    };

    DNA(unsigned size, unsigned img_width, unsigned img_height);

    // Rule of five
    DNA(const DNA& source);                     // Copy constructor
    DNA(DNA&& source) noexcept;                 // Move constructor
    ~DNA();                                     // Destructor
    DNA& operator=(const DNA& source);          // Copy assignment operator
    DNA& operator=(DNA&& source) noexcept;      // Move assignment operator

    const unsigned& size() const;               //get size
    const unsigned& img_width() const;          //get image width
    const unsigned& img_height() const;         //get image height

    Gene& operator[](unsigned i);               //access specific gene by index (non const)
    Gene& operator[](double p);                 //access random gene with random p (non const)

    const Gene& operator[](unsigned i) const;   //access specific gene by index
    const Gene& operator[](double p)   const;   //access random gene with random p

    //mutates the given gene in the indexed field by the specified amount (0 - 1]
    friend void mutate(DNA& dna, unsigned gene, unsigned field, double amount);
    friend void swap(DNA& dna, unsigned gene1, unsigned gene2);
    friend void randomize(DNA& dna);            //fills this DNA with random values

private:
    void shallow_copy(const DNA& source);
    void deep_copy(const DNA& source);
    void clear();

    unsigned size_;
    unsigned img_width_;
    unsigned img_height_;
    Gene* genome_;

};

#endif
