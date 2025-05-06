#include <iostream>
using namespace std;
int main()
{
    int n, *ptr = &n;
    cout << "-- Ref Change with PTR --\n> Input: ";
    cin >> n;
    *ptr +=7;
    cout << "pointer update: " << *ptr;
}