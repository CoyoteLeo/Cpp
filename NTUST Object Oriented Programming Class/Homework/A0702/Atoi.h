#include <string>
#include <cmath>
using namespace std;

class Atoi
{
   private:
    string beTrans;
    char sign;

   public:
    Atoi();
    Atoi(string s);
    void SetString(string s);
    const string GetString();
    int Length();
    bool IsDigital();
    int StringToInteger();
};

Atoi::Atoi()
{
}

Atoi::Atoi(string s)
{
    beTrans = s;
}

void Atoi::SetString(string s)
{
    beTrans = s;
}

const string Atoi::GetString()
{
    
}
int Atoi::Length()
{
    if (beTrans[0] == '-')
        return beTrans.length() - 1;
    return beTrans.length();
}
bool Atoi::IsDigital()
{
    unsigned int checker = 0;
    if (beTrans[0] == '-')
        checker = 1;
    for (; checker < beTrans.length(); checker++)
    {
        if ((int)beTrans[checker] < 48 || (int)beTrans[checker] > 57)
            return false;
    }
    return true;
}
int Atoi::StringToInteger()
{
    int result = 0;
    for (int i = beTrans.length() - 1, j = 0; i > 0; i--, j++)
    {
        result += ((int)beTrans[i] - (int)'0') * ceil(pow(10, j));
    }
    if (beTrans[0] == '-')
        result *= -1;
    else
        result += ((int)beTrans[0] - (int)'0') * ceil(pow(10, beTrans.length() - 1));
    return result;
}