/* Define a data structure that can store unlimited data of students.  
+ Each student has ID, name, year and program degree.
+ Create an element for student then a list that contains head, tail and 
pointer. */
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