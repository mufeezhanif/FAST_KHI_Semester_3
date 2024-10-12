#include <bits/stdc++.h>

using namespace std;

string guessNumber(int n)
{
    int guess;
    cout << "Enter your guess Mr player 1:";
    cin >> guess;
    if (n == guess)
        return "Player 1";
    else if (guess > n)
        cout << "Your guess was too high" << endl;
    else
        cout << "Your guess was too low" << endl;
    cout << "Enter your guess Mr player 2:";
    cin >> guess;
    if (n == guess)
        return "Player 2";
    else if (guess > n)
        cout << "Your guess was too high" << endl;
    else
        cout << "Your guess was too low" << endl;
    return guessNumber(n);
}
int main()
{
    srand(static_cast<unsigned>(time(0)));
    int n = rand() % 100 + 1;
    cout << n << endl;
    cout << guessNumber(n) << " won the game";
    return 0;
}