/*
    [+] Q3. Write a C++ program using pointers to swap two numbers.
*/
#include <iostream>
void swap(int *a, int *b)
{
    int temp = *a ^ *b;
    *a = *a ^ temp;
    *b = *b ^ temp;
}
int main()
{
    int n1 = 2, n2 = 5;
    std::cout << "Origin: [a] " << n1 << " [b] " << n2 << std::endl;
    swap(&n1, &n2);
    std::cout << "Swap:   [a] " << n1 << " [b] " << n2;
    return 0;
}