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

    // Getters
    unsigned int getNumerator();   // Returns the fraction numerator
    unsigned int getDenominator(); // Returns the fraction denominator
    char getSign();                // Returns a number representing the sign of the fraction
    bool isPositive();             // Returns true if fraction is greater then zero
    bool isNegative();             // Returns true if fraction is less then zero
    bool isZero();                 // Returns true if fraction is zero

    // Setters
    void setNumerator(unsigned int);   // Sets the fraction's numerator
    void setDenominator(unsigned int); // Sets the fraction's denominator
    void setSign(char);                // Sets the fraction's sign

    // Other
    Fraction getReciprocal();
    std::string toString(bool);
    double toNumber();
    void simplifyFraction(); // Simplifies the fraction

    // Assignment operators
    friend Fraction operator+(Fraction &lhs, Fraction &rhs);
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