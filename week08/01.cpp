#include <iostream>

using namespace std;

struct Element
{
    int data;
    Element *next;
};

struct Stack
{
    int n;
    Element *top;
};

Stack* initStack() {
    Stack *s = new Stack;
    s->n=0;
    s->n=nullptr;
    return s;
}


