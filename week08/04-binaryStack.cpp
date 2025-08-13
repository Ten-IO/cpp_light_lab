/*
    Write a program to get a number from a user. Use stack to store that number as the binary number
    representation in the stack. Finally, display the binary representation from the stack.
    Hint:  Divide the integer by 2 then store the remainder in stack. Finally, display data in stack.
*/
#include <iostream>
struct Bin
{
    int n;
    Bin *next;
};
struct Stack
{
    Bin *top;
    int n;
};
void push(int _n, Stack *s)
{
    int bit;
    while (_n > 0)
    {
        bit = _n % 2;
        _n /= 2;
        Bin *bin = new Bin{bit, s->top};
        s->top = bin;
        s->n++;
    }
}
int pow(int _n, int _pow)
{
    if (_pow < 1)
        return 1;
    return _n * pow(_n, --_pow); 
}
void show(Stack *s)
{
    if (s->n == 0)
    {
        std::cout << "[+] Empty stack";
        return;
    }
    int dec=0, len = s->n;
    Bin *bin = s->top;
    while (bin != nullptr)
    {
        len--;
        if (bin->n != 0)
            dec += pow(2, len);
        bin = bin->next;
    }
    std::cout << "Binary form of " << dec << ": ";
    bin = s->top;
    while (bin != nullptr)
    {
        std::cout << bin->n;
        bin = bin->next;
    }
}
int main()
{
    Stack *stk = new Stack{NULL, 0};
    push(5, stk);
    show(stk);
}