/*
    [+] Q5. Write a function to insert a node at the end of a singly
        linked list.
*/
#include <iostream>
struct Node
{
    int num;
    Node *next;
} node;
struct List
{
    Node *head, *tail;
    int n;
} *ls;
void endSert(List *ls, int data)
{
    Node *tmp = new Node{data, nullptr};
    if (ls->head == nullptr)
        ls->head = tmp;
    else
        ls->tail->next = tmp;
    ls->tail = tmp;
    ls->n++;
}
int main()
{
    ls = new List{nullptr, nullptr, 0};
    std::cout << "Index: " << ls->n << " -> " << &(ls->head->num) << '\n';
    endSert(ls, 2);
    std::cout << "Index: " << ls->n << " -> " << &(ls->head->num) << " -> " << (*ls).head->num << '\n'; // ls->num = (*ls).num
    std::cout << "Index: " << ls->n << " -> " << &(ls->tail->num) << " -> " << (*ls).tail->num; // ls->num = (*ls).num
    return 0;
}