#include <iostream>
using namespace std;

bool checkForWin(int guess, int answer)
{
    if (answer == guess)

    {
        cout << "You're right! You win!" << endl;
        return true;
    }

    else if (answer < guess)
        cout << "Your guess is too high." << endl;
    else
        cout << "Your guess is too low." << endl;
    return false;
}

class Player
{
   public:
    virtual int getGuess();
    virtual bool& setTooBig();

   private:
    bool TooBig;
};

int Player::getGuess()
{
    return 0;
}

bool& Player::setTooBig()
{
    return TooBig;
}

class HumanPlayer : public Player
{
   public:
    virtual int getGuess();
};

int HumanPlayer::getGuess()
{
    int input;
    cin >> input;
    return input;
}

class ComputerPlayer : public Player
{
   public:
    ComputerPlayer();
    virtual int getGuess();
    virtual bool& setTooBig();

   private:
    bool TooBig = true;
    int last_max, last_min, last;
};

ComputerPlayer::ComputerPlayer()
{
    TooBig = true;
    last_max = last = 100;
    last_min = 0;
}

bool& ComputerPlayer::setTooBig()
{
    return TooBig;
}

int ComputerPlayer::getGuess()
{
    if (TooBig)
        last_max = last;
    else
        last_min = last + 1;

    if (last_max == last_min)
        last = last_min;
    else
        last = rand() % (last_max - last_min) + last_min;
    cout << last << endl;
    return last;
}

void play(Player& player1, Player& player2)
{
    int answer = 0, guess = 0;
    answer = rand() % 101;
    bool win = false;

    while (!win)

    {
        cout << "Player 1's turn to guess." << endl;
        guess = player1.getGuess();
        win = checkForWin(guess, answer);
        player1.setTooBig() = (guess > answer);
        if (win)
            return;
        cout << "Player 2's turn to guess." << endl;

        guess = player2.getGuess();
        win = checkForWin(guess, answer);
        player2.setTooBig() = (guess > answer);
    }
}

int main()

{
    HumanPlayer playerH1, playerH2;
    ComputerPlayer playerC1, playerC2;
    play(playerH1, playerH2);
    play(playerH1, playerC1);
    play(playerC1, playerC2);
    system("pause");
    return 0;
}