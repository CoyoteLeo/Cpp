#include "Form.h"
// inputmain2.cpp
int main()
{
    Form form2;
    form2.SetInputWord("calculator");
    form2.ProcessInputWord();
    form2.SetFileName("word.txt");
    form2.Load_CompaerWord();
    form2.PrintFoundWords();
    system("pause");
    return 0;
}