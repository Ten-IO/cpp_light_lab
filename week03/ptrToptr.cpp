#include <iostream>
using namespace std;

static int static_var = 0;
void someFunction()
{
    static_var++;
    printf("Value of static_var: %d\n", static_var);
}

int main()
{
    int a = 0;
    int *ptr = &a;
    int **masterPtr = &ptr;
    cout << "main: " << ptr << endl;
    cout << "&main: " << &ptr << endl;

    cout << "master&: " << &masterPtr << endl;
    cout << "master: " << masterPtr << endl;
    cout << "*master: " << *masterPtr << endl;
    cout << "**master: " << **masterPtr << endl;
    cout << endl
         << endl;
    int static_var = 0;
    someFunction();
    cout <<  static_var;
}