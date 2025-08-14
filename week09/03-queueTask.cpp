/*
    [+] Create a queue that can schedule a set of priority tasks. Each task is just to display a message on the screen.
        Table 1 shows about tasks and their descriptions (used for displaying message). Suppose that, the queue
        contains Task4, Task1, Task3, and Task2 (Task 4 is the first task in the queue, Task 1 is the second task
        in the queue, so on and so forth).
        Write a program to ask user “Do you want to activate a task in your queue now?”.
        When the user say ‘yes’, activate the task by calling to dequeue function of the queue. Keep asking user
        until there is no task remained in the queue.
*/
#include <iostream>
#include <iomanip>
struct Task
{
    int id;
    std::string desc;
    Task *next;
};
struct Queue
{
    Task *front, *rear;
    int n;
};
Queue *createQ()
{
    Queue *q = new Queue;
    q->front = q->rear = nullptr;
    return q;
}
void enqueue(Queue *q, const Task &_t)
{
    Task *newT_ = new Task{_t.id, _t.desc, nullptr};
    if (q->rear == nullptr)
        q->front = newT_;
    else
        q->rear->next = newT_;
    q->rear = newT_;
    q->n++;
}
bool isEmpty(Queue *q)
{
    return q->front == nullptr ? std::cout << "[!] Empty queue\n", true : false;
}
void dequeue(Queue *q)
{
    if (isEmpty(q))
        return;
    Task *tmp = q->front;
    q->front = q->front->next;
    if (q->front == nullptr)
        q->rear = nullptr;
    std::cout << "[-] Activating " << tmp->id << ": " << tmp->desc << " ... DONE!\n";
}
void show(Queue *q)
{
    Task *t = q->front;
    std::cout << " ______ ______________________\n";
    std::cout << "| Task |      Description     |\n";
    while (t != nullptr)
    {
        std::cout << "|______|______________________|\n";
        std::cout << "| " << std::setw(4) << t->id << " | " << std::setw(20) << t->desc << " |\n";
        t = t->next;
    }
    std::cout << "|______|______________________|\n";
}

int main()
{
    Queue *taskQueue = createQ();
    enqueue(taskQueue, Task{4, "Send report", nullptr});
    enqueue(taskQueue, Task{1, "Review Lesson", nullptr});
    enqueue(taskQueue, Task{3, "Malware scan", nullptr});
    enqueue(taskQueue, Task{2, "Update note", nullptr});

    std::string input;
    while (!isEmpty(taskQueue))
    {
        show(taskQueue);
        std::cout << "Do you want to activate a task in your queue? (yes?): ";
        std::cin >> input;
        if (input == "yes" || input == "y")
            dequeue(taskQueue);
        else
            std::cout << "Task not activated. Continue..\n";
    }
    std::cout << "[+] All tasks completed. Congratulation!";
    delete taskQueue;
    return 0;
}
