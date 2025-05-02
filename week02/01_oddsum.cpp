#include <iostream>
#include <string>
using namespace std;

int Odd_sum(int n)
{
    if (n <= 0)
        return 0;
    if (n % 2 == 0)
        return Odd_sum(n - 1);
    return n + Odd_sum(n - 2);
}
int main(int argc, char **argv)
{

    try
    {
        int n = stoi(argv[1]);
        cout << "odd result: " << Odd_sum(n);
    }
    catch (const invalid_argument &e)
    {
        cerr << "Invalid: not a number\n";
    }
    catch (const out_of_range &e)
    {
        cerr << "Number: out of range\n";
    }
}