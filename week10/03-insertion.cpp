/*
    [+] Given a student list below. Read data from csv file into an array. Sort the data in array using an insertion algorithm.
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
void sortID(Student s[], int n){
    for (int i=1;i<n;i++){
        Student tmp = s[i];
        int j=i-1;
        while(j>=0&&tmp.id<s[j].id){
            s[j+1] = s[j];
            j--;
        }
        s[j+1] = tmp;
    }
}
void sortName(Student s[], int n){
    for (int i=1;i<n;i++){
        Student tmp = s[i];
        int j = i-1;
        while(j>=0&&tmp.name<s[j].name){
            s[j+1]=s[j];
            j--;
        }
        s[j+1]= tmp;
    }
}
void sortGender(Student s[], int n){
    for (int i=1;i<n;i++){
        Student tmp = s[i];
        int j=i-1;
        while(j>=0&&tmp.gender<s[j].gender)
        {
            s[j+1] =s[j];
            j--;
        }
        s[j+1]=tmp;
    }
}
int main()
{
    int SIZE = 10, curr = 0, choice;
    Student st[SIZE];
    std::string line;
    std::stringstream stream;
    std::ifstream read("student.csv");
    if (!read)
    {
        std::cout << "[!] Cannot open student.csv\n";
        return 1;
    }
    std::getline(read, line);
    while (std::getline(read, line) && curr < SIZE)
    {
        stream.str(line);
        stream.clear();
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

    std::cout << "\nFrom file: \n";
    for (int i = 0; i < curr; i++)
        std::cout << st[i].id << ' ' << st[i].name << ' ' << st[i].gender << ' ' << st[i].dob << '\n';
    std::cout << "\n == Sorting Methods ==";
    std::cout << "\n    1. by ID";
    std::cout << "\n    2. by name";
    std::cout << "\n    3. by gender";
    std::cout << "\n>> choice: ";
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        sortID(st, curr);
        break;
    case 2:
        sortName(st, curr);
        break;
    case 3:
        sortGender(st, curr);
        break;
    default:
        std::cout << "[!] You picked the wrong choice. Restart!\n";
        break;
    }
    std::ofstream write("sorted.csv");
    for (int i = 0; i < curr; i++)
        write << st[i].id << ',' << st[i].name << ',' << st[i].gender << ',' << st[i].dob << '\n';
    std::cout << "[!] Finished!\n";
    return 0;
}