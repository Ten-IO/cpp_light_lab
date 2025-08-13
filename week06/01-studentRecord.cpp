/*
    [+] Create a singly linked list to manage student records.  
        a. Define a linked list to store student information such as id, name, score.  
        b. Implement the following functions and test the program: 
            i.   add the student info to the end of the list 
            ii.  display all student info from the list 
            iii. remove the last student from the list
*/
/* Node: a point of intersection and connection*/
#include <iostream>
struct Student
{
    int id;
    std::string name;
    float score;
};
struct Node
{
    Student student;
    Node *next;
};
struct List
{
    Node *head, *tail, *next;
    int n;
};

void addBack(Student s, List *ls)
{
    Node *node = new Node{s, nullptr};
    if (ls->n == 0)
        ls->head = node;
    else
        ls->tail->next = node;
    ls->tail = node;
    ls->n++;
}
void show(const List *ls){
    Node *node = ls->head;
    while(node!=nullptr){
        std::cout << "Student: ["<< node->student.id << "] "<< node->student.name << " : " <<node->student.score<< "pts.\n";
        node = node->next;
    }
}
void deleteBack(List *ls){
    if(ls->n==0) return;
    if(ls->n==1) {
        delete ls->tail;
        ls->head = ls->tail = nullptr;
    } else{
        Node *node = ls->head;
        while(node->next!=ls->tail)
        node=node->next;
        node->next = nullptr;
        delete ls->tail;
        ls->tail=node;
    }
    ls->n--;
}
int main(){
    List *list = new List{nullptr, nullptr, 0};
    addBack(Student{11,"Zec", 98.2},list);
    addBack(Student{31,"Vite", 88},list);
    addBack(Student{77,"Koi", 90.6},list);
    std::cout << "[+] Info:\n";
    show(list);
    deleteBack(list);
    std::cout << "[-] Changes:\n";
    show(list);
}