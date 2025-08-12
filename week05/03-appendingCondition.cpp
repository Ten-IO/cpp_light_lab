/*
    [+] Design a program that is able to manage product information. Define a linked list that is able to store
        a list of products. Each product has info such as productid, Name, price. Create data structures for
        this program. Create some functions below:
            a. create an empty list,
            b. add product to begin of the list (when the price is less than 50 dollars),
            c. add product to end of the list (when the price is at least 50 dollars), and
            d. display product for the implementation of linked list.
*/
#include <iostream>
struct Product
{
    int id;
    std::string name;
    double price;
    Product *next;
};
struct List
{
    Product *head, *tail;
    int n;
};
List *init() { return new List{nullptr, nullptr, 0}; }
/* if we pass by ref without const, the address will be modified as it start reference again
void addProduct(Product &_p, List *ls)
{
    Product *p = &_p;
    */
void addProduct(const Product &_p, List *ls) {
     Product *p = new Product{_p.id,_p.name,_p.price,_p.next};
     if (p->price < 50)
    {
        if (ls->n == 0)
            ls->head = p;
        else
            ls->tail->next = p;
        ls->tail = p;
    }
    else
    {
        p->next = ls->head;
        ls->head = p;
        if (ls->n == 0)
            ls->tail = p;
    }
    ls->n++;
}
void show(const List *ls)
{
    Product *p = ls->head;
    while (p != nullptr)
    {
        std::cout << "Product: " << p->id << " - " << p->name << ", cost: $" << p->price << '\n';
        p = p->next;
    }
}
