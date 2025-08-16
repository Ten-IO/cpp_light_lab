/*
    [+] Create a file containing 20 employees’ info, where each employee has employee ID (starting with emp001),
        first name, last name, position, gender and phone number.
            ▪ Read data from this file then store in a binary search tree.
            ▪ Write a function to search for an employee based on his/her employee ID. This function asks a user to
            input an employee ID to be searched in the tree.
            ▪ Test your program and call the search function above
*/
#include <iostream>
#include <fstream>
#include <sstream>
struct Node
{
    Node *left, *right;
    std::string id, fname, lname, position, gender, tel;
};
Node *insert(Node *root, std::string id, std::string fname, std::string lname, std::string position, std::string gender, std::string tel)
{
    if (root == nullptr)
        return new Node{nullptr, nullptr, id, fname, lname, position, gender, tel};
    else if (id < root->id)
        root->left = insert(root->left, id, fname, lname, position, gender, tel);
    else if (id > root->id)
        root->right = insert(root->right, id, fname, lname, position, gender, tel);
    return root;
}
void showIn(Node *root)
{
    if (root != nullptr)
    {
        showIn(root->left);
        std::cout << "[+] id: " << root->id << '\n'
                  << root->fname << ' ' << root->lname << "\t-\t" << root->position << " | " << root->gender << " | " << root->tel << '\n';
        showIn(root->right);
    }
}
bool search(Node *root, std::string id)
{
    if (root == nullptr)
        return false;
    else if (id == root->id)
        return true;
    else if (id < root->id)
        return search(root->left, id);
    else 
        return search(root->right, id);
}
int main()
{
    std::ifstream read("sample.csv");
    std::string line;
    std::stringstream stream;
    Node *root = nullptr;
    if (!read)
    {
        std::cerr << "[!] Missing sample.csv\n";
        return 1;
    }
    while (std::getline(read, line))
    {
        std::string txt[6];
        stream.clear();
        stream.str(line);
        for (int i = 0; i < 5; i++)
            std::getline(stream, txt[i], ',');
        std::getline(stream, txt[5]);
        root = insert(root, txt[0], txt[1], txt[2], txt[3], txt[4], txt[5]);
    }
    read.close();
    std::cout << "[+] Read completed\n";
    std::cout << "\n[+] Read data:\n";
    showIn(root);
    std::cout << "\n[+] Search employee id: ";
    std::cin >> line;
    if (search(root, line))
        std::cout << "[+] Found\n";
        else
    std::cout << "[-] " << line << " : Not found\n";
    return 0;
}
