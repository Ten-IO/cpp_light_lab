#include <string>
#pragma once // guard redundant inclusion/redefine
struct Student{
    std::string id, name, program;
    int yr;
};

struct Element{
    Student data;
    Element *next;
};

struct ListStudent{
    Element *head, *tail;
    int n;
};