#include <iostream>
using namespace std;
int main()
{
    int a = 1, b = 2;
    int *ptr[] = {&a, &b, &a, &a};

    cout << ptr[0] << " :"<< *ptr[0] << endl;
    cout << ptr[1] <<  " :"<< *ptr[1] << endl;
    cout << ptr[2] <<  " :"<< *ptr[2] << endl;
    cout << sizeof(ptr) / sizeof(ptr[0]) << " " << *ptr << endl;
}