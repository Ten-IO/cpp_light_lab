/*
    [+] Create a binary search tree (BST) data structure that can store numbers. Read data from the file below
        and store in this tree. Then
            a. Display data using pre-order traversal.
            b. Display data using in-order traversal.
            c. Display data using post-order traversal.
*/
#include <iostream>
#include <fstream>
struct Node
{
    Node *left, *right;
    int data;
};
Node *insert(Node *root, int data)
{
    if (root == nullptr)
        return new Node{nullptr, nullptr, data};
    else if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}
void showPreOrder(Node *root)
{
    if (root != nullptr)
    {
        std::cout << root->data << ' ';
        showPreOrder(root->left);
        showPreOrder(root->right);
    }
}
void showInOrder(Node *root)
{
    if (root != nullptr)
    {
        showInOrder(root->left);
        std::cout << root->data << ' ';
        showInOrder(root->right);
    }
}
void showPostOrder(Node *root)
{
    if (root != nullptr)
    {
        showPostOrder(root->left);
        showPostOrder(root->right);
        std::cout << root->data << ' ';
    }
}
int main()
{
    Node *root = nullptr;
    int data;
    std::ifstream read("sample.txt");
    if (!read)
    {
        std::cerr << "[!] sample.txt does not exist, program needs to read file.\n";
        return 1;
    }
    std::cout << "[+] Read completed\n";
    while (read >> data)
        root = insert(root, data);
    std::cout << "\nPre-Order: ";
    showPreOrder(root);
    std::cout << "\nIn-Order: ";
    showInOrder(root);
    std::cout << "\nPost-Order: ";
    showPostOrder(root);
    return 0;
}