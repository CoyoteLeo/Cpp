#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
using namespace std;

class Form
{
   private:
    string input;     //輸入的字
    string fileName;  //檔案名稱
    int letterCount[26];
    vector<string> result;

   public:
    Form();
    void SetInputWord(string inputWord);  //設定Input
    void ProcessInputWord();              //處理Input的資訊
    void SetFileName(string fileName);    //設定檔案名稱
    void Load_CompaerWord();              //讀檔並且比較
    void PrintFoundWords();               //印出符合的字
};
Form::Form() : letterCount{0}
{
}
void Form::SetInputWord(string inputWord)
{
    input = inputWord;
}
void Form::ProcessInputWord()
{
    for (unsigned int i = 0; i < input.length(); i++)
        letterCount[(int)(tolower(input[i])) - (int)'a']++;
}
void Form::SetFileName(string fileName)
{
    this->fileName = fileName;
}
void Form::Load_CompaerWord()
{
    fstream f;
    f.open(fileName.c_str(), fstream::in);
    string input_word;
    while (f >> input_word)
    {
        int inputLetterCount[26] = {0};
        bool flag = true, otherChar = false;
        for (unsigned int i = 0; i < input_word.length(); i++)
        {
            if (!isalpha(input_word[i]))
            {
                otherChar = true;
                break;
            }
            inputLetterCount[(int)(tolower(input_word[i])) - (int)'a']++;
        }
        if (otherChar)
            continue;
        for (unsigned int i = 0; i < 26; i++)
        {
            if (letterCount[i] < inputLetterCount[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            result.push_back(input_word);
    }
}
void Form::PrintFoundWords()
{
    for (unsigned int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
}
