#include <iostream>
using namespace std;

void displayStar(int n)
{
    if (n <= 0)
        return;
    if (n % 5 == 0)
        cout << endl;
    cout << "*";
    displayStar(n - 1);
}
void displayNumbers(int n)
{
    if (n <= 0)
        return;
    if (n % 5 == 0)
        cout << endl;
    cout << n << " ";
    displayNumbers(n - 1);
}

int main()
{
    int choice, n;
    while (!cin.fail())
    {
        cout << "\n1. display n star *\n2. display numbers from n -> 1\n>> ";
        cin >> choice;
        cout << "n: ";
        cin >> n;
        cout << "result:\n";
        switch (choice)
        {
        case 1:
            displayStar(n);
            break;
        case 2:
            displayNumbers(n);
            break;
        default:
            break;
        }
    }
}