/*
    [+] Given a student list below. Read data from csv file into an array. Sort the data in array using Quick algorithm.
        The program should be able to sort the data by … (provide a menu of choice to a user)
            a. Sort by ID
            b. Sort by name
            c. Sort by gender
*/
#include <iostream>
#include <fstream>
#include <sstream>
struct Student
{
    int id;
    std::string name, dob;
    char gender;
};
void swap(Student &a, Student &b)
{
    Student tmp = a;
    a = b;
    b = tmp;
}
int partitionID(Student arr[], int lb, int ub)
{
    Student pivot = arr[lb];
    int start = lb, end = ub;
    while (start < end)
    {
        while (arr[start].id <= pivot.id && start <= ub)
            start++;
        while (arr[end].id > pivot.id && end >= lb)
            end--;
        if (start < end)
            swap(arr[start], arr[end]);
    }
    swap(arr[lb], arr[end]);
    return end;
}
int partitionName(Student arr[], int lb, int ub)
{
    Student pivot = arr[lb];
    int start = lb, end = ub;
    while (start < end)
    {
        while (arr[start].name <= pivot.name && start <= ub)
            start++;
        while (arr[end].name > pivot.name && end >= lb)
            end--;
        if (start < end)
            swap(arr[start], arr[end]);
    }
    swap(arr[lb], arr[end]);
    return end;
}
int partitionGender(Student arr[], int lb, int ub)
{
    Student pivot = arr[lb];
    int start = lb, end = ub;
    while (start < end)
    {
        while (arr[start].gender <= pivot.gender && start <= ub)
            start++;
        while (arr[end].gender > pivot.gender && end >= lb)
            end--;
        if (start < end)
            swap(arr[start], arr[end]);
    }
    swap(arr[lb], arr[end]);
    return end;
}
void QuickSort(Student arr[], int lb, int ub, int type)
{
    if (lb < ub)
    {
        int pos;
        if (type == 1)
            pos = partitionID(arr, lb, ub);
        else if (type == 2)
            pos = partitionName(arr, lb, ub);
        else if (type == 3)
            pos = partitionGender(arr, lb, ub);
        else
            return;
        QuickSort(arr, lb, pos - 1, type);
        QuickSort(arr, pos + 1, ub, type);
    }
}
void show(Student st[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << st[i].id << ' ' << st[i].name << ' ' << st[i].gender << ' ' << st[i].dob << '\n';
}
int main()
{
    int choice, curr = 0, size = 10;
    Student st[size];
    std::stringstream stream;
    std::string line;
    std::ifstream read("student_sample.csv");
    if (!read)
    {
        std::cerr << "[!] Cannot open student.csv\n";
        return 1;
    }
    std::getline(read, line);
    while (std::getline(read, line) && curr < size)
    {
        stream.clear();
        stream.str(line);
        std::getline(stream, line, ',');
        st[curr].id = std::stoi(line);
        std::getline(stream, line, ',');
        st[curr].name = line;
        std::getline(stream, line, ',');
        st[curr].gender = line[0];
        std::getline(stream, line, ',');
        st[curr].dob = line;
        curr++;
    }
    read.close();
    std::cout << "\nFrom file:\n";
    show(st, curr);
    std::cout << "\n == Sorting Methods ==";
    std::cout << "\n    1. by ID";
    std::cout << "\n    2. by name";
    std::cout << "\n    3. by gender";
    std::cout << "\n>> choice: ";
    std::cin >> choice;
    if (choice > 0 && choice <= 3)
    {
        QuickSort(st, 0, curr - 1, choice);
        std::cout << "\nSorted:\n";
        show(st, curr);
    }
    else
        std::cout << "[!] You picked the wrong choice. Restart!\n";
    return 0;
}