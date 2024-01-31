#include "ComplexCalc.h"
#include <iostream>
#include <cstdio>
#include <complex>
#include <cmath>
using namespace std;

Complex Complex::operator+(Complex c1)
{
    this->real_part += c1.real_part;
    this->imag_part += c1.imag_part;
    return *this;
}

Complex Complex::operator-(Complex c1)
{
    this->real_part -= c1.real_part;
    this->imag_part -= c1.imag_part;
    return *this;
}

Complex Complex::operator*(Complex c1)
{
    double Originrealpart = this->real_part;
    this->real_part = this->real_part * c1.real_part - this->imag_part * c1.imag_part;
    this->imag_part = Originrealpart * c1.imag_part + this->imag_part * c1.real_part;
    return *this;
}

Complex Complex::operator/(Complex c1)
{
    double OriginrealPart = this->real_part;
    if (c1.Modulous() != 0)
    {
        this->real_part = (this->real_part * c1.real_part + this->imag_part * c1.imag_part) / (c1.Modulous());
        this->imag_part = (this->imag_part * c1.real_part - OriginrealPart * c1.imag_part) / (c1.Modulous());
        return *this;
    }
    else
    {
        cerr << "除数的模为0 !" << endl;
        return c1;
    }
}

Complex Complex::operator=(Complex c1)
{
    this->real_part = c1.real_part;
    this->imag_part = c1.imag_part;
    return *this;
}

double Complex::Modulous()
{
    return this->real_part * this->real_part + this->imag_part * this->imag_part;
}

Complex operator+=(Complex c1, Complex c2)
{
    c1.real_part += c2.real_part;
    c1.imag_part += c2.imag_part;
    return c1;
}

Complex operator-=(Complex c1, Complex c2)
{
    c1.real_part -= c2.real_part;
    c1.imag_part -= c2.imag_part;
    return c1;
}

Complex operator*=(Complex c1, Complex c2)
{
    double OriginRealnum = c1.real_part;
    c1.real_part = c1.real_part * c2.real_part - c1.imag_part * c2.imag_part;
    c1.imag_part = OriginRealnum * c2.imag_part + c1.imag_part * c2.real_part;
    return c1;
}

Complex operator/=(Complex c1, Complex c2)
{
    double OriginrealPart = c1.real_part;
    if (c2.Modulous() != 0)
    {
        c1.real_part = (c1.real_part * c2.real_part + c1.imag_part * c2.imag_part) / (c2.Modulous());
        c1.imag_part = (c1.imag_part * c2.real_part - OriginrealPart * c2.imag_part) / (c2.Modulous());
        return c1;
    }
    else
    {
        cerr << "除数的模为0 !" << endl;
        return c2;
    }
}

bool Complex::operator>(Complex c1)
{
    return this->real_part > c1.real_part || this->real_part == c1.real_part && this->imag_part > c1.imag_part;
}

bool Complex::operator==(Complex c1)
{
    return this->real_part == c1.real_part && this->imag_part == c1.imag_part;
}

bool operator!=(Complex c1, Complex c2)
{
    if (c1 == c2) { return false; }
    else { return true; }
}

bool operator<(Complex c1,Complex c2)
{
    if (c1 > c2) { return false; }
    else { return true; }
}

bool operator>=(Complex c1, Complex c2)
{

    if (c1 < c2) { return false; }
    else { return true; }
}

bool operator<=(Complex c1, Complex c2)
{

    if (c1 > c2) { return false; }
    else { return true; }
}

void Complex::Show()
{
    if (this->real_part == 0)
    {
        if (this->imag_part == 1) { printf("i\n\n"); }
        else if (this->imag_part == 0) { printf("0\n\n"); }
        else { printf("%lf i\n\n", this->imag_part); }
    }
    else
    {
        if (this->imag_part == 1) { printf("%lf + i\n\n", this->real_part); }
        else if (this->imag_part <= 0)
        {
            if (this->imag_part < 0)printf("%lf - %lf i\n\n", this->real_part, fabs(this->imag_part));
            else { printf("%lf\n\n", this->real_part); }
        }
        else { printf("%lf + %lf i\n\n", this->real_part, this->imag_part); }
    }
}




