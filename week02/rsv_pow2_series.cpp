#include <iostream>
#include <cstdlib>
using namespace std;

int sumPow2(int n)
{
    if (n > 0)

        return n * n + sumPow2(n - 1);
    else
        return 0;
}

int main(int argc, char *argv[])
{
    char *p;
    long num = strtoi(argv[1]);
    errno = 0;

    if (errno == ERANGE || *p != '\0' || num > INT_MAX || num < INT_MIN)
    {
        cout << "Error: out of int range or invalid input\n";
        return 1;
    }
    else
    {
        cout << "Your output: " << sumPow2((int)num);
    }
}