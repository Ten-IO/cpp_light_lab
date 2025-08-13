/*
    [+] Using the doubly linked list from problem above. Create functions to delete the element from the list:
        (1) delete one element from beginning
        (2) delete one element from the end of the list
        (3) delete one element at the position. Display all data in the list.
*/
#include <iostream>
#include "01-simpleDoubly.h"
void popBegin(ListLinked *ls)
{
    if (ls->n == 0)
        return;
    Element *tmp = ls->head;
    ls->head = tmp->next;
    if (ls->head != nullptr)
        ls->head->prev = nullptr;
    else
        ls->tail = nullptr;
    delete tmp;
    ls->n--;
}
void popEnd(ListLinked *ls)
{
    if (ls->n == 0)
        return;
    Element *tmp = ls->tail;
    ls->tail = tmp->prev;
    if (ls->tail != nullptr)
        ls->tail->next = nullptr;
    else
        ls->head = nullptr;
    delete tmp;
    ls->n--;
}
void popPosition(ListLinked *ls, int pos)
{
    if (pos < 0 || pos > ls->n - 1)
        return;
    if (pos == 0)
    {
        popBegin(ls);
        return;
    }
    if (pos == ls->n - 1)
    {
        popEnd(ls);
        return;
    }
    Element *current = ls->head;
    for (int i = 0; i < pos - 1; i++)
        current = current->next;
    Element *tmp = current->next;
    current->next = tmp->next;
    if (tmp->next != nullptr)
        tmp->next->prev = current;
    delete tmp;
    ls->n--;
}
int main()
{
    ListLinked *ls = initList();
    int n[] = {4, 7, 1, 0, 9, 2};
    for (int i = 0; i < 3; i++)
        addBeg(ls, n[i]);
    for (int i = 3; i < 6; i++)
        addEnd(ls, n[i]);
        std::cout << "[+] List:";
        showFront(ls);
        std::cout << "\n[+] Front pop List:";
        showFront(ls);
        popBegin(ls);
        std::cout << "\n[+] End pop List:";
        popEnd(ls);
        showFront(ls);
        std::cout << "\n[+] Position pop List:";
        popPosition(ls,2);
        showFront(ls);
    return 0;
}