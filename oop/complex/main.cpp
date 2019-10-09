#include<bits/stdc++.h>

using namespace std;

class Complex 
{
public:
    Complex (double r = 0, double i = 0) 
    : re (r), im (i)
    {}
    Complex& operator += (const Complex&);
    //Complex operator + (const Complex&, const Complex&);
    double real() const { return re; }
    double img() const { return im; }
private:
    double re, im;

    friend Complex& __doapl(Complex*, const Complex&);
};

inline Complex&
__doapl(Complex* ths, const Complex& r) {
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline Complex&
Complex::operator += (const Complex& r) 
{
    return __doapl(this, r);
}

inline Complex
operator+(const Complex& x, const Complex& y)
{
    return Complex (x.real () + y.real (),
                    x.img () + y.img () );
}

inline Complex
operator+(const Complex& x, double y)
{
    return Complex(x.real() + y, x.img());
}

inline Complex
operator+(double x, const Complex& y)
{
    return Complex(x+y.real(), y.img());
}

ostream&
operator<<(ostream& os, const Complex& x)
{
    return os << '(' << x.real() << ',' << x.img() << ')';
}

int main()
{
    Complex c1(9,8);
    Complex c2;
    cout << c1 ;
    cout << c1 << endl;
    c2 = c1+c2;
        cout << c2 << endl;
    c2 = c1 + 5;
        cout << c2 << endl;
    c2 = 7 + c1;
    cout << c2 << endl;
}