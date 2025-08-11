/*
Create display function for data from 02 and 03.
+ Then add 2 more students to list.
*/
#include <iostream>
#include "02-StudentList.cpp"

ListStudent *initEmpty()
{
    return new ListStudent{nullptr, nullptr, 0};
}

void addEnd(Student s, ListStudent *ls)
{
    Element *e = new Element;
    e->data = s;
    e->next = nullptr;
    if (ls->n == 0)
        ls->head = e;
    else
        ls->tail->next = e;
    ls->tail = e;
    ls->n++;
}
void addBegin(Student s, ListStudent *ls)
{
    Element *e = new Element;
    e->data = s;
    e->next = ls->head;
    ls->head = e;
    if (ls->n == 0)
        ls->tail = e;
}
void show(ListStudent *ls)
{
    Element *info;
    info = ls->head;
    int i = 0;

    while (info != nullptr)
    {
        std::cout << ++i << ". id: " << info->data.id << " - " << info->data.name << '\n';
        std::cout << "Program-year: " << info->data.program << " Y" << info->data.yr << '\n'<<std::endl;
        info = info->next;
    }
}

int main()
{
    ListStudent *ls = initEmpty();
    Student _s_1 = {"h01", "Na", "SE", 2}, _s_2 = {"h04", "Fu", "SE", 2};
    Student _s_3 = {"h03", "Li", "SE", 2}, _s_4 = {"h02", "Ni", "SE", 2}, _s_5 = {"h05", "Ka", "SE", 2};
    addEnd(_s_1, ls);
    addBegin(_s_2, ls);
    addEnd(_s_3, ls);
    addBegin(_s_4, ls);
    addEnd(_s_5, ls);
    addEnd(Student{"h06", "Set", "CS", 5}, ls);
    addEnd(Student{"h07", "Ro", "CS", 5}, ls);
    show(ls);
}