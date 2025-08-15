/*
    [+] Create a hash table to store key-value data for 15 students.
        A student has ID, name, sex, phone and major.
            • A student’s ID will be taken as a key which is used as a parameter for the hash function. The value to
            be inserted to an array slot at the position defined by the hash function is a student info of that ID.
            • To avoid collision, you have to apply collision resolution technique called chaining (implement hash
            table as an array of linked list).
            • The hash function of this hash table is to generate the student ID into an index of the array. Let assume
            that the student ID is the same format as an engineer student ID (e.g.: td202301)
            To test this program, enter information of 3 students (your friends) then
        a. Insert their information to the hash table.
        b. Finally, display all data in hash table.
        c. Study the case that has duplicate data in order to verify that your program is still working well
        since we apply collision resolution technique.
*/
#include <iostream>
struct Student {std::string id, name, phone, major; char gender;};
struct Node {Student *info; Node *next;};
struct List {Node *head, *tail; int n;};

const int SIZE = 15;
List *ht[SIZE];

void initHashTable()
{
    for (int i = 0; i < SIZE; i++)
        ht[i] = new List{nullptr, nullptr, 0};
}
int hash(std::string txt)
{
    int val = 0;
    for (char c : txt)
        val += c;
    return (val % SIZE + SIZE) % SIZE;
}
void link(List *ls, Student *_s)
{
    Node *node = new Node{_s, nullptr};
    if (ls->n == 0)
        ls->head = node;
    else
        ls->tail->next = node;
    ls->tail = node;
    ls->n++;
}
void insert(Student *_s)
{
    int index = hash(_s->id);
    link(ht[index], _s);
}
void show()
{
    std::cout << "Index\t->\tValue\n";
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << ' ' << i;
        if (ht[i]->n != 0)
        {
            Node *node = ht[i]->head;
            while (node != nullptr)
            {
                std::cout <<"\t->\t"<< node->info->id << '\t' << node->info->name << '\t'
                          << node->info->gender << '\t' << node->info->major << '\t'
                          << node->info->phone << '\n';
                node = node->next;
            }
        }
        else
            std::cout << "\t->\t" << "null\n";
    }
}
int main()
{
    initHashTable();
    insert(new Student{"ko102931", "Holan", "083582934", "RAM", 'm'});
    insert(new Student{"kp102930", "Nida", "039481929", "CPU", 'm'});
    insert(new Student{"td102494", "Dorta", "039481929", "CS", 'f'});
    show();
}