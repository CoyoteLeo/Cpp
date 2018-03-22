#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "FakeRand.h"
using namespace std;

typedef struct person
{
    string name;
    int level, start, duration, win;
} person;

bool Win(const int &targetLv, const int &opponentLv)
{
    double rate = pow(2, targetLv - opponentLv);
    return rand() / (RAND_MAX + 1.0) < rate / (rate + 1);
}

class Game
{
   public:
    Game()
    {
        A = NULL;
        B = NULL;
        goingOn = false;
        endTime = 0;
    }
    person *A;
    person *B;
    bool goingOn;
    int endTime;
};

bool compareStart(const person &a, const person &b)
{
    return a.start < b.start;
}
int main()
{
    int amount;
    while (cin >> amount)
    {
        person people[9999];
        vector<person *> line;
        for (int i = 0; i < amount; i++)
        {
            cin >> people[i].name;
            cin >> people[i].level;
            cin >> people[i].start;
            cin >> people[i].duration;
            people[i].win = 0;
        }
        sort(people, people + amount, compareStart);
        int notArrive = 0;
        Game game;
        for (int nowTime = 0; notArrive < amount || !line.empty() || game.A != NULL || game.B != NULL; nowTime++)
        {
            bool print_game_information = false;

            if (game.A != NULL)
                game.A->duration--;
            if (game.B != NULL)
                game.B->duration--;
            while (notArrive < amount && people[notArrive].start <= nowTime)
            {
                line.push_back(&people[notArrive++]);
                print_game_information = true;
            }
            if (game.A != NULL && game.B != NULL)
            {
                if (game.goingOn && nowTime == game.endTime)
                {
                    print_game_information = true;
                    if (!Win(game.A->level - 1, game.B->level) || game.A->win == 4)  // A lose B win
                    {
                        if (game.A->win == 4)
                            game.A->win = 0;
                        game.B->win++;
                        if (game.A->duration > 0)
                            line.push_back(game.A);
                        game.A = NULL;
                        game.B = game.B->duration <= 0 ? NULL : game.B;
                        swap(game.A, game.B);
                    }
                    else
                    {
                        game.A->win++;
                        if (game.B->duration > 0)
                            line.push_back(game.B);
                        game.B = NULL;
                        game.A = game.A->duration <= 0 ? NULL : game.A;
                    }
                    game.goingOn = false;
                    game.endTime = -1;
                }
            }
            if (game.A == NULL && !line.empty())
            {
                if (game.B != NULL)
                {
                    game.A = game.B;
                    game.B = NULL;
                }
                else
                {
                    game.A = line.front();
                    line.erase(line.begin());
                }
            }
            if (game.B == NULL && !line.empty())
            {
                game.B = line.front();
                line.erase(line.begin());
            }
            if (game.A != NULL && game.B != NULL && !game.goingOn)
            {
                game.goingOn = true;
                game.endTime = nowTime + 5;
            }

            if (print_game_information)
            {
                cout << nowTime << ":";
                if (game.A != NULL)
                    cout << game.A->name << " lv" << game.A->level;
                else
                    cout << "none";
                cout << " vs. ";
                if (game.B != NULL)
                    cout << game.B->name << " lv" << game.B->level;
                else
                    cout << "none";
                cout << " | ";
                for (int i = 0; i < line.size(); i++)
                {
                    cout << line[i]->name << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}