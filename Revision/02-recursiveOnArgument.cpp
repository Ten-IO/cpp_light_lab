/*
    [+] Q1. Write a recursive function to calculate the sum of digits of a number on argument input.
*/
#include <iostream>
using namespace std;

bool isNum(const string &s)
{
    if(s.empty())return false;
    for (char c : s)
        if (!isdigit(c))
            return false;
    return true;
}
int main(int argc, char **argv)
{
    int result = 0;
    if (argc < 2)
        cout << "There is only " << argc << " argument.\n";
    for (int i = 0; i < argc-1; i++)
        if (isNum(argv[i + 1]))
            result += stoi(argv[i + 1]);
    std::cout << "Result: " << result;
    return 0;
}