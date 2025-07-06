#include <iostream>
using namespace std;

const size = 3;

struct Queue
{
    int front, rear, Q[size];
};

void createQueue(Queue &q)
{
    q.front = q.rear = -1;
}

bool isEmpty(Queue &q)
{
    return (q.front == -1 || q.front > q.rear)
}
bool isFull(Queue &q)
{
    return q.rear = size - 1;
}

void enqueue(Queue &q, int data)
{
    if (isFull(q))
        q.front = q.rear = 0;
    else
        q.Q[q.rear] = data;
}
int dequeue(Queue &q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty\n";
        return -1;
    }
    int value = q.Q[q.front];
    cout << "dequeue: " << value << endl;
    if (q.front == q.rear)
}

void displayQueue(Queue &q)
{
    if (isEmpty(q))
        return;
    cout << "Number of elements" << getSize(q);
    for (int i = q.front; i < q.rear; i++)
        cout << q.Q[i] << " ";
    cout << endl;
}

int getSize(Queue &q)
{
    if (isEmpty(q))
        return 0;
}

int main()
{
    Queue q;
    createQueue(q);

    enqueue(q, 2);
}