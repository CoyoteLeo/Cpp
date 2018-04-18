#include"Form.h"

int main()
{
    Form form1;
    form1.SetInputWord("SWIMMING");
    form1.ProcessInputWord();
    form1.SetFileName("word.txt");
    form1.Load_CompaerWord();
    form1.PrintFoundWords();
    system("pause");
    return 0;
}