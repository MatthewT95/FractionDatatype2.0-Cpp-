#include <stdexcept>
#include <string>
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
        std::invalid_argument("Fraction denominator can not be zero.");
    }
    simplifyFraction();
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
    }
}

unsigned int Fraction::getNumerator()
{
    return this->numerator;
}

unsigned int Fraction::getDenominator()
{
    return this->denominator;
}

char Fraction::getSign()
{
    return this->sign;
}

bool Fraction::isPositive()
{
    return sign > 0;
}

bool Fraction::isNegative()
{
    return sign < 0;
}

bool Fraction::isZero()
{
    return sign == 0;
}

Fraction Fraction::getReciprocal()
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

std::string Fraction::toString(bool showPositiveSign = false)
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

unsigned int Fraction::LCD(unsigned int a, unsigned int b)
{
    return (a * b) / GCD(a, b);
}

void Fraction::simplifyFraction()
{
    unsigned int commonFactor = GCD(this->numerator, this->denominator);
    this->numerator = this->numerator / commonFactor;
    this->denominator = this->denominator / commonFactor;
}