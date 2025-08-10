/*
[+] Program to create a new data structure for storing info of book (book ISBN, title, published year, author and price ($)).
 Then do each of the following :
 ▪ Create an array that can store 7 books’ info.
 ▪ Create a function to display a book info based on ISBN. This function takes a parameter which is an ISBN of a book.
 ▪ void displayBookByISBN(Book books[], int size, string isbn){…. }
 ▪ Create a function to display information of all books.
 ▪ void displayAllBooks(Book books[], int size) { … }
*/
#include <iostream>
#include <iomanip>
using namespace std;

struct Book
{
    string ISBN, title;
    int year;
    string author;
    double price;
};
void displayBookByISBN(Book books[], int size, string isbn)
{
    cout << "\n\n"
         << left << setw(28) << "   ISBN" << setw(60) << "Book Title " << setw(12) << "Year " << setw(70) << "Author(s)" << setw(10) << "   Price" << endl;

    for (int i = 0; i < size; i++)
    {
        if (books[i].ISBN.compare(isbn) == 0)
            cout << ">> ";
        else
            cout << i + 1 << ". ";
        cout << left << setw(25) << books[i].ISBN << setw(60) << books[i].title << setw(12) << books[i].year << setw(70) << books[i].author << fixed << setprecision(2) << setw(7) << "$" << books[i].price << endl;
    }
}
void displayAllBooks(Book books[], int size)
{
    // for (const Book& book : books)

    cout << "\n\n"
         << left << setw(60) << "   Book Title " << setw(12) << "   Year " << setw(70) << "   Author(s)" << setw(28) << "   ISBN " << setw(10) << "   Price" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ". ";
        cout << left << setw(60) << books[i].title << setw(12) << books[i].year << setw(70) << books[i].author << setw(25) << books[i].ISBN << fixed << setprecision(2) << setw(7) << "$" << books[i].price << endl;
    }
}
int main()
{
    int in;
    Book books[7] = {
        {"978-0134685991", "Effective Java", 2018, "Joshua Bloch", 45.00},
        {"978-0596009205", "Head First Design Patterns", 2004, "Eric Freeman, Bert Bates, Kathy Sierra, Elisabeth Robson", 38.99},
        {"978-0132350884", "Clean Code: A Handbook of Agile Software Craftsmanship", 2008, "Robert C. Martin", 39.99},
        {"978-0201616224", "The Pragmatic Programmer: Your Journey To Mastery", 1999, "Andrew Hunt, David Thomas", 42.95},
        {"978-1491950357", "Fluent Python", 2015, "Luciano Ramalho", 49.99},
        {"978-1492078005", "Designing Data-Intensive Applications", 2017, "Martin Kleppmann", 55.99},
        {"978-0135957059", "Introduction to the Theory of Computation", 2020, "Michael Sipser", 75.99}};
    int size = sizeof(books) / sizeof(books[0]);
    while (true)
    {

        cout << "-- Mini Library --" << endl;
        cout << "1. Check ISBN\n2. Display All\n>> input: ";
        cin >> in;
        switch (in)
        {
        case 1:
        {
            string isbn;
            cout << ">> ISBN: ";
            cin >> isbn;
            displayBookByISBN(books, size, isbn);
            break;
        }
        case 2:
        {
            displayAllBooks(books, size);
            break;
        }
        default:
            return 1;
        }
        system("pause");
        system("cls");
    }
}