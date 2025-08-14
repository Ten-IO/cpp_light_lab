/*
    [+] Ask user for 10 numbers and store in a single linked list. Sort data in your linked list using bubble sort
        algorithm. Display the sorted data in your linked list.
*/
#include <iostream>
struct Input
{
    int num;
    Input *next;
};
struct List
{
    Input *head, *tail;
    int n;
};
void add(int data, List *ls)
{
    Input *in = new Input{data, nullptr};
    if (ls->n == 0)
        ls->head = in;
    else
        ls->tail->next = in;
    ls->tail = in;
    ls->n++;
}
void show(List *ls)
{
    Input *in = ls->head;
    while (in != nullptr)
    {
        std::cout << in->num << " ";
        in = in->next;
    }
}
void sort(List *ls)
{
    if (ls->n < 2)
        return;
    Input *curr = ls->head, *prev = nullptr;
    bool swap;
    do
    {
        curr = ls->head;
        swap = false;
        while (curr->next != prev)
        {
            if (curr->num > curr->next->num)
            {
                int tmp = curr->num;
                curr->num = curr->next->num;
                curr->next->num = tmp;
                swap = true;
            }
            curr = curr->next;
        }
        prev = curr;
    } while (swap);
}
int main()
{
    List *ls = new List{nullptr, nullptr, 0};
    int num;
    std::cout << "== THE 10 Numeric Sorter ==\n";
    while (ls->n < 10)
    {
        std::cout << "arr[" << (ls->n+1) << "] : ";
        std::cin >> num;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "\n[!] Input only number\n\n";
            continue;
        }
        add(num, ls);
    }
    sort(ls);
    std::cout << "\n[+] Sorted: ";
    show(ls);
    return 0;
}