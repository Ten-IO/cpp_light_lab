/*
    [+] Write a C++ program to implement a queue data structure using an array to store integer numbers. Write
        functions for: enqueue(), dequeue(), front(), isEmpty(), isFull(), displayQueue(), getSize().
*/
#include <iostream>
#define SIZE 5
struct Queue
{
    int front, rear, q[SIZE];
};
void init(Queue &q)
{
    q.front = q.rear = -1;
}
bool isEmpty(const Queue &q)
{
    return (q.front == -1 || q.front > q.rear);
}
bool isFull(const Queue &q)
{
    return (q.rear == SIZE - 1);
}
int getSize(const Queue &q){
    return q.rear-q.front+1;
}
void enqueue(Queue &q, int data)
{
    if (isFull(q))
    {
        std::cout << "[!] Empty Queue\n";
        return;
    }
    if (isEmpty(q))
        q.front = q.rear = 0;
    else
        q.rear++;
    q.q[q.rear] = data;
}
int dequeue(Queue &q)
{
    if (isEmpty(q))
    {
        std::cout << "[!] Queue empty\n";
        return -1;
    }
    int val = q.q[q.front];
    q.q[q.front]=0;
    if (q.front == q.rear)
    q.front=q.rear=-1;
    else 
    q.front++;
    return val;
}
int front(const Queue &q){
    if(isEmpty(q))
 {
    std::cout << "[!] Queue empty\n";
    return -1;
}
return q.q[q.front];
}
void show(const Queue &q){
    if(isEmpty(q)){
        std::cout << "[!] Empty queue\n";
        return;
    }
    for (int i=q.front;i<=q.rear;i++)
    std::cout <<q.q[i] <<" ";
}
int main()
{
    Queue qu;
    init(qu);
    int n[] = {22, 41, 31};
    for (int i : n)
        enqueue(qu, i);
        std::cout << "[+] Queue: ";
        show(qu);
        std::cout << "\n[-] Dequeue: " << dequeue(qu);
        std::cout << "\n[+] Queue: ";
        show(qu);
        std::cout << "\n[+] Front: "<<front(qu);
        std::cout << "\n[+] Size: "<<getSize(qu);
    return 0;
}