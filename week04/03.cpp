#include <iostream>
#include <02_dsStudent.h>
#include "04.cpp"
using namespace std;

ListStudent *createEmptyList()
{
    ListStudent *ls = new ListStudent();
    ls->n = 0;
    ls->head = nullptr;
    ls->tail = nullptr;

    return ls;
}

void add(Student s, ListStudent *ls)
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

int main()
{
    ListStudent *ls = createEmptyList();
    Student s = {"p02", "Tuy", "SE", 2};
    add(s, ls);
    add(Student{"e01", "An", "CS", 2},ls);
    display(ls);
    // add(Student("p04", "Modro", "AIECS", 2)); // this one is wrong, default input constructor for structure using curly braces
    // add(Student("p53", "Uohp", "SE", 2));
    // add(Student("p44", "Yet", "CS", 2));
}