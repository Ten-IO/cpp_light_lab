/* Write a C++ program to create a new data structure for storing info of book (book ID, book ISBN, 
book title, published year, author names and price ($)). Each book could have more than one 
author. To do: 
▪ Create an array that can store 5 books’ info.  
▪ Create a function to display a book info based on ISBN. This function takes a parameter which 
is an ISBN of a book.   
void displayBookByISBN(Book books[], int size, string isbn){…. } 
▪ Create a function to display information of all books.  
void displayAllBooks(Book books[], int size) { … } 
*/

#include <iostream>
#include <vector>
using namespace std;

struct Book
{
    string bookID;
    string ISBN;
    string title;
    int publishedYear;
    vector<string> authors;
    double price;
};

void displayBookByISBN(Book books[], int size, string isbn)
{
    for (int i = 0; i < size; ++i)
    {
        if (books[i].ISBN == isbn)
        {
            cout << "Book Found:\n";
            cout << "ID: " << books[i].bookID << "\nTitle: " << books[i].title
                 << "\nYear: " << books[i].publishedYear << "\nAuthors: ";
            for (string author : books[i].authors)
                cout << author << ", ";
            cout << "\nPrice: $" << books[i].price << endl;
            return;
        }
    }
    cout << "Book with ISBN " << isbn << " not found.\n";
}

void displayAllBooks(Book books[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "Book " << i + 1 << ":\n";
        cout << "ID: " << books[i].bookID << "\nTitle: " << books[i].title
             << "\nISBN: " << books[i].ISBN
             << "\nYear: " << books[i].publishedYear
             << "\nAuthors: ";
        for (string author : books[i].authors)
            cout << author << ", ";
        cout << "\nPrice: $" << books[i].price << endl
             << endl;
    }
}

int main()
{
    Book books[5] = {
        {"B001", "123-A", "C++ Basics", 2020, {"John Doe"}, 29.99},
        {"B002", "124-B", "Advanced C++", 2021, {"Jane Smith", "Alan Brown"}, 39.99},
        {"B003", "125-C", "Data Structures", 2019, {"Alice White"}, 24.50},
        {"B004", "126-D", "Algorithms", 2022, {"Bob Grey"}, 34.00},
        {"B005", "127-E", "C++ Projects", 2023, {"Charlie Black", "Dana Green"}, 44.99}};

    displayAllBooks(books, 5);

    string searchISBN;
    cout << "\nEnter ISBN to search for a book: ";
    cin >> searchISBN;
    displayBookByISBN(books, 5, searchISBN);

    return 0;
}
