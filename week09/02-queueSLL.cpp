/*
    [+] Write a C++ program to implement a queue data structure using a singly linked list to store integer numbers
        with the following operations: enqueue(), dequeue(), front(), isEmpty(), isFull(), displayQueue(), getSize().
*/
#include <iostream>
struct Element
{
    int data;
    Element *next;
};
struct Queue
{
    int n;
    Element *front;
    Element *rear;
};
bool isEmpty(const Queue *q)
{
    return q->n == 0 ? (std::cout << "[+] Empty Queue\n", true) : false;
}
int getSize(const Queue *q)
{
    return q->n;
}
void enqueue(Queue *q, int data)
{
    Element *e = new Element{data, nullptr};
    if (q->n == 0)
        q->front = e;
    else
        q->rear->next = e;
    q->rear = e;
    q->n++;
}
int dequeue(Queue *q)
{
    if (isEmpty(q))
        return -1;
    int val = q->front->data;
    Element *tmp = q->front;
    q->front = q->front->next;
    if (q->front == nullptr)
        q->rear = nullptr;
    delete tmp;
    q->n--;
    return val;
}
int front(const Queue *q)
{
    if (isEmpty(q))
        return -1;
    return q->front->data;
}
int rear(const Queue *q)
{
    if (isEmpty(q))
        return -1;
    return q->rear->data;
}
void show(Queue *q)
{
    if (isEmpty(q))
        return;
    Element *e = q->front;
    while (e != nullptr)
    {
        std::cout << e->data << " ";
        e = e->next;
    }
}
int main()
{
    Queue *qu = new Queue{0, nullptr, nullptr};
    int n[] = {22, 41, 31};
    for (int i : n)
        enqueue(qu, i);
    std::cout << "[+] Queue: ";
    show(qu);
    std::cout << "\n[-] Dequeue: " << dequeue(qu);
    std::cout << "\n[+] Queue: ";
    show(qu);
    std::cout << "\n[+] Front: " << front(qu);
    std::cout << "\n[+] Size: " << getSize(qu);
    return 0;
}