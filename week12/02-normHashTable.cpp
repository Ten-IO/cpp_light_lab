/*
(No collision)
    [+] Create a hash table to store 4 integer numbers. This hash table uses a hash function to
        compute the index using the operation data % size of array, assume that the size of array is 7.
        Write 4 functions to :
            ▪ Insert a number to the hash table.
            ▪ Display all data in hash table. Each data should be displayed with its index
            ▪ Search whether a number is contained in the hash table. If the number is contained in the hash table,
                then display a message “It is contained in position positionNumber” and return true. Otherwise,
                display “Not found” and return false.
            ▪ Remove a number from the hash table. If the number is contained in the hash table, then remove it by
                setting a default value (e.g: for array of integer, the default value for each element can be 0). Finally,
                display a message “removed success. Otherwise (if not contained), display “failed to delete as it does
            not exist”.
        In main program, add the numbers of 2, 4, 7, 10. Search for the number 7 by calling the search function. Then
        remove the number 10 using the remove function. Finally, display all data in the hash table.
    [!] Hint: The hash value returning from the hash function is the index of the number in the hash table.
*/
#include <iostream>
const int size = 5;
int ht[size];
int hash(int val)
{
    return val%size;
}
void insert(int val)
{
    int index = hash(val);
    ht[index] = val;
}
void show()
{
    std::cout << "Index\t->\tvalue\n";
    for (int i = 0; i < size; i++)
        std::cout << i << "\t->\t"<< ht[i] << '\n';
}
bool search(int val)
{
    int index = hash(val);
    if (ht[index] = val)
    {
        std::cout <<"[=] Found "<<  val << " in position [" << index << "]\n";
        return true;
    }
    std::cout << "[!] Not found\n";
    return false;
}
void pop(int val)
{
    int index = hash(val);
    if (ht[index] == val)
    {
        ht[index] = 0;
        std::cout<< "[-] " << val << " is removed from [" << index << "]\n";
    }else
    std::cout << "[!] Value not exist, Fail to delete " << val << '\n';
}
int main()
{
    int num[]= {2,4,7,10};
    for (int i:num)
    insert(i);
    show();
    search(7);
    pop(10);
    show();
}