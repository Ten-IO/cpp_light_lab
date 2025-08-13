/*
    Write a C++ program to implement a stack data structure using a singly linked list to store integer numbers
    with the following operations: push(), pop(), peek(), isEmpty(), and function to count and return the
    number of elements in the stack, and display function to print all elements in the stack from top to bottom.
*/
#include <iostream>
struct NUMBER
{
    int num;
    NUMBER *next;
};
struct Stack
{
    NUMBER *top;
    int n;
};
void push(int _num, Stack *stk)
{
    NUMBER *num = new NUMBER{_num, stk->top};
    stk->top = num;
    stk->n++;
}
int pop(Stack *stk)
{
    if (stk->top == nullptr)
    {
        std::cout << "[!] Empty stack\n";
        return -1;
    }
    NUMBER *num = stk->top;
    stk->top = stk->top->next;
    int data = num->num;
    delete num;
    stk->n--;
    return data;
}
void peek(Stack *stk)
{
    if (stk->top == nullptr)
    {
        std::cout << "[!] Empty stack\n";
        return;
    }
    std::cout << "\n[+] Peek on: " << stk->top->num << '\n';
}
bool isEmpty(Stack *stk)
{
    return stk->n == 0;
}
int getCount(Stack *stk)
{
    return stk->n;
}
void show(Stack *stk)
{
    if (isEmpty(stk))
    {
        std::cout << "[!] Empty stack\n";
        return;
    }
    std::cout << "[+] Top-bottom: ";
    NUMBER *num = stk->top;
    while (num != nullptr)
    {
        std::cout << num->num << " ";
        num = num->next;
    }
}
int main()
{
    Stack *stk = new Stack{nullptr, 0};
    int num[] = {3, 1, 2, 4};
    for (int i : num)
        push(i, stk);
    show(stk);
    pop(stk);
    std::cout << "\n== After pop ==";
    peek(stk);
    if (isEmpty(stk))
        std::cout << "[!] Stack Empty\n";
    std::cout << "[+] Current Elements: " << getCount(stk) << '\n';
    show(stk);
}
