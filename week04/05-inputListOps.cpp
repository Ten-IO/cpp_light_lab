/*
    [+] Write a program that can store numbers as many as possible using linked list data structure.
        + Ask user for a number at a time then add to the list. Keep asking the user for another
        number and add to the list if the input number is not 0.
            a. When the user inputs 0 twice, display all data in the list and stop the program.
            b. Finally, compute the summation of all data in the list and show the result.
*/

#include <iostream>
using namespace std;

struct numList
{
    int num;
    numList *next;
};
struct LinkedList
{
    numList *head, *tail;
    int n;
};
LinkedList *empty_list()
{
    return new LinkedList{nullptr, nullptr, 0};
}
void add_end(LinkedList *ls, int data)
{
    numList *e = new numList{data, nullptr};
    if (ls->n == 0)
        ls->head = e;
    else
        ls->tail->next = e;
    ls->tail = e;
    ls->n++;
}
int sumList(LinkedList *ls)
{
    numList *e = ls->head;
    int result = 0;
    cout << "\n+ List from input:";
    while (e != nullptr)
    {
        result += e->num;
        cout << " " << e->num;
        e = e->next;
    }
    return result;
}
int main()
{
    LinkedList *ls = empty_list();
    int num, count = 0;

    cout << "== Summation Linked List ==\n";
    cout << "[+] 0 twice to exit\n\n";
    while (true)
    {
        cout << "Enter a number: ";
        cin >> num;
        if (num == 0)
        {
            count++;
            if (count == 1)
            {
                cout << "\n! Another 0 to quit the program.\n";
                continue;
            }
            if (count > 1)
                break;
        }
        else
            count = 0;
        add_end(ls, num);
    }
    cout << "\n! Program stop ...\n";
    int x = sumList(ls);
    cout << "\n+ result: " << x;
}