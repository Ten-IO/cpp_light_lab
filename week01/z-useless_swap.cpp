/* Passing like this means, copying value, modified only in function, does not affect otuside*/
#include <iostream>
void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = a;
}
void show(int a, int b)
{
    std::cout << "\na: " << a << ", b: " << b;
}

int main()
{
    int a = 1, b = 2;
    show(a, b);
    swap(a, b);
    show(a, b);
}