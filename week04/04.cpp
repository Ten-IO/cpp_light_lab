/*
Create display function for data from 02 and 03. 
+ Then add 2 more students to list.
*/
#include <iostream>
#include <02_dsStudent.h>
void display(ListStudent *ls)
{
    Element *info;
    info = ls->head;
    int i = 0;

    while (info != nullptr)
    {
        std::cout << ++i << ". name: " << info->data.name << " id: " << info->data.id << " program-year: " << info->data.program << " - " << info->data.yr << std::endl;
        info = info->next;
    }
}