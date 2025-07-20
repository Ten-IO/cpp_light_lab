#include <iostream>
using namespace std;

struct Element
{
    int data;
    Element *next;
};
struct List
{
    int n;
    Element *head;
    Element *tail;
};
List *createList();
void link_begin(List *, int);
void link_end(List *, int);
void link_pos(List *, int, int);

int main()
{
    Element e1, e2;
    e1.data = 21;
    cout << "data: " << e1.data << endl;
    cout << "ptr next: " << &e1.next << endl;
    cout << "data: " << e2.data << endl;
    cout << "ptr next: " << e2.next << endl;

    List *ls = createList();
    cout << "== List ==\n";
    cout << ls;
    return 0;
}

void link_begin(List *ls, int data)
{
    Element *e = new Element;
    e->data = data;
    e->next = ls->head;
    ls->head = e;

    if (ls->n == 0)
        ls->tail = e;
    ls->n++;
}
void link_end(List *ls, int data)
{
    Element *e = new Element;
    e->data = data;
    e->next = nullptr;
    if (ls->n == 0)
        ls->head = e;
    else
        ls->tail->next = e;
    ls->tail = e;
    ls->n++;
}
void link_pos(List *ls, int data, int pos)
{
    if (pos < 0 || pos >= ls->n)
    {
        cout << "Position cannot be add\n";
        return;
    }
    Element *current = ls->head;
    for (int i = 0; i < pos; i++)
        current = current->next;
    Element *e = new Element;
    e->data = data;
    e->next = current->next;
    current->next = e;
    if (current == ls->tail)
        ls->tail = e;
    ls->n++;
}


List *createList()
{
    List *ls = new List;
    ls->n = 0;
    ls->head = nullptr;
    ls->tail = nullptr;
    return ls;
}