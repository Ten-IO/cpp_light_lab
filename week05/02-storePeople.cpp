/*
    [+] Store names of people in a linked list. Make sure we can add person more as many as possible.
Hint: Create 2 structures such as element structure and list structure. Then create 3 functions:
createList (make the list empty), addPerson(add new person name to the begin of the list), display
all data in the list.  Finally, test your program in main and add 10 of your friends’ names.
*/
#include <iostream>
struct Person
{
    std::string name;
    Person *next;
};
struct List
{
    int n;
    Person *head, *tail;
};
List *init() { return new List{0, nullptr, nullptr}; }
void addPerson(const std::string &name, List *ls)
{
    Person *p = new Person{name, nullptr};
    p->next = ls->head;
    ls->head = p;
    if (ls->n == 0)
        ls->tail = p;
    ls->n++;
}
void show(const List *ls)
{
    Person *p = ls->head;
    while (p != nullptr)
    {
        std::cout << p->name << " ";
        p = p->next;
    }
}

int main()
{
    List *People = init();
    addPerson("Nali", People);
    addPerson("Kala", People);
    addPerson("Liam", People);
    addPerson("Risa", People);
    std::string ppl[6] = {"lane", "Nik", "Fola", "Eli", "Set", "Dow"};
    for (int i = 0; i < 6; i++)
        addPerson(ppl[i], People);
    show(People);
}