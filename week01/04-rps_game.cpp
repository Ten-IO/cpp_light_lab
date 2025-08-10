/*
    [+] Create a C++ program that can play a game Rock-Paper-Scissor. User against the computer.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int userChoice, compChoice;
    string choices[] = {"Rock", "Paper", "Scissors"};

    cout << "-- Rock Paper Scissors Game! --\n";
    cout << "Enter your choice:\n";
    cout << "0: Rock\n1: Paper\n2: Scissors\n>> ";
    cin >> userChoice;

    if(userChoice < 0 || userChoice > 2) {
        cout << "Invalid choice.\n";
        return 1;
    }

    compChoice = rand() % 3;

    cout << "You chose: " << choices[userChoice] << endl;
    cout << "Computer chose: " << choices[compChoice] << endl;

    if(userChoice == compChoice) {
        cout << "It's a Tie!\n";
    } else if((userChoice == 0 && compChoice == 2) || 
              (userChoice == 1 && compChoice == 0) ||
              (userChoice == 2 && compChoice == 1)) {
        cout << "You Win!\n";
    } else {
        cout << "You Lose!\n";
    }

    return 0;
}
