/*
  [+] Q1. Write a recursive function to calculate the sum of digits of a number on argument input.
*/

#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
  for (int i = 0; i < argc; i++)
    return stoi(argv[i + 1]) + stoi(argv[i + 2]);
    std::cout << "Result: " << 
  return 0;
}