#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
   private:
    double real_;
    double imaginary;

   public:
    Complex();
    Complex(double r, double i);
    Complex(double r);
    double real();
    double imag();
    double norm();
    bool operator==(const Complex a);
    Complex operator+(const Complex& a);
    Complex operator-(const Complex& a);
    Complex operator*(const Complex& a);
    Complex operator/(const Complex& a);
    Complex operator+(const double d);
    Complex operator-(const double d);
    Complex operator*(const double d);
    Complex operator/(const double d);
    friend double real(Complex& a);
    friend double imag(Complex& a);
    friend double norm(Complex& a);
    friend Complex operator+(double a, Complex& c);
    friend Complex operator-(double a, Complex& c);
    friend Complex operator*(double a, Complex& c);
    friend Complex operator/(double a, Complex& c);
    friend ostream& operator<<(ostream& stream, const Complex& c);
    friend istream& operator>>(istream& stream, Complex& c);
};

bool Complex::operator==(const Complex a)
{
    return (this->real_ == a.real && this->imaginary == a.imaginary);
}
Complex Complex::operator+(const Complex& a)
{
    return Complex(this->real_ + a.real_, this->imaginary + a.imaginary);
}
Complex Complex::operator-(const Complex& a)
{
    return Complex(this->real_ - a.real_, this->imaginary - a.imaginary);
}
Complex Complex::operator*(const Complex& a)
{
    return Complex((this->real_ * a.real_ - this->imaginary * a.imaginary),
                   (this->imaginary * a.real_ + a.imaginary * this->real_));
}
Complex Complex::operator/(const Complex& a)
{
    double denominator = a.real_ * a.real_ + a.imaginary * a.imaginary;
    return Complex((this->real_ * a.real_ + this->imaginary * a.imaginary) / denominator,
                   (this->imaginary * a.real_ - a.imaginary * this->real_) / denominator);
}
Complex Complex::operator+(const double d)
{
    return Complex(this->real_ + d, this->imaginary);
}
Complex Complex::operator-(const double d)
{
    return Complex(this->real_ - d, this->imaginary);
}
Complex Complex::operator*(const double d)
{
    return *this * Complex(d);
}
Complex Complex::operator/(const double d)
{
    return *this / Complex(d);
}
Complex::Complex()
{
    real_ = 0;
    imaginary = 0;
}
Complex::Complex(double r, double i)
{
    real_ = r;
    imaginary = i;
}
Complex::Complex(double r)
{
    real_ = r;
    imaginary = 0;
}
double Complex::real()
{
    return real_;
}
double Complex::imag()
{
    return imaginary;
}
double Complex::norm()
{
    return sqrt(real_ * real_ + imaginary * imaginary);
}
ostream& operator<<(ostream& stream, const Complex& c)
{
    stream << c.real_ << " + " << c.imaginary << "*i" << endl;
    return stream;
};
istream& operator>>(istream& stream, Complex& c)
{
    stream >> c.real_ >> c.imaginary;
    return stream;
};
Complex operator+(double a, Complex& c)
{
    return Complex(a) + c;
};

Complex operator-(double a, Complex& c)
{
    return Complex(a) - c;
};

Complex operator*(double a, Complex& c)
{
    return Complex(a) * c;
};

Complex operator/(double a, Complex& c)
{
    return Complex(a) / c;
};

double real(Complex& c)
{
    return c.real();
}

double imag(Complex& c)
{
    return c.imag();
}
double norm(Complex& c)
{
    return c.norm();
}