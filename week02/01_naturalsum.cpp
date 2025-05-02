#include <iostream>

int sumSquare(int n)
{
    if (n <= 0)
        return 0;

    return n + sumSquare(n - 1);s
}

int main()
{
    std::cout << sumSquare(3);
}