/*
    [+] Create a singly linked list to manage tasks. 
        a. Define a singly linked list to stores a task (description, priority level: 1-5) 
        b. Implement:  
            i.   add tasks to the end of the list 
            ii.  display all tasks info in the list 
            iii. delete the oldest task in the list (the beginning of the list) 
*/
#include <iostream>
enum PRIOR{LOW, MEDIUM, HIGH, URGENT, CRITICAL};
struct Task{std::string desc; PRIOR lvl; Task *next;};
struct List{Task *head, *tail; int n;};
void add(Task _t, List *ls){
    Task *t = new Task{_t.desc, _t.lvl, nullptr};
    if(ls->n==0)
    ls->head = t;
    else 
    ls->tail->next = t;
    ls->tail = t;
    ls->n++;
}
void show(List *ls){
    Task *t = ls->head;
    while(t!=nullptr){
        std::cout << "Task: [" << t->lvl << "] :"<< t->desc<<'\n';
        t= t->next;
    }
}
void popTask(List *ls){
    if(ls->n==0)return;
    if(ls->n==1){
        delete ls->head;
        ls->head =ls->tail=  nullptr;
    }else{
        Task *t = ls->head->next;
        delete ls->head;
        ls->head=t;
    }
    ls->n--;
}
int main(){
    List *ls = new List{nullptr,nullptr,0};
    std::cout << "[+] Show task\n";
    Task _task[] = {{"Go to sleep", (PRIOR)1}, {"Eat dinner",PRIOR::HIGH}, {"Find your life", static_cast<PRIOR>(5)}};
    for (int i=2;i>=0;i--) add(_task[i],ls);
    show(ls);
    std::cout << "[+] Pop task\n";
    popTask(ls);
    show(ls);
}