#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class PrimeNumber
{
   private:
    int number;

   public:
    PrimeNumber();
    PrimeNumber(const PrimeNumber& input);
    PrimeNumber(int input);
    PrimeNumber& operator++();
    PrimeNumber operator++(int);
    PrimeNumber& operator--();
    PrimeNumber operator--(int);
    int get();
};

PrimeNumber::PrimeNumber()
{
    number = 1;
}
PrimeNumber::PrimeNumber(const PrimeNumber& input)
{
    this->number = input.number;
}
PrimeNumber::PrimeNumber(int input)
{
    number = input;
}
PrimeNumber& PrimeNumber::operator++()  // prefix
{
    bool isPrime = true;
    do
    {
        number++;
        isPrime = true;
        for (int i = 2; i <= sqrt(number); i++)
        {
            if (number % i == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            break;
    } while (true);
    return *this;
}
PrimeNumber PrimeNumber::operator++(int)  // postfix
{
    PrimeNumber result = *this;
    ++(*this);
    return result;
};
PrimeNumber& PrimeNumber::operator--()
{
    bool isPrime = true;
    do
    {
        number--;
        isPrime = true;
        for (int i = 2; i <= sqrt(number); i++)
        {
            if (number % i == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            break;
    } while (true);
    return *this;
}
PrimeNumber PrimeNumber::operator--(int)
{
    PrimeNumber result = *this;
    --(*this);
    return result;
};
int PrimeNumber::get()
{
    return number;
}