/*
   [+] Q2. Write a recursive function to generate the Fibonacci sequence up to n
*/
#include <iostream>
int main(int argc, char **argv)
{
    if (argc > 2)
        return 1;
    int n = std::stoi(argv[1]), x = 0, y = 1;
    while (n > 0)
    {
        int tmp = x + y;
        x = y;
        y = tmp;
        n--;
    }
    std::cout << "Result: " << x;
    return 0;
}