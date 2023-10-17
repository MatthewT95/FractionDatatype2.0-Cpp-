# FractionDatatype2.0-Cpp-

----

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

### Creating instances

```cpp
Fraction a; // Create a default fraction of 0/1
Fraction b(1,3); // Create a positive fraction of 1/3
Fraction c(-5,6); // Create a negative fraction -5/6
Fraction (3); // Creates a fraction 3/1 from whole number
```

### Perform arithmetic operations on fractions

```cpp
Fraction a(1,2);
Fraction b(1,3);
Fraction c;

c = a + b; // Addition of two fractions
c = a - b; // Subtraction of fraction b from a
c = a * b; // Multiplication of two fractions
c = a / b; // Dividing fraction a by b
```

### Perform assignment operations

```cpp
Fraction a(1,2);

a = Fraction(1,3); // Assign a new value to fraction
a += Fraction(1,3); // Increment value by fraction
a *= Fraction(1,3); // Multiple by and self assign by fraction
a /= Fraction(1,3); // Divide by and self assign by fraction
```
