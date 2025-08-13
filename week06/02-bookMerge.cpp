/*
    [+] Create a singly linked list to manage the lists of books.
        a. Define a singly linked list for books (title, isbn, price)
        b. Implement:
            i.   add the book info to the beginning of the list1 when price is higher than 50
            ii.  add the book info to the end of the list2 when price is lower than 50
            iii. display all book info in the list
            iv.  combine two lists into one list list1
*/
#include <iostream>
struct Book
{
    std::string title;
    long int isbn;
    float price;
    Book *next;
};
struct List
{
    Book *head, *tail;
    int n;
};
void addBook(Book _b, List *ls)
{
    Book *b = new Book{_b.title, _b.isbn, _b.price, nullptr};
    if (_b.price >= 50)
    {
        b->next = ls->head;
        ls->head = b;
        if (ls->n == 0)
            ls->tail = b;
    }
    else
    {
        if (ls->n == 0)
            ls->head = b;
        else
            ls->tail->next = b;
        ls->tail = b;
    }
    ls->n++;
}
void show(const List *ls)
{
    Book *b = ls->head;
    while (b != nullptr)
    {
        std::cout << "Book: [" << b->isbn << "] " << b->title << " cost: " << b->price << '\n';
        b = b->next;
    }
}
void combineList(List *_l1, List *_l2)
{
    if (_l2 == 0)
        return;
    if (_l1->n == 0)
    {
        _l1->head = _l2->head;
        _l1->tail = _l2->tail;
        _l1->n = _l2->n;
    }
    else
    {
        _l1->tail->next = _l2->head;
        _l1->tail = _l2->tail;
        _l1->n += _l2->n;
    }
}
int main()
{
    List *_list1 = new List{nullptr, nullptr, 0}, *_list2 = new List{nullptr, nullptr, 0};
    Book _book[] = {{"To Kill a Mockingbird", 97800610, 12.99},
                    {"1984", 97804519, 119.49},
                    {"The Great Gatsby", 978043265, 10.29},
                    {"Pride and Prejudice", 97413518, 8.75},
                    {"The Catcher in the Rye", 36769488, 91.50}};
    for (int i = 0; i < 5; i++)
    {
        if (_book[i].price > 50)
           addBook(_book[i], _list1);
        else
            addBook(_book[i], _list2);
    };
    std::cout << "[+] List over 50\n";
    show(_list1);
    std::cout << "[+] List under 50\n";
    show(_list2);
    std::cout << "[+] List\n";
    combineList(_list1, _list2);
    show(_list1);
}