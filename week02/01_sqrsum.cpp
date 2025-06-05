#include <iostream>

int sumSquare(int n)
{
    if (n <= 0)
        return 0;

    return n * n + sumSquare(n - 1);
}

int main()
{
    std::cout << sumSquare(3);
}