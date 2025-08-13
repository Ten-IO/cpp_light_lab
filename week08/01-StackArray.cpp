/*
    Write a C++ program to implement a stack data structure using an array to store integer numbers.
    Write functions for: push(), pop(), peek(), isEmpty(), isFull(), displayStack().
*/
#include <iostream>
const int SIZE = 3;
int s[SIZE], top = -1;
bool isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}
bool isFull()
{
    if (top == SIZE - 1)
        return true;
    else
        return false;
}
void push(int data)
{
    if (isFull())
    {
        std::cout << "[!] Stack Overflow\n";
        return;
    }
    top += 1;
    s[top] = data;
    std::cout << data << " added\n";
}
int pop()
{
    if (isEmpty())
    {
        std::cout << "[!] Stack Underflow\n";
        return -1;
    }
    int data = s[top];
    s[top] = 0;
    top--;
    return data;
}
int peek()
{
    if (isEmpty())
    {
        std::cout << "[!] Stack is empty\n";
        return -1;
    }
    return s[top];
}
void displayStack()
{
    if (isEmpty())
        return;
    for (int i = top; i > -1; i--)
        std::cout << s[i] << " ";
}
int main()
{
    int num[] = {3,1,2,4};
    for (int i:num) push(i);
    std::cout << "[+] Stack: ";
    displayStack();
    std::cout << "\n[+] Top: "<<peek();
    std::cout << "\n[-] Pop: "<< pop();
    std::cout << "\nAfter Pop: ";displayStack();
}