#include <iostream>
#include <conio.h>

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

Stack *createStack()
{
    Stack *s = new Stack;
    s->top = nullptr;
    s->n = 0;
    return s;
}

void push(Stack *s, int data) {
    Element *e = new Element;
    e->data=data;
    e->next=s->top;
    s->top=e;
    s->n++;
}
int pop(Stack *s)
{
    if (s->n == 0)
    {
        return 1;
    }

    Element *tmp = s->top;
    s->top = tmp->next;
    s->n--;
    int value = tmp->data;
    delete tmp;
    return value;
}

void display(Stack *s)
{
    Element *e = s->top;
    while (e != nullptr)
    {
        cout << e->data << " ";
        e= e->next;
    }
    cout << endl;
}

int main()
{
    Stack *s = createStack();
    // push (s, "a");
    push (s, 1);
    push(s, 'a');
    display(s);
}
