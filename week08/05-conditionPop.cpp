/*
    A letter means push and an asterisk means pop in the following sequence.  Give the sequence of values
    returned by the pop operations (display top data in queue then delete it) when this sequence of operations
    is performed on an initially empty LIFO stack.
    E A S * Y * Q U E * * * S T * * * I O * N * * *
*/
#include <iostream>
struct Txt
{
    char _c;
    Txt *next;
};
struct Stack
{
    Txt *top;
    int n;
};
void push(char ch, Stack *s)
{
    Txt *txt = new Txt{ch, s->top};
    s->top = txt;
    s->n++;
}
void pop(Stack *s)
{
    if (s->n == 0)
    {
        std::cout << "[!] Empty stack";
        return;
    }
    Txt *txt = s->top;
    s->top = s->top->next;
    std::cout  << txt->_c ;
    delete txt;
    s->n--;
}
void rev(Stack *s)
{
    if (s->n < 1)
        return;
    Txt *prev = nullptr, *current = s->top, *next = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    s->top = prev;
}
void show(Stack *s)
{
    Txt *txt = s->top;
    while (txt != nullptr)
    {
        std::cout << txt->_c;
        txt = txt->next;
    }
}
int main()
{
    Stack *stk = new Stack{nullptr, 0};
    std::string prmpt = "EAS*Y*QUE***ST***IO*N***";
    for (char c : prmpt)
    {
        if (c == '*')
        {
            pop(stk);
            continue;
        }
        push(c, stk);
    }
    rev(stk);
    std::cout << "\n[=] result: ";
    show(stk);
}