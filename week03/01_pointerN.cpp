#include <iostream>
using namespace std;
int main()
{
    int n1 = 7, n2 = 3, n3 = 15;
    int *p1 = &n1, *p2 = &n2, *p3 = &n3;

    cout << "-- init --\n"
         << p1 << ": " << *p1 << endl;
    cout << p2 << ": " << *p2 << endl;
    cout << p3 << ": " << *p3 << endl;

    *p3 = n1 + n2;
    cout << "-- Val update --\n"
         << p3 << ": " << *p3;
}