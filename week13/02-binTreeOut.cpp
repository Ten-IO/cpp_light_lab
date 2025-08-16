/*
    [+] Random 20 numbers in this ranges [10 – 1000] then store in a binary search tree. Display data from this
        tree using in-order traversal method and also write them to a file (txt or CSV).
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
struct Node
{
    int data;
    Node *left, *right;
};
Node *insert(Node *root, int data)
{
    if (root == nullptr)
        root = new Node{data, nullptr, nullptr};
    else if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}
void showInOrder(Node *root)
{
    if (root != nullptr)
    {
        showInOrder(root->left);
        std::cout << root->data << " ";
        showInOrder(root->right);
    }
}
void writeInOrder(Node *root, std::fstream &_write){
    if (root!=nullptr){
        writeInOrder(root->left, _write);
        _write << root->data << ' ';
        writeInOrder(root->right, _write);
    }
}
int main() {
    Node *node = nullptr;
    node  = insert(node, 0);
    for (int i=0;i<20;i++){
        int num= rand()%991+10; // when range 5-10, f(min, max) = (rand % (max-min+1) + min);  
        /*
        let say 5-10
        + When putting in range
        rand % 10 = 0-9
        + When get to the range
        rand % 10 + 10 = 10-19
        + But we want min of 5
        rand % (10-5) = 0-4
        rand % (10-5) + 10 = 5-9
        rand % (10-5) + 10 + 1 = 6-11 (x)
        rand % (10-5+1) + 10 = 5-10 (..o)
        f(min, max) = rand % (max-min+1) + max = min-max (o)
        */
        node = insert(node, num);
    }
    std::cout << "In-order Node: ";
    showInOrder(node);
    std::fstream write("out.txt", std::ios::out);
    writeInOrder(node, write);
    write.close();
    std::cout << "\n[+] Write finished";
    return 0;
}

        