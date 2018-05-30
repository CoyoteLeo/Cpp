#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Dice
{
   public:
    Dice();
    Dice(int numSides);
    virtual int rollDice() const;

   protected:
    int numSides;
};
Dice::Dice()
{
    numSides = 6;
    srand(time(NULL));  // Seed srandom number generator
}
Dice::Dice(int numSides)
{
    this->numSides = numSides;
    srand(time(NULL));  // Seeds random number generator
}
int Dice::rollDice() const
{
    return (rand() % numSides) + 1;
}
// Take two dice objects,roll them,and return the sum
int rollTwoDice(const Dice& die1, const Dice& die2)
{
    return die1.rollDice() + die2.rollDice();
}

class LoadedDice : public Dice
{
   public:
    LoadedDice();
    LoadedDice(int numSides);
    int rollDice() const;
};

LoadedDice::LoadedDice() : Dice()
{
}

LoadedDice::LoadedDice(int numSides) : Dice(numSides)
{
}

int LoadedDice::rollDice() const
{
    if (rand() % 2 == 0)
    {
        return numSides;
    }
    else
    {
        return Dice::rollDice();
    }
}

int main()
{  // Uncomment the line below for regular dice
    Dice die1(6), die2(6);
    LoadedDice die3(6), die4(6);
    // This would be the game;here we just simulate it rolling 10 times
    for (int i = 0; i < 10; i++)
    {
        int total = rollTwoDice(die1, die2);
        cout << total << "";
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        int total = rollTwoDice(die3, die4);
        cout << total << "";
    }
    cout << endl;
    return 0;
}