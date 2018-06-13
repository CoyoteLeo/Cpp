#include <iostream>
using namespace std;

class NegativeDeposit : public exception
{
};
class InsufficientFunds : public exception
{
};
class Account
{
   private:
    double balance;

   public:
    Account()
    {
        balance = 0;
    }
    Account(double initialDeposit)
    {
        balance = initialDeposit;
    }
    double getBalance()
    {
        return balance;
    }
    // returns new balance or -1 if error
    double deposit(double amount)
    {
        if (amount > 0)
            balance += amount;
        else
        {
            throw NegativeDeposit();
        }
        return balance;
    }
    // return new balance or -1 if invalid amount
    double withdraw(double amount)
    {
        if ((amount > balance) || (amount < 0))
        {
            throw InsufficientFunds();
        }
        else
            balance -= amount;
        return balance;
    }
};

int main()
{
    Account a(100);
    try
    {
        cout << "Depositing50" << endl;
        cout << "Newbalance:" << a.deposit(50) << endl;
        cout << "Depositing-25" << endl;
        cout << "Newbalance:" << a.deposit(-25) << endl;
        cout << "Withdraw25" << endl;
        cout << "Newbalance:" << a.withdraw(25) << endl;
        cout << "Withdraw250" << endl;
        cout << "Newbalance:" << a.withdraw(250) << endl;
    }
    catch (InsufficientFunds &exc)  // InsufficientFunds : aclassname
    {
        cout << "Not enough money to withdraw that amount." << endl;
    }
    catch (NegativeDeposit &exc)  // NegativeDeposit : aclassname
    {
        cout << "You may only deposit a positive amount." << endl;
    }
    cout << "Enter a character to exit" << endl;
    char wait;
    cin >> wait;
    return 0;
}