/*
    [+] Suppose that we want to store ID of ITC students in a binary search tree (BST). Create a data structure for this program.
    [!] Hint: Create element for the tree, insert function, traverse the tree via in-order, preorder or post-order method.
*/
#include <iostream>
struct Node
{
    std::string data;
    Node *left, *right;
};
Node *insert(Node *root, std::string data)
{
    if (root == nullptr)
    {
        root = new Node;
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data >= root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}
void preOrder(Node *root)
{
    if (root != nullptr)
    {
        std::cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(Node *root)
{
    if (root != nullptr)
    {
        inOrder(root->left);
        std::cout << root->data << " ";
        inOrder(root->right);
    }
}
void postOrder(Node *root)
{
    if (root != nullptr)
    {
        postOrder(root->left);
        std::cout << root->data << " ";
        postOrder(root->right);
    }
}
int main()
{
    Node *tree = new Node{};
    tree = insert(tree, "d2021");
    tree = insert(tree, "d2019");
    insert(tree, "k2011");
    insert(tree, "d2021");
    std::cout << "[+] Pre-Order: ";
    preOrder(tree);
    std::cout << "\n[=] In-Order: ";
    inOrder(tree);
    std::cout << "\n[-] Post-Order: ";
    postOrder(tree);
}