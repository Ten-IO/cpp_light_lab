/*
    [+] Create an element structure and a list structure that can store a list of integer numbers. Create 4 functions to
        i) Create an empty list
        ii) Add a number to begin of list
        iii) Add a number to end of list
        iv) Add a number to specific position in the list, and v) display list.
*/

/* Important: uncomment main to run */
#include <iostream>
#include "01-simpleDoubly.h"
ListLinked *initList()
{
    ListLinked *ls = new ListLinked();
    ls->n = 0;
    ls->head = nullptr;
    ls->tail = nullptr;
    return ls;
}
void addBeg(ListLinked *ls, int num)
{
    Element *e = new Element;
    e->num = num;
    e->next = ls->head;
    e->prev = nullptr;
    if (ls->n == 0)
        ls->tail = e;
    else
        ls->head->prev = e;
    ls->head = e;
    ls->n++;
}
void addEnd(ListLinked *ls, int num)
{
    Element *e = new Element();
    e->num = num;
    e->next = nullptr;
    e->prev = ls->tail;
    if (ls->n == 0)
        ls->tail = e;
    else
        ls->tail->next = e;
    ls->tail = e;
    ls->n++;
}
void addPos(ListLinked *ls, int num, int pos)
{
    if (pos < 0 || pos > ls->n)
        return;
    if (pos == 0)
    {
        addBeg(ls, num);
        return;
    }
    if (pos == ls->n)
    {
        addEnd(ls, num);
        return;
    }
    Element *current = ls->head;
    for (int i = 0; i < pos - 1; i++)
        current = current->next;
    Element *e = new Element;
    e->num = num;
    e->prev = current;
    e->next = current->next;

    current->next->prev = e;
    current->next = e;
    ls->n++;
}
void showFront(ListLinked *ls)
{
    Element *e = ls->head;
    while (e != nullptr)
    {
        std::cout << e->num << " ";
        e = e->next;
    }
}
// int main()
// {
//     ListLinked *ls = initList();
//     int n[] = {4, 7, 1, 0, 9, 4};
//     for (int i=0;i<3;i++)addBeg(ls,n[i]);
//     for (int i=3;i<6;i++)addEnd(ls,n[i]);
//     showFront(ls);
//     return 0;
// }