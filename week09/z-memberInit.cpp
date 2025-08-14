// About member initializer for class
#include <iostream>
struct Queue
{
    int front, rear;
    int *q, size;

    Queue(int s) : front(-1), rear(-1), size(s)
    {
        q = new int[s];
    }
    ~Queue()
    {
        delete[] q;
    }
};
void enqueue(Queue &q, int data)
{
    {
        if (q.rear == q.size-1)
        {
            std::cout << "[!] Full queue\n";
            return;
        }
    }
    if (q.front == -1&&q.rear ==-1)
        q.front = q.rear = 0;
    else
        q.rear++;
    q.q[q.rear] = data;
}
void show(const Queue &q)
{
    if (q.front == -1 || q.front > q.rear)
    {
        std::cout << "[!] Empty queue\n";
        return;
    }
    for (int i = q.front; i <= q.rear; i++)
        std::cout << q.q[i] << " ";
}
int main()
{
    Queue qu = Queue(5);
    int n[] = {22, 41, 31};
    for (int i : n)
        enqueue(qu, i);
    show(qu);
    return 0;
}