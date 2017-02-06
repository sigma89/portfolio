#include <iostream>

using namespace std;

int main()
{
    int turn = 1, input, sticks = 11, a = 0;

    cout << "WELCOME TO NIM!" << endl << endl;
    cout << "Two players will take turns removing 1, 2, or 3 sticks from the initial 11. The player that removes the final stick wins!" << endl << endl;

    do
    {
         turn++;

         cout << "Player " << (turn % 2) + 1 << ", it's your turn.";
         cout << "The game currently looks like this:" << endl << endl;

         do
         {
             cout << "| ";
             a++;
         }  while (a < sticks);

         a = 0;

         cout << endl << "How many sticks would you like to remove, Player " << (turn % 2) + 1 << "? (1, 2, or 3)";
         cin >> input;

         while (input < 1 || input > 3)
         {
            cout << "Error: illegal move. Please enter a valid number of sticks to remove (1, 2, or 3).";
            cin >> input;
         }

         sticks -= input;

    }   while(sticks > 0);

    cout << "\n\nCongratulations, Player " << (turn % 2) + 1 << "! You won!" << endl << endl;




    return 0;
}
