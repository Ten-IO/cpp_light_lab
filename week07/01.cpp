#include <iostream>
using namespace std;

struct Element
{
    int num;
    Element *next, *prev;
};
struct ListLinked
{
    int n;
    Element *head, *tail;
};

ListLinked *initList()
{
    ListLinked *ls = new ListLinked();
    ls->n = 0;
    ls->head = nullptr;
    ls->tail = nullptr;

    return ls;
}

void addBeg(ListLinked* ls, int num){
    Element* e = new Element;
    e->num=num;
    e->next=ls->head;
    e->prev=nullptr;

    if(ls->n==0)
    ls->tail=e;
    else ls->head->prev=e;
    ls->head=e;
    ls->n++;
}

void addEnd(ListLinked* ls, int num){
    Element* e=new Element();
    e->num=num;
    e->next=ls->head;
    e->prev=nullptr;

    if(ls->n==0)
    ls->tail=e;
    

}


int main()
{
}