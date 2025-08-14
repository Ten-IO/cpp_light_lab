/*
    At a restaurant, customers are waiting to be served. Create a queue as singly linked list that can store
    customer. Each customer has name, sex and phone number.
    The program provides a menu of choices that a user can use to do some operations on the queue. The
    operations are:
        A. enqueue a customer (add a customer to queue),
        B. dequeue a customer (remove a customer from queue),
        C. display all customers’ info in the queue and
        D. exit the program.
    Each time the function dequeue is called, display this message “Serving customer, [name]! ”. The program
    keeps running until the user choose choice number 4 to exit.
*/
#include <iostream>
#include <iomanip>
struct Customer
{
    std::string name;
    char sex;
    std::string age;
    Customer *next;
};
struct Queue
{
    Customer *front, *rear;
    int n;
};
bool isEmpty(Queue *q)
{
    return q->n == 0 ? std::cout << "[+] Empty Queue\n", true : false;
}
void enqueue(Queue *q, std::string name, char gender, std::string age)
{
    Customer *c = new Customer{name, gender, age, nullptr};
    if (q->n == 0)
        q->front = c;
    else
        q->rear->next = c;
    q->rear = c;
    q->n++;
}
void dequeue(Queue *q)
{
    if (isEmpty(q))
        return;
    Customer *c = q->front;
    std::cout << "\n[-] Serving Customer, " << c->name << '\n';
    q->front = q->front->next;
    delete c;
    if (q->front == nullptr)
        q->rear = nullptr;
    q->n--;
}
void show(Queue *q)
{
    if (isEmpty(q))
        return;
    Customer *c = q->front;
    std::cout << "\n[+] To Serve: \n";
    int i = 0;
    while (c != nullptr)
    {
        std::cout << ++i << std::setw(20) << c->name << std::setw(3) << c->sex << ' ' << c->age << '\n';
        c = c->next;
    }
}
std::string read(std::string prmpt)
{
    std::string txt;
    std::cout << prmpt;
    std::getline(std::cin, txt);
    return txt;
}
int main()
{
    Queue *qu = new Queue{nullptr, nullptr, 0};
    int input;
    while (true)
    {
        std::cout << "\n== Restaurant Customer Management ==\n";
        std::cout << "  1. enqueue a customer (add a customer to queue),\n";
        std::cout << "  2. dequeue a customer (remove a customer from queue),\n";
        std::cout << "  3. display all customers' info in the queue and\n";
        std::cout << "  4. exit the program.\n";
        try
        {
            input = std::stoi(read("[> Choice: "));
        }
        catch (...)
        {
            std::cout << "[!] Input must be a numeric.\n";
            continue;
        }
        switch (input)
        {
        case 1:
        {
            std::string name = read("\nCustomer's name: ");
            char sx = read("Gender         : ")[0];
            std::string age = read("Phone Number   : ");
            enqueue(qu, name, sx, age);
            break;
        }
        case 2:
            dequeue(qu);
            break;
        case 3:
            show(qu);
            break;
        case 4:
            std::cout << "\n[!] Exiting ..\n";
            delete qu;
            return 0;
            break;
        default:
            std::cout << "\n[!] Choice 1-4\n";
            break;
        }
    }
}