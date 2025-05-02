#include <iostream>

int controlSum()
{
    int n = 0;
    std::cin >> n;
    if (n == -1)
    {
        std::cout << "total: ";
        return 0;
    }
    return n + controlSum();
}
int main()
{
    {
        std::cout << "enter number (-1 to exit):\n"
                  << controlSum();
    }
}