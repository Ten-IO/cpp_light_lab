/*
    Fibonacci sequence, consider index[0] where fibonacci number = 0
    sample: 0,1,1,3,5,8,13
*/
#include <iostream>

int fibonacci(int n)
{
    if (n <= 1)
    {
        if (n < 1)
            return 0;
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main(int argc, char **argv)
{
    std::cout << "== Fibonacci ==\n";
    if (argc == 2)
    {
        std::cout << fibonacci(atoi(argv[1]));
        return 0;
    }
    std::cout << fibonacci(4);
    return 0;
}