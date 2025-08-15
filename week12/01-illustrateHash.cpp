/*
(No collision)
    [+] Consider a hash table data structure that has a simple hash function as “key mod 20”.
        We would like to insert these numbers 50, 700, 76, 85, 92, 73, 101, respectively into this hash table.
        Draw the hash table to see how your data is stored.
*/
#include <iostream>
#include <iomanip>
int ht[20];
int hashFunction(int val)
{
    return val % 20;
}
void insert(int val)
{
    int index = hashFunction(val);
    ht[index] = val;
}
int main()
{
    int num[] = {50, 700, 76, 85, 92, 73, 101};
    for (int i : num)
        insert(i);
    std::cout << "Index\n";
    for (int i = 0; i < 20; i++)
        std::cout << std::setw(5) << i << "   |";
    std::cout << "\nValue\n";
    for (int i : ht)
        std::cout << std::setw(5) << i << "   |";
    return 0;
}