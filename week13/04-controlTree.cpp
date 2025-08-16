/*
    [+] Ask a user for a number, say n. Then loop n times to get names and ages of n students. Store names of 
    students into a binary search tree. 
        a. Display data in the tree using in-order traversal. Write those data into a file (txt or CSV). 
        b. Find the student who has the youngest age. 
        c. Find the student who has the oldest age. 
*/
#include <iostream>
#include <fstream>
struct Student{std::string name; int age;};
struct Node{Node *left, *right; Student data;};
Node *insert( Node *root, Student data){
    if(root ==nullptr)
    return new Node{nullptr,nullptr,data};
    else if (data.age<root->data.age)
    root->left = insert(root->left, data);
    else if(data.age>root->data.age)
    root->right = insert(root->right, data);
    return root;
}
void showIn(Node *root){
    if (root!=nullptr){
        showIn(root->left);
        std::cout << "\nStudent: "<< root->data.name << " age: " << root->data.age;
        showIn(root->right);
    }
}
Node *findMin(Node *root){
    if(root->left!=nullptr)
    root = root->left;
    return root;
}
Node *findMax(Node *root){
    if(root->right!=nullptr)
    root = root->right;
    return root;
}
void WriteIn(Node *root, std::ofstream &_write){
    if(root!=nullptr){
        WriteIn(root->left, _write);
        _write << root->data.name << ','<< root->data.age<<'\n';
        WriteIn(root->right, _write); // declare fstream("<file>", ios::out), when pass in must be same fstream; if ofstream, use ofstream;
    }
}
int main(){
    Node *node = nullptr;
    Student s;
    unsigned int SIZE;
    std::ofstream write("out.txt", std::ios::out);
    std::cout << "[+] Number of student you want to write: ";
    std::cin >> SIZE;
    for (int i=0;i<SIZE;i++)
    {
        std::cout << "#"<< i+1 <<" Student name: ";
        std::cin >>  s.name;
        std::cout << "#"<< i+1 <<" Student age: ";
        std::cin >> s.age;
        node = insert(node, s);
    }
    showIn(node);
    WriteIn(node, write);
    std::cout << "\n[+] Write completed";
    return 0;
}