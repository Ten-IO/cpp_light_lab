/*
    [+] Using the doubly linked list from problem above.
        - Get a number n from a user.
        - Generate n random numbers and store in the list.
        - Display the list.
        - Compute summation and average of all numbers in the list then display the result on screen.
*/

/* Important: Comment main of 01.cpp or rewrite the implementation */
#include <iostream>
#include <cstdlib>
#include "01-simpleDoubly.h"
int sum(ListLinked *ls)
{
    Element *e = ls->head;
    Element *o = ls->tail;
    int total = 0;
    while (e != nullptr && o != nullptr)
    {
        if (e == o)
            return total += e->num;
        else if (e->next == o || o->prev == e)
            return total += e->num + o->num;
        total += e->num + o->num;
        e = e->next;
        o = o->prev;
    }
    return total;
}
float avg(ListLinked *ls)
{
    return sum(ls) / ls->n;
}
int main()
{
    ListLinked *ls = initList();
    for (int i = 0; i < 3; i++)
        addBeg(ls, rand()%50);
    for (int i = 3; i < 6; i++)
        addEnd(ls, rand()%50);
    showFront(ls);
    std::cout << "\n[+] Summary: total=" << sum(ls) << "; avg=" << avg(ls);
    return 0;
}