// Write a C++ program to find the summation of numbers from 1 to n except number 10 and 30, 
// where n is a number input by a user and n should be greater than 50.

#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cout << "-- Unique Series !(10 || 30) --\n";
    cout << "Enter a number greater than 50: ";
    cin >> n;

    if(n <= 50) {
        cout << "Number must be greater than 50.\n";
        return 1;
    }

    for(int i = 1; i <= n; ++i) {
        if(i == 10 || i == 30) continue;
        sum += i;
    }

    cout << "The summation is: " << sum << endl;
    return 0;
}
