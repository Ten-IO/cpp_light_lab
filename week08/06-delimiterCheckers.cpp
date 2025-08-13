/*
    Write a program that reads a piece of delimiter symbols containing parentheses, braces and/or curly braces.
    The program determines whether its parentheses, braces, and curly braces are "balanced".  The program can be done using stack data structure.
    Hint:  Process each character of the input.
        • When a character is left delimiter, push it to stack.
        • When a character is right delimiter, pop data from stack and check whether popped element matches right delimiter.
        • It is balance when all matching are true and stack is empty when all characters have been processed.
*/
#include <iostream>

using namespace std;

struct Element
{
    char data;
    Element *next;
};

struct Stack
{
    int n;
    Element *top;
};

Stack *createStack()
{
    return new Stack{0, nullptr};
}
char peek(Stack *s)
{
    return (!s || s->top == nullptr) ? '\0' : s->top->data;
}
void push(Stack *s, char data)
{
    Element *e = new Element{data, s->top};
    s->top = e;
    s->n++;
}
char pop(Stack *s)
{
    if (s->n == 0)
        return '\0';
    Element *e = s->top;
    char data = e->data;
    s->top = s->top->next;
    s->n--;
    delete e;
    return data;
}
bool isPair(char left, char right)
{
    return (left == '(' && right == ')') || (left == '[' && right == ']') || (left == '{' && right == '}');
}

bool isBalanced(Stack *s, string txt)
{
    for (char c : txt)
    {
        if (c == '(' || c == '[' || c == '{')
            push(s, c);
        else if (c == ')' || c == ']' || c == '}')
        {
            if (s->top == nullptr || !isPair(peek(s), c))
                return false;
                pop(s);
        }
    }
    return s->top == nullptr;
}

int main()
{
    Stack *stk = createStack();
    string txt;
    cout << "enter text: ";
    cin >> txt;
    if(isBalanced(stk,txt))
    cout << "is balanced\n";
    else cout << "not balanced\n";
    delete stk;
    return 0;
}