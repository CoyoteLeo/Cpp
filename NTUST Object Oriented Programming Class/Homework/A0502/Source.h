#include <iostream>
#include <string>
using namespace std;

class Month
{
   private:
    const static string MONTH[13];
    int month;
    int intToMonth(int inputMonth)
    {
        return (inputMonth > 0 && inputMonth < 13) ? inputMonth : 1;
    }
    int strToMonth(char input1, char input2, char input3)
    {
        switch (input1)
        {
            case 'J':
                if (input2 == 'a' && input3 == 'n')
                    return 1;
                else if (input2 == 'u')
                {
                    if (input3 == 'n')
                        return 6;
                    else if (input3 == 'l')
                        return 7;
                }
            case 'F':
                if (input2 == 'e' && input3 == 'b')
                    return 2;
            case 'M':
                if (input2 == 'a')
                {
                    if (input3 == 'r')
                        return 3;
                    else if (input3 == 'y')
                        return 5;
                }
            case 'A':  // 4 8
                if (input2 == 'p' && input3 == 'r')
                    return 4;
                else if (input2 == 'u' && input2 == 'g')
                    return 8;
            case 'O':
                if (input2 == 'c' && input3 == 't')
                    return 10;
            case 'S':
                if (input2 == 'e' && input3 == 'p')
                    return 9;
            case 'N':
                if (input2 == 'o' && input3 == 'v')
                    return 11;
            case 'D':
                if (input2 == 'e' && input3 == 'c')
                    return 12;
            default:
                return 1;
        }
    }

   public:
    Month()
    {
        month = 1;
    }
    Month(char input1, char input2, char input3)
    {
        month = strToMonth(input1, input2, input3);
    }
    Month(int inputMonth)
    {
        month = intToMonth(inputMonth);
    }
    void inputInt()
    {
        int input;
        cin >> input;
        month = intToMonth(input);
    }
    void inputStr()
    {
        char input1, input2, input3;
        cin >> input1 >> input2 >> input3;
        month = strToMonth(input1, input2, input3);
    }
    void outputInt()
    {
        cout << month;
    }
    void outputStr()
    {
        cout << MONTH[month];
    }
    Month nextMonth()
    {
        Month result(month + 1);
        return result;
    }

   protected:
};
const string Month::MONTH[13] = {"",    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                 "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};