/*
    Write a program to ask a piece of text from a user. Display the text in a reverse order using stack.
    Hint: Push each character in the text into stack. Display stack.
*/
#include <iostream>
#include <conio.h>
struct Text
{
    char c;
    Text *next;
};
struct Stack
{
    Text *top;
    int n;
};
void push(Stack *stk, char _ch)
{
    Text *ch = new Text{_ch, stk->top};
    stk->top = ch;
    stk->n++;
}
void reverse(Stack *s)
{
    if (s->n < 1)
        return;
    Text *prev = nullptr;
    Text *current = s->top;
    Text *next = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    s->top = prev;
}
void show(Stack *stk)
{
    if (stk->n == 0)
    {
        std::cout << "[!] Stack empty\n";
        return;
    }
    Text *ch = stk->top;
    while (ch != nullptr)
    {
        std::cout << ch->c;
        ch = ch->next;
    }
}
int main()
{
    Stack *txt = new Stack{nullptr, 0};
    char _ch;
    std::cout << "Type your text: ";
    // not perfect, because did not handle backspace
    while (_ch != 13)
    {
        push(txt, _ch);
        _ch = _getch();
        std::cout << _ch;
    }
    std::cout << std::endl;
    std::cout << "\nCurrent text: ";
    show(txt);
    std::cout << "\nIn reverse: ";
    reverse(txt);
    show(txt);
}