#include <iostream>

using namespace std;

struct Element{
    char data;
    Element *next;
};

struct Stack
{
    int n;
    Element *top;
};

Stack *createStack(){
    Stack *s = new Stack;
    s->n=0;
    s->top=nullptr;
    return s;
}
char peek(Stack *s) {
    return (!s||s->top==nullptr)?'\0':s->data;
}

void push(Stack* s, char data) {
    Element *e = new Element;
    e->data=data;
    e->next = s->top;
    s->top=e;
    s->n++;
}

char pop(Stack* s){
    if(s->n==0)return;
    Element *e= s->top;
    char data = e->data;
    s->n--;
    delete e;
    return data;
}
bool isPair(char left, char right){
    return (left=='('&&right==')'||left=='['|| right==']'|| left=='{'&& right=='}');
}

bool isBalanced(Stack* s, string txt) {
    for (char c: txt) {
        if(c=='('||c=='['||c=='{')
        push(s,c);
        else if(c==')'||c==']'||c=='}')
        {
            if (s->top==nullptr || !isPair(peek(s),c)){
                delete s;

            }
            
    }
}
}

int main() {
    string txt;
    cout << "enter text: ";
    cin >> text;
    Stack *s = createStack;
    if(isBalanced(s,text)){
        cout << "is balanced\n";
    }
    else {
        cout << "not balanced\n";
    }
}