/*
    [+] Create two linked list that are able to store list of English alphabets, one list for the small letters and
        another list for the capital letters. Hint: Create 2 structures such as element structure and list structure.
        Then create 3 functions: createList, addAlphabet(add to the end of the list), display all data in the list.
*/
#include <iostream>
struct Node
{
    char alpha;
    Node *next;
};
struct LinkedList
{
    int n;
    Node *head, *tail;
};
LinkedList *initList()
{
    return new LinkedList{0, nullptr, nullptr};
}
void addEnd(char c, LinkedList *ls)
{
    Node *e = new Node{c, nullptr};
    if (ls->n == 0)
        ls->head = e;
    else
        ls->tail->next = e;
    ls->tail = e;
    ls->n++;
}
void show(const LinkedList *ls)
{
    Node *n = ls->head;
    while (n != nullptr)
    {
        std::cout << n->alpha << " ";
        n = n->next;
    }
}

int main()
{
    LinkedList *lchar = initList(), *uchar = initList();
    addEnd('a', lchar); addEnd('c', lchar);
    addEnd('D', uchar); addEnd('G', uchar);
    std::cout << "Lower character: ";
    show(lchar);
    std::cout << "\nUpper character: ";
    show(uchar);
}
