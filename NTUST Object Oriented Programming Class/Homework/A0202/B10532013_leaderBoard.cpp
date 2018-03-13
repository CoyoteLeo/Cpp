#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void getHighScores(string highestName[], int highestScore[])
{
    string temp, name;
    fstream input;
    int inputScore;
    input.open("score.txt");
    while (getline(input, temp))
    {
        name = temp;
        getline(input, temp);
        inputScore = stoi(temp);
        for (int i = 2; i >= 0; i--)
        {
            if (inputScore > highestScore[i])
            {
                for (int j = i; j < 2; j++)
                {
                    highestScore[i + 1] = highestScore[i];
                    highestName[i + 1] = highestName[i];
                }
                highestScore[i] = inputScore;
                highestName[i] = name;
            }
            else
                break;
        }
    }
}

int main()
{
    string name[3] = {};
    int score[3] = {0};
    getHighScores(name, score);
    for (int i = 0; i < 3; i++)
    {
        cout << name[i] << '\n' << score[i] << endl;
    }
    return 0;
}