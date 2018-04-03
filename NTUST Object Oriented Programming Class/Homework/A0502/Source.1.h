#include <iostream>
#include <string>
#include <map>
using namespace std;

class Month
{
   private:
    const static string MONTH[13];
    static map<string, int> monthMap;
    int month;
    int intToMonth(int inputMonth);
    int strToMonth(string m);

   public:
    Month();
    Month(char input1, char input2, char input3);
    Month(int inputMonth);
    void inputInt();
    void inputStr();
    void outputInt();
    void outputStr();
    Month nextMonth();
};
map<string, int> Month::monthMap = {{"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4},  {"May", 5},  {"Jun", 6},
                                    {"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}};
const string Month::MONTH[13] = {"",    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                 "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

int Month::intToMonth(int inputMonth)
{
    return (inputMonth > 0 && inputMonth < 13) ? inputMonth : 1;
}
int Month::strToMonth(string m)
{
    if (monthMap.find(m) != monthMap.end())
        return monthMap.find(m)->second;
    else
        return 1;
}

Month::Month()
{
    month = 1;
}

Month::Month(char input1, char input2, char input3)
{
    char input[4] = {input1, input2, input3, 0};
    month = strToMonth(string(input));
}

Month::Month(int inputMonth)
{
    month = intToMonth(inputMonth);
}

void Month::inputInt()
{
    int input;
    cin >> input;
    month = intToMonth(input);
}

void Month::inputStr()
{
    char input[4] = {0};
    cin >> input[0] >> input[1] >> input[2];
    month = strToMonth(string(input));
}

void Month::outputInt()
{
    cout << month;
}

void Month::outputStr()
{
    cout << MONTH[month];
}

Month Month::nextMonth()
{
    return Month(month + 1);
}