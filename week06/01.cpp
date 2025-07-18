#include <iostream>
using namespace std;
struct Alphabet{
    char lo, up;
    Alphabet* next;
};

struct List{
    int n;
    Alphabet* head;
    Alphabet* tail;
};

List* emptyList(){
    List* ls = new List();
    ls->head = nullptr;
    ls->tail = nullptr;
    ls->n=0;
    return ls;
}

void end_add(List* ls, char alphaLo, char alphaUp) {
    Alphabet* e = new Alphabet();

    e->lo = alphaLo;
    e->up = alphaUp;
    e->next = nullptr;

    if(ls->n==0)
    ls->head = e;
    else 
    ls->tail->next=e;

    ls->tail=e;
    ls->n++;


}

void display(List *ls) {
    Alphabet *e = ls->head;
    int i=0;
    while(e!=nullptr){
        cout<< ++i << ". "<<e->lo <<" "<< e->up<<endl;
        e = e->next;
    } 
}

int main() {
    List* ls = emptyList();

    end_add(ls, 'a', 'A');
    end_add(ls, 'g', 'G');
    end_add(ls, 'f', 'F');

    display(ls);
}