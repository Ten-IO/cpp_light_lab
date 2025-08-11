/*
Create 2 functions such as:
- create an empty list, and add student to list.
In the main program, call to these functions and add 5 students of your classmate that
you like the most.
*/

#include <iostream>
#include "02-StudentList.cpp"
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

// int main()
// {
//     ListStudent *ls = createEmptyList();
//     Student s = {"p02", "Tuy", "SE", 2}, _s = {"o21", "Lane","GTR", 4}, __s = {"q10","Bale", "LN", 1};
//     add(s, ls);
//     add(_s, ls);
//     add(__s, ls);
//     add(Student{"e01", "An", "CS", 5}, ls);
//     add(Student{"z31", "Set", "CS", 2}, ls);
//     Element *e = ls->head;
//     while (e != nullptr)
//     {
//         std::cout << "Student: " << e->data.id << " - " << e->data.name << '\n';
//         std::cout << "Program: " << e->data.program << " of " << e->data.yr << " year.\n\n";
//         e = e->next;
//     }
// }
// add(Student("p04", "Modro", "CS", 2)); // this one is wrong, default initialization using curly braces