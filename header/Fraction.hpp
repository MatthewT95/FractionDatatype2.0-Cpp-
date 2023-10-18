class Fraction
{
private:
    unsigned int numerator;
    unsigned int denominator;
    char sign; /* Value of 1 means fraction has positive value.
    Value of -1 means fraction has a negative value.
    0 means fraction has a value of 0.*/

    static unsigned int GCD(unsigned int a, unsigned int b); // returns Greatest Common Denominator of two integers
    static unsigned int LCM(unsigned int a, unsigned int b); // returns Least Common Multiple of two integers

public:
    // Constructors
    Fraction();
    Fraction(int numerator, unsigned int denominator);
    Fraction(const Fraction &);
    Fraction(const int);
    Fraction(const double);

    // Getters
    unsigned int getNumerator() const;   // Returns the fraction numerator
    unsigned int getDenominator() const; // Returns the fraction denominator
    char getSign() const;                // Returns a number representing the sign of the fraction
    bool isPositive() const;             // Returns true if fraction is greater then zero
    bool isNegative() const;             // Returns true if fraction is less then zero
    bool isZero() const;                 // Returns true if fraction is zero
    bool isImproper() const;             // Returns true if fraction is an improper fraction

    // Setters
    void setNumerator(unsigned int);   // Sets the fraction's numerator
    void setDenominator(unsigned int); // Sets the fraction's denominator
    void setSign(char);                // Sets the fraction's sign
    void scale(unsigned int);          // Scales the numerator and denominator by factor
    void simplifyFraction();           // Simplifies the fraction

    // Other
    Fraction getReciprocal() const;
    std::string toString(bool showPositiveSign = false) const;
    std::string toString2(unsigned char mode = 0) const; /*
    Mode is a set of bit that represent different settings
    1 : Show positive sign
    2 : Use mixed number form
    */
    double toNumber() const;

    friend Fraction operator-(const Fraction &);

    // Assignment operators
    friend Fraction operator+(const Fraction &lhs, const Fraction &rhs);
    friend Fraction operator-(const Fraction &lhs, const Fraction &rhs);
    friend Fraction operator*(const Fraction &lhs, const Fraction &rhs);
    friend Fraction operator/(const Fraction &lhs, const Fraction &rhs);

    // Assignment operators
    Fraction &operator=(const Fraction &src);
    Fraction &operator+=(const Fraction &src);
    Fraction &operator-=(const Fraction &src);
    Fraction &operator*=(const Fraction &src);
    Fraction &operator/=(const Fraction &src);

    // Relationship operators
    friend bool operator==(const Fraction a, const Fraction b);
    friend bool operator!=(const Fraction a, const Fraction b);
    friend bool operator>(const Fraction a, const Fraction b);
    friend bool operator<(const Fraction a, const Fraction b);
    friend bool operator>=(const Fraction a, const Fraction b);
    friend bool operator<=(const Fraction a, const Fraction b);
};