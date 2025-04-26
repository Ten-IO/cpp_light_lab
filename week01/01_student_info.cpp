/* 
Write a C++ program to ask information from a student such as name, gender, major, age then 
display the greeting message on screen.  Say he/she is eligible to vote the election if the age is at 
least 18. 
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Student_info
{
    string name, major;
    char gender;
    int age = 0;
};

int main()
{
    Student_info db;

    cout << "-- Privacy Collector --" << endl;
    cout << "Choose \'m\' - for male and \'f\' - for female\n> ";
    cin >> db.gender;

    cout << "What is your name?\n> ";
    cin.ignore();
    getline(cin, db.name);
    cout << "May we know your age?\n> ";
    cin >> db.age;
    cout << "What major are you currently in?\n> ";
    cin.ignore();
    getline(cin, db.major);

    system("cls");

    if (db.gender == 'm' || db.gender == 'M')
        cout << "Response: Hi! " << db.name << ". Your age is " << db.age << " years old and you learn in " << db.major << "! field.\n";
    else if (db.gender == 'f' || db.gender == 'F')
        cout << "Response: Hi! " << db.name << ". Your age is " << db.age << " years old and you are majoring in " << db.major << "! field.\n";
    else
        return 1;

    if (db.age >= 18)
        cout << "FYI: You can vote.\n";
    else
        cout << "FYI: You cannot vote.\n";
    system("pause");

    return 0;
}
