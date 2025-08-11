/* 
    Describe simple DS (Data Structure) linked to each other
*/
struct Node
{
    int data;
    Node *link;
};
struct linkedList
{
    int n;
    Node *head, *tail;
};