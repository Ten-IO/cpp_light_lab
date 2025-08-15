/*
(No collision)
    [+] Create a hash table with the size of 10 to store names of people. This hash table uses a hash
        function which returns the index in which the name should be inserted into. The hash function computes
        the total summation of ASCII value in the string (sum each character’s ASCII value together) and modulo
        with 10. Write 3 functions to:
            ▪ Insert a string to the hash table
            ▪ Search whether a string is contained in the hash table. If the string is contained in the hash table, then display a
                message “It is contained in position/index positionNumber”. Otherwise, display “Not found”.
            ▪ Remove the string from the hash table. If the string is contained in the hash table, then remove it by setting to
                a default value (e.g: for array of string, the default value can be an empty string). Finally display a message
                “removed success”.  Otherwise (if not contained), display “failed to delete as it does not exist”.
        In main program, add a string “Bob” to the hash table. Then ask a user for 3 other names and add to the hash
        table. Search for the string “Bob” by calling search function. Then remove string “Bob” using the remove
        function. Finally, display all data in the hash table.
    [!] Remark: Apply chaining to solve the collision problem.
*/
#include <iostream>
struct Txt
{
    std::string txt;
    Txt *next;
};
struct List
{
    int n;
    Txt *head, *tail;
};
const int size = 10;
List *ht[size];
List *init()
{
    return new List{0, nullptr, nullptr};
}
void initChainHash()
{
    for (int i = 0; i < size; i++)
        ht[i] = init();
}
int hash(std::string val)
{
    int hash = 0;
    for (char c : val)
        hash += c;
    return hash % size;
}
void link(List *ls, std::string val)
{
    Txt *txt = new Txt{val, nullptr};
    if (ls->n == 0)
        ls->head = txt;
    else
        ls->tail->next = txt;
    ls->tail = txt;
    ls->n++;
}
void insert(std::string val)
{
    int pos = hash(val);
    link(ht[pos], val);
}
bool pop(std::string val)
{
    int pos = hash(val);
    if (ht[pos]->n != 0)
    {
        Txt *txt = ht[pos]->head;
        Txt *prev = nullptr;
        while (txt != nullptr)
        {
            if (txt->txt == val)
                if (prev == nullptr)
                {
                    ht[pos]->head = txt->next;
                    if (ht[pos]->tail == txt)
                        ht[pos]->tail = nullptr;
                }
                else
                {
                    prev->next = txt->next;
                    if (ht[pos]->tail == txt)
                        ht[pos]->tail = prev;
                }
            delete txt;
            ht[pos]->n--;
            std::cout << "[!] Removed " << val << " from [" << pos << "]\n";
            return true;
        }
        prev = txt;
        txt = txt->next;
    }
    std::cout << "[!] " << val << " not found\n";
    return false;
}
bool search(std::string val)
{
    int pos = hash(val);
    if (ht[pos]->n != 0)
    {
        Txt *txt = ht[pos]->head;
        while (txt != nullptr)
        {
            if (txt->txt == val)
            {
                std::cout << "[=] Found " << val << " at [" << pos << "]\n";
                return true;
            }
            txt = txt->next;
        }
    }
    std::cout << "[!] " << val << " is not found\n";
    return false;
}
void show()
{
    std::cout << "Index\t->\tValue\n";
    for (int i = 0; i < size; i++)
    {
        std::cout << ' ' << i;
        if (ht[i]->n != 0)
        {
            Txt *txt = ht[i]->head;
            while (txt != nullptr)
            {
                std::cout << "\t->\t" << txt->txt << '\n';
                txt = txt->next;
            }
        }
        else
            std::cout << "\t->\t" << "null\n";
    }
}
int main()
{
    std::string input;
    initChainHash();
    insert("Bob");
    for (int i=3;i>0;i--){
        std::cout << "[+] Add "<<i<< " more name: ";
        std::getline(std::cin, input);
        insert(input);
    }
    search("Bob");
    pop("Bob");
    show();
}