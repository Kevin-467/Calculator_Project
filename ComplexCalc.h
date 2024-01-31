//Complex Calculation
#pragma once
class Complex
{
private:
    double real_part, imag_part;
public:
    Complex(double r, double imag) { imag_part = imag; real_part = r; }
    ~Complex(){}
    Complex operator+(Complex c1) ;
    Complex operator-(Complex c1) ;
    Complex operator*(Complex c1) ;
    Complex operator/(Complex c1) ;
    Complex operator=(Complex c1) ;
    double Modulous();
    bool operator> (Complex c1) ;
    bool operator== (Complex c1) ;
    friend bool operator!= (Complex c1,Complex c2) ;
    friend bool operator< (Complex c1,Complex c2) ;
    friend bool operator>= (Complex c1, Complex c2);
    friend bool operator<= (Complex c1, Complex c2);
    friend Complex operator+=(Complex c1,Complex c2) ;
    friend Complex operator-=(Complex c1, Complex c2) ;
    friend Complex operator*=(Complex c1, Complex c2) ;
    friend Complex operator/=(Complex c1, Complex c2) ;
    void Show();
};