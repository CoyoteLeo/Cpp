#include <cmath>
#include <cstddef>
using namespace std;

class Polynomial
{
   public:
    Polynomial();  // creates an empty polynomial
    Polynomial(const Polynomial& poly);  // copy constuctor
    Polynomial(double coefficient[], int size);
    ~Polynomial();  
    // Use indexed polynomial as r-value to inspect coefficient//and as l-value to assign coefficient
    double& operator[](int degree);  // This is required if we are to have const correctness
    const double& operator[](int degree) const; 
    Polynomial& operator=(const Polynomial& rhs);
    int mySize();  // friend functions:
    friend double evaluate(const Polynomial& poly, double arg);
    friend Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
    friend Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs);
    friend Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs);
    friend Polynomial operator+(const double constant, const Polynomial& rhs);
    friend Polynomial operator-(const double constant, const Polynomial& rhs);
    friend Polynomial operator*(const double constant, const Polynomial& rhs);
    friend Polynomial operator+(const Polynomial& lhs, const double constant);
    friend Polynomial operator-(const Polynomial& lhs, const double constant);
    friend Polynomial operator*(const Polynomial& lhs, const double constant);

   private:
    double* coef;
    int size;
};

Polynomial::Polynomial() : coef(new double[1]()), size(0)
{
}

Polynomial::Polynomial(const Polynomial& poly) : coef(new double[poly.size]()), size(poly.size)
{
    for (int i = 0; i < poly.size; i++)
        this->coef[i] = poly[i];
}

Polynomial::Polynomial(double coefficient[], int size) : coef(new double[size]()), size(size)
{
    for (int i = 0; i < size; i++)
        coef[i] = coefficient[i];
}

Polynomial::~Polynomial()
{
    delete[] coef;
    coef = NULL;
}

double& Polynomial::operator[](int degree)
{
    return coef[degree];
}
const double& Polynomial::operator[](int degree) const
{
    return coef[degree];
}
Polynomial& Polynomial::operator=(const Polynomial& rhs)
{
    delete[] this->coef;
    coef = new double[rhs.size]();
    for (int i = 0; i < rhs.size; i++)
        this->coef[i] = rhs[i];
    this->size = rhs.size;
    return *this;
}
int Polynomial::mySize()
{
    return size;
}
double evaluate(const Polynomial& poly, double arg)
{
    double result = 0;
    for (int i = 0; i < poly.size; i++)
    {
        result += poly[i] * pow(arg, i);
    }
    return result;
}
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs)
{
    int max = (lhs.size > rhs.size ? lhs.size : rhs.size);
    double* temp = new double[max]();
    for (int i = 0; i < max; i++)
    {
        temp[i] = lhs[i] + rhs[i];
    }
    Polynomial result(temp, max);
    delete[] temp;
    return result;
}
Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs)
{
    int max = lhs.size > rhs.size ? lhs.size : rhs.size;
    double* temp = new double[max]();
    for (int i = 0; i < max; i++)
    {
        temp[i] = lhs[i] - rhs[i];
    }
    Polynomial result(temp, max);
    delete[] temp;
    return result;
}
Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs)
{
    if (lhs.size == 0 || rhs.size == 0)
    {
        Polynomial result;
        return result;
    }
    else
    {
        int max = (lhs.size - 1) + (rhs.size - 1) + 1;
        double* temp = new double[max]();
        for (int i = 0; i < lhs.size; i++)
        {
            for (int j = 0; j < rhs.size; j++)
            {
                temp[i + j] += lhs[i] * rhs[j];
            }
        }
        Polynomial result(temp, max);
        delete[] temp;
        return result;
    }
}
Polynomial operator+(const double constant, const Polynomial& rhs)
{
    double temp[] = {constant};
    return Polynomial(temp, 1) + rhs;
}
Polynomial operator-(const double constant, const Polynomial& rhs)
{
    double temp[] = {constant};
    return Polynomial(temp, 1) - rhs;
}
Polynomial operator*(const double constant, const Polynomial& rhs)
{
    double temp[] = {constant};
    return Polynomial(temp, 1) * rhs;
}
Polynomial operator+(const Polynomial& lhs, const double constant)
{
    double temp[] = {constant};
    return lhs + Polynomial(temp, 1);
}
Polynomial operator-(const Polynomial& lhs, const double constant)
{
    double temp[] = {constant};
    return lhs - Polynomial(temp, 1);
}
Polynomial operator*(const Polynomial& lhs, const double constant)
{
    double temp[] = {constant};
    return lhs * Polynomial(temp, 1);
}