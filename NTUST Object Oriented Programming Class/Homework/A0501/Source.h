#include <iostream>
#include <string>
using namespace std;

class HotDogStand
{
   private:
    string name;
    int amount;
    static int totalAmount;

   public:
    HotDogStand(string inputName, int inputAmount);
    HotDogStand(string inputName);
    void justSold();
    int thisStandSoldAmount();
    static int allStandsoldAmount();
    void print();
};

int HotDogStand::totalAmount = 0;

HotDogStand::HotDogStand(string inputName, int inputAmount)
{
    name = inputName;
    amount = inputAmount;
    totalAmount += amount;
}

HotDogStand::HotDogStand(string inputName)
{
    name = inputName;
    amount = 0;
}

void HotDogStand::justSold()
{
    amount++;
    totalAmount++;
}

int HotDogStand::thisStandSoldAmount()
{
    return amount;
}

int HotDogStand::allStandsoldAmount()
{
    return totalAmount;
}

void HotDogStand::print()
{
    cout << name << " " << amount << endl;
}