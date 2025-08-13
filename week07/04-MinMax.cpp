/*
    Using the doubly linked list from problem above.
        a. Give the minimum number in the list,
        b. Give the maximum number in the list.
*/
#include <iostream>
#include "01-simpleDoubly.h"
int min(ListLinked *ls)
{
    Element *e = ls->head;
    int min = ls->head->num;
    while (e != nullptr)
    {
        if (e->num < min)
            min = e->num;
        e = e->next;
    }
    return min;
}
int max(ListLinked *ls)
{
    Element *e = ls->head;
    int max = ls->head->num;
    while (e != nullptr)
    {
        if (e->num > max)
            max = e->num;
        e = e->next;
    }
    return max;
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
    std::cout << "\n[!] Minimize: " << min(ls) << " Maximize: " << max(ls);
    return 0;
}