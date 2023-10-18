# FractionDatatype2.0-Cpp-

----

Author: Matthew Taormina

## Summary

This project contains the header and source file for a class designed to hold fractional values. Using this class you can store and modify fractions.

## How to add to your project

The files are designed for a project that has a header and source folder. The header folder containing all project header(.hpp) files and source folder containing all source(.cpp) files. To add to your project place the fraction.hpp file in your header folder of your project. Place the fraction.cpp file in the source folder of your project. Include the header file in all source files that use the class. When you compile the program, pass all source files to complier.

use a command such as the following to compile.
g++ source/* -o main.exe

Use the following to include the header file.

```cpp
#include "../header/fraction.hpp
```

## How to use

### Creating instances of fractions

Fractions can be created in many ways.

- A default fraction of zero.
- A specific fraction from with a defined numerator and denominator.
The sign of the numerator decides the fraction sign. Only excepts denominators greater then 0.
- Create a fraction equal to provided number either whole number of decimal.
We create the most simplified fraction equal to provided number.

```cpp
Fraction a;       // Create a default fraction of 0/1
Fraction b(1,3);  // Create a positive fraction of 1/3
Fraction c(-5,6); // Create a negative fraction -5/6
Fraction (3);     // Creates a fraction equal to whole number 3 which is 3/1
Fraction(0.125)   // Creates a fraction equal to decimal value 0.125. The fraction is 1/8 
```

### Perform arithmetic operations on fractions

All basic arithmetic operations can be performed on fractions no different then if they were number values. Operations such as addition, subtraction, multiplication and division can be performed as shown below using built in operators.

```cpp
Fraction a(1,2);
Fraction b(1,3);
Fraction c;

c = a + b; // Addition of two fractions
c = a - b; // Subtraction of fraction b from a
c = a * b; // Multiplication of two fractions
c = a / b; // Dividing fraction a by b
```

### Perform assignment operations on a fraction with fractions

This class also supports all assignment operators including the shortcuts for arithmetic operations.

```cpp
Fraction a(1,2);

a =  Fraction(1,3); // Assign a new value to fraction
a += Fraction(1,3); // Increment value by fraction
a -= Fraction(1,3); // Decrement value by fraction
a *= Fraction(1,3); // Multiple by and self assign by fraction
a /= Fraction(1,3); // Divide by and self assign by fraction
```

### Perform equality operations on fractions

Support both == and != equality operators which tell if two fractions are identical or not.

```cpp
Fraction a(1,2);
Fraction b(1,4);

a == a // Returns true
a == b // Returns false
a != a // Returns false
a != b // Returns True
```

### Perform relational operations on fractions

Supports '>','<','>=' and'<=' operations on fractions.

```cpp
Fraction a(1,2);
Fraction b(-1,3);

a > b;  // Fraction a is greater then Fraction b
a < b;  // Fraction a is less then Fraction b
a >= b; // Fraction a is greater then or equal to Fraction b
a <= b; // Fraction a is less then or equal to Fraction b
```


### Setters

Has setters for numerator, denominator and sign.
Setting sign to zero will set numerator to 0 and denominator to 1.

#### Prototypes of setters

```cpp
// Setters
void setNumerator(unsigned int);   // Sets the fraction's numerator
void setDenominator(unsigned int); // Sets the fraction's denominator
void setSign(char);                // Sets the fraction's sign
void scale(unsigned int);          // Scales the numerator and denominator by factor
void simplifyFraction();           // Simplifies the fraction
```

#### Examples

```cpp
Fraction a;

a.setNumerator(5)      // Sets fraction numerator to five
a.setDenominator(6)    // Sets fraction denominator to six
a.setSign(1)           // Sets the fraction sign to positive
a.scale(2)             // Scales the fraction numerator and denominator by 2
```

### Getters

There are many methods for getting information about a fraction.

- getNumerator()
- getDenominator()
- getSign()
- isPositive()
- isNegative()
- isZero()

#### Prototypes of getters

```cpp
// Getters
unsigned int getNumerator() const;   // Returns the fraction numerator
unsigned int getDenominator() const; // Returns the fraction denominator
char getSign() const;                // Returns a number representing the sign of the fraction
bool isPositive() const;             // Returns true if fraction is greater then zero
bool isNegative() const;             // Returns true if fraction is less then zero
bool isZero() const;                 // Returns true if fraction is zero
```

### Other methods

There many other methods.

- getReciprocal() : returns a fraction that is the reciprocal of the source fraction.
- toString() : returns a string representing the fraction
- toNumber : return a double which is equal to the fraction
- simplifyFraction() : Simplifies the fraction

```cpp
// Other
Fraction getReciprocal() const;
std::string toString(bool showPositiveSign = false) const;
double toNumber() const;
```
