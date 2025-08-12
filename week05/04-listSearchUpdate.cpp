/*
    [+] With the extension to the exercise #3, we also create two search functions and one update function.
        - The update function is to update data based on the input of productid.
        - The first search function is able to search and display detail product information by name,
        - while the second search function should be able to show all products based on a given price (p).
            It shows product into two sections such as:
                1) Section1: All products that have price lower than p
                2) Section2: All products that have price more than p.
*/
#include <iostream>
#include "03.cpp"
void updateByID(const Product &_p, List *ls)
{
    Product *p = ls->head;
    while (p != nullptr)
    {
        if (_p.id == p->id)
            // *p = _p; // affecting *(p->next) because _p.next is 0x0 nullptr
        {
            p->name=_p.name;
            p->price=_p.price;
        }
        p = p->next;
    }
}
void searchID(int id, List *ls)
{
    Product *p = ls->head;
    List *tmpList = init();
    while (p != nullptr)
    {
        if (id == p->id)
            addProduct(*p, tmpList);
        p = p->next;
    }
    show(tmpList);
}
void searchPrice(const int price, List *ls)
{
    List *lowP = init();
    List *topP = init();
    Product *p = ls->head;
    while (p != nullptr)
    {
        if (p->price > price)
            addProduct(*p, topP);
        else
            addProduct(*p, lowP);
        p = p->next;
    }

    std::cout << "[+] Price higher than $" << price << '\n';
    show(topP);
    std::cout << "[+] Price lower than $" << price << '\n';
    show(lowP);
}
int main()
{
    List *ls = init();
    Product _p[] = {{22, "86", 50.1, nullptr}, {98, "Kuru Toga", 1.10, nullptr}, {01, "Lenovo X1", 202.1, nullptr}};
    std::cout << "[+] List:\n";
    for (int i = 0; i < 3; i++)
        addProduct(_p[i], ls);
    show(ls);
    updateByID(Product{01, "Lenovo X1 Carbon", 1002.1, nullptr}, ls);
    std::cout << "[=] Search Product ID\n";
    searchID(1, ls);
    std::cout << "[=] Search Product Price\n";
    searchPrice(10, ls);
}