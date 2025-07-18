#include <iostream>
struct Element
{
    char low, up, t;
    Element *next;
};

struct List
{
    int n;
    Element head;
    Element tail;
};

int main()
{
    Element e = {'a', 'A', 't', nullptr};
    std::cout << &e.next << std::endl;
    std::cout << e.next << std::endl;
    std::cout << "2 " << &e.low << std::endl;
    std::cout << "1 " << &e.up << std::endl;
    std::cout << "2 " << &e.t << std::endl;
    std::cout << "3 " << &e << std::endl;
}