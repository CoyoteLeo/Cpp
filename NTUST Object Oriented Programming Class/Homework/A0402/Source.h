#include <iostream>
using namespace std;
class Fraction
{
   private:
    int numerator;
    int denominator;

   public:
    void setNumerator(int input_numerator)
    {
        numerator = input_numerator;
    }
    void setDenominator(int input_denominator)
    {
        denominator = input_denominator;
    }
    double getDouble()
    {
        return (double)numerator / denominator;
    }
    void outputReducedFraction()
    {
        int tempNumerator = numerator, tempDenominator = denominator;
        while (tempNumerator != 0 and tempDenominator != 0)
        {
            if (tempNumerator >= tempDenominator)
            {
                tempNumerator = tempNumerator % tempDenominator;
            }
            else if (tempDenominator > tempNumerator)
            {
                tempDenominator = tempDenominator % tempNumerator;
            }
        }
        if (tempNumerator > tempDenominator)
        {
            cout << numerator / tempNumerator;
            if (denominator / tempNumerator != 1)
            {
                cout << '/' << denominator / tempNumerator;
            }
        }
        else
        {
            cout << numerator / tempDenominator;
            if (denominator / tempDenominator != 1)
            {
                cout << '/' << denominator / tempDenominator;
            }
        }
    }

   protected:
};