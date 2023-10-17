#include <stdexcept>
#include <string>
#include <iostream>
#include "../header/Fraction.hpp"

Fraction::Fraction()
{
    this->numerator = 0;
    this->denominator = 1;
    this->sign = 0;
}

Fraction::Fraction(int numerator, unsigned int denominator)
{
    // Checks if given denominator is zero which is an invalid argument
    if (denominator != 0)
    {
        this->numerator = abs(numerator);
        this->denominator = abs(denominator);
        if (numerator > 0)
        {
            this->sign = 1;
        }
        else if (numerator < 0)
        {
            this->sign = -1;
        }
        else
        {
            this->sign = 0;
        }
    }
    else
    {
        throw std::invalid_argument("Fraction denominator can not be zero.");
    }
}

Fraction::Fraction(const Fraction &t)
{
    this->numerator = t.numerator;
    this->denominator = t.denominator;
    this->sign = t.sign;
}

void Fraction::setNumerator(unsigned int numerator)
{
    this->numerator = numerator;
}

void Fraction::setDenominator(unsigned int denominator)
{
    // Checks if denominator is not zero
    if (denominator != 0)
    {
        this->denominator = denominator;
    }
    // Denominator of zero is invalid
    else
    {
        throw std::invalid_argument("Denominator can not be zero.");
    }
}

void Fraction::setSign(char sign)
{
    // Checks if sign parameter is greater then zero
    if (sign > 0)
    {
        this->sign = 1;
    }
    else if (sign < 0)
    {
        this->sign = -1;
    }
    else
    {
        this->sign = 0;
        this->numerator = 0;
        this->denominator = 1;
    }
}

unsigned int Fraction::getNumerator() const
{
    return this->numerator;
}

unsigned int Fraction::getDenominator() const
{
    return this->denominator;
}

char Fraction::getSign() const
{
    return this->sign;
}

bool Fraction::isPositive() const
{
    return sign > 0;
}

bool Fraction::isNegative() const
{
    return sign < 0;
}

bool Fraction::isZero() const
{
    return sign == 0;
}

Fraction Fraction::getReciprocal() const
{
    Fraction reciprocal;
    if (this->numerator != 0)
    {
        reciprocal.setNumerator(this->denominator);
        reciprocal.setDenominator(this->numerator);
        reciprocal.setSign(this->sign);
    }
    else
    {
        throw std::logic_error("Can not get reciprocal of zero.");
    }
    return reciprocal;
}

std::string Fraction::toString(bool showPositiveSign = false) const
{
    // Checks if fraction is positive
    if (isPositive())
    {
        // Checks if positive sign should be shown
        if (showPositiveSign)
        {
            return "+" + std::to_string(getNumerator()) + "/" + std::to_string(getDenominator());
        }
        else
        {
            return std::to_string(getNumerator()) + "/" + std::to_string(getDenominator());
        }
    }
    // Checks if fraction is negative
    else if (isNegative())
    {
        return "-" + std::to_string(getNumerator()) + "/" + std::to_string(getDenominator());
    }
    else
    {
        return "0/1";
    }
}

double Fraction::toNumber() const
{
    return ((double)getNumerator() / (double)getDenominator()) * getSign();
}

unsigned int Fraction::GCD(unsigned int a, unsigned int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return GCD(b, a % b);
    }
}

unsigned int Fraction::LCM(unsigned int a, unsigned int b)
{
    return (a * b) / GCD(a, b);
}

void Fraction::simplifyFraction()
{
    unsigned int commonFactor = GCD(this->numerator, this->denominator);
    this->numerator = this->numerator / commonFactor;
    this->denominator = this->denominator / commonFactor;
}

Fraction operator-(const Fraction &src)
{
    Fraction ans = src;
    if (src.sign == 1)
    {
        ans.sign = -1;
    }
    else if (src.sign == -1)
    {
        ans.sign = 1;
    }

    return ans;
}

Fraction operator+(const Fraction &lhs, const Fraction &rhs)
{

    // Checks if both fractions are zero and returns zero if true
    if (lhs.sign == 0 && rhs.sign == 0)
    {
        return Fraction(0, 1);
    }
    // Checks if lhs is zero and if true return rhs
    else if (lhs.sign == 0)
    {
        return rhs;
    }
    // Checks if rhs is zero and if true return lhs
    else if (rhs.sign == 0)
    {
        return lhs;
    }
    // Checks if both sides are not zero
    else
    {
        Fraction a = lhs;
        Fraction b = rhs;

        Fraction result;
        // Calculate new denominator
        unsigned int commonDominator = Fraction::LCM(a.denominator, b.denominator);
        // Calculate the multiplier needed to convert both fractions to a common dominator
        unsigned int aMultiplier = commonDominator / a.denominator;
        unsigned int bMultiplier = commonDominator / b.denominator;
        // convert lhs
        a.numerator *= aMultiplier;
        a.denominator *= aMultiplier;
        // convert rhs
        b.numerator *= bMultiplier;
        b.denominator *= bMultiplier;

        // Checks if signs match
        if (a.sign == b.sign)
        {
            result.numerator = a.numerator + b.numerator;
            result.denominator = commonDominator;
            result.sign = a.sign;
        }
        else
        {
            // Calculates value of new numerator
            int value = (a.numerator * a.sign) + (b.numerator * b.sign);
            result.numerator = abs(value); // sets numerator to absolute value of value
            result.denominator = commonDominator;
            // Updates sign according to sign of value
            if (value > 0)
            {
                result.setSign(1);
            }
            else if (value < 0)
            {
                result.setSign(-1);
            }
            else
            {
                result.setSign(0);
            }
        }

        return result;
    }
}

Fraction operator-(const Fraction &lhs, const Fraction &rhs)
{
    return lhs + (-rhs);
}

Fraction operator*(const Fraction &lhs, const Fraction &rhs)
{
    // Check if either lhs or rhs has a value of zero and return zero fraction
    if (lhs.isZero() || rhs.isZero())
    {
        return Fraction();
    }
    else
    {
        Fraction result;
        // Mutiple numerators
        result.numerator = lhs.numerator * rhs.numerator;
        // Mutiple denominators
        result.denominator = lhs.denominator * rhs.denominator;
        // Mutiple signs
        result.sign = lhs.sign * rhs.sign;

        return result;
    }
}

Fraction operator/(const Fraction &lhs, const Fraction &rhs)
{
    if (rhs.isZero())
    {
        throw std::logic_error("Can not divide by zero.");
    }
    else
    {
        return lhs * rhs.getReciprocal();
    }
}

Fraction &Fraction::operator=(const Fraction &src)
{
    numerator = src.numerator;
    denominator = src.denominator;
    sign = src.sign;
    return *this;
}