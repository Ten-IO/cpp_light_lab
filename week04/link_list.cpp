#include <iostream>
#include <02_dsStudent.h>

using namespace std;
void link_begin(List* ls, int data) {
    Element* e = new Element;
    e-> data= data;
    e-> next = ls-> head;
    ls-> head = e;

    if(ls-> n==0)
    ls-> tail=e;
    ls-> n++;
}
void link_end(List *ls, int data)
{
    Element *e = new Element;
    e->data = data;
    e->next = nullptr;
    if (ls->n == 0)
        ls->head = e;
    else
        ls - tail->next = e;
}
void link_pos(List *ls, int data, int pos)
{
    if (pos < 0 || pos >= ls->n)
    {
        cout << "Position cannot be add\n";
        return;
    }
    Element *current = ls->head;
}
struct Element
{
    int data;
    Element *next;
    Element *prev;
};
struct List
{
    int n;
    Element *head;
    Element *tail;
};
int main()
{
    Element e1, e2;
    e1.data = 21;
    cout << "data: " << e1.data << endl;
    cout << "ptr next: " << &e1.next << endl;
    cout << "ptr prev: " << &e1.prev << endl;
    cout << "data: " << e2.data << endl;
    cout << "ptr next: " << e2.next << endl;
    cout << "ptr prev: " << e2.prev << endl;
}