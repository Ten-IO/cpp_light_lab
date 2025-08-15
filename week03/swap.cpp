/*
    [+] Swap function
        - swap with pointer 
*/
#include <iostream>
using namespace std;
// Cool method with Not OR
void swapXOR(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

// Make copies but use a and b which are simply copy. We did not touch the address
void swapPtr(int *a, int *b)
{
    a = b;
    b = a;
}
// Cool method with summation
void swapSum(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main()
{
    int a = 1, b = 2;
    std::cout << a << ' ' << b << '\n';
    swapXOR(&a, &b);
    std::cout << "1- " << a << ' ' << b << '\n';
    swapPtr(&a, &b);
    std::cout << "2- " << a << ' ' << b << '\n';
    swapSum(&a, &b);
    std::cout << "3- " << a << ' ' << b;
}