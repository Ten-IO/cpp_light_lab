#include <iostream>
using namespace std;

struct numList
{
    int numDT;
    numList *next;
};
struct LinkedList
{
    numList *head, *tail;
    int n;
};
LinkedList *empty_list()
{
    LinkedList *ls = new LinkedList;
    ls->head = nullptr;
    ls->tail = nullptr;
    ls->n = 0;
    return ls;
}
void add_end(LinkedList *ls, int data)
{
    numList *e = new numList;
    e->numDT = data;
    e->next = nullptr;

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
        result += e->numDT;
        cout<< " "<< e->numDT;
        e = e->next;
    }
    return result;
}
int main()
{
    LinkedList *ls = empty_list();
    int num, count = 0;

    cout << ">> Summation Linked List <<\n";
    while (true)
    {
        cout << "Enter a number: ";
        cin >> num;
        add_end(ls, num);
        if (num == 0)
        {
            count++;
            if (count == 1)
                cout << "! Another 0 to quit the program.\n";
            if (count == 2)
                break;
        }
        else
            count = 0;
    }
    cout << "\n! Program stop ...\n";
    int x=sumList(ls);
    cout<< "\n+ result: "<<x;
}