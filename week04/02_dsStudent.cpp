#include <string>

struct Student{
    std::string id, name, program;
    int yr;
};

struct Element{
    Student *next, data;
};

struct ListStudent{
    Element *head, *tail;
    int n;
};