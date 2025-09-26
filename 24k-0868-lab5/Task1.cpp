#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void guessGame(int target, int playerTurn, int totalPlayers)
{
    int guess;
    cout << "Player " << playerTurn << ", enter your guess (1-100): ";
    cin >> guess;

    if (guess == target)
    {
        cout << "🎉 Player " << playerTurn << " wins! The number was " << target << ".\n";
        return;
    }
    else if (guess < target)
    {
        cout << "Too low! Try again...\n";
    }
    else
    {
        cout << "Too high! Try again...\n";
    }

    int nextPlayer = (playerTurn % totalPlayers) + 1;
    guessGame(target, nextPlayer, totalPlayers);
}

int main()
{
    srand(time(0));
    int target = rand() % 100 + 1;
    int totalPlayers;

    cout << "Enter number of players: ";
    cin >> totalPlayers;

    cout << "\n--- Number Guessing Game ---\n";
    cout << "A number between 1 and 100 has been generated.\n";
    cout << "Players will take turns to guess!\n\n";

    guessGame(target, 1, totalPlayers);

    return 0;
}
