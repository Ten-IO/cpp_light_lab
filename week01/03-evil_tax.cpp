/*
  [+] A program to compute tax salary of a person. The program asks for name, gender and salary of a person
   and tell him/her how much tax he/she is required to pay. 
    The tax is computed based on the rules below:
 ▪ For males
    • Salary more than 1000 USD, pay tax 9.5%
    • Salary 500 – 1000 USD, pay tax 7%
    • Salary 300 – 500 USD, pay tax 5%
    • Salary less than 300, no need to pay tax
 ▪ For females
    • Salary more than 1000 USD, pay tax 8%
    • Salary 500 – 1000 USD, pay tax 6.5%
    • Salary 300 – 500 USD, pay tax 3.5%
    • Salary less than 300, no need to pay tax
*/
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
    string name;
    char gender;
    float salary = .2f;
    float tax = .2f;
    string valid = "mMFf";
    cout << "\n-- Evil Tax --\n";

    cout << "Please fill in:\n> name: ";
    getline(cin, name);
    cout << "> gender: ";
    cin.get(gender);
    cin.ignore();

    cout << "> salary: ";
    cin >> salary;
    if (salary >= 0 && salary <= 300)
        tax = 0;
    else
    {
        if (gender == 'm' || gender == 'M')
        {

            if (salary > 300 && salary <= 500)
                tax = 5;
            else if (salary > 500 && salary <= 1000)
                tax = 5;
            else if (salary > 1000)
                tax = 9.5;
        }
        if (gender == 'f' || gender == 'F')
        {

            if (salary > 300 && salary <= 500)
                tax = 3.5;
            else if (salary > 500 && salary <= 1000)
                tax = 6.5;
            else if (salary > 1000)
                tax = 8;
        }
    }

    if (salary < 0)
    {
        cerr << "invalid salary argument";
        return 1;
    }
    if (valid.find(gender) == string::npos)
    {
        cerr << "invalid gender argument";
        return 1;
    }
    printf("Greeting! %s.\nSince you are %c, Your tax is: %.2f %% amount to $ %.2f"
        , name.c_str(), gender, tax, salary * tax / 100); // c_string warn, bc it must not be modified or pointer will changes 
    return 0;
}