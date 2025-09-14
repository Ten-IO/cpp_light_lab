/*
    [+] Q5. Define a struct Student with fields name and score, then
        use a pointer to access and modify its members.
*/
#include <iostream>
struct Student
{
    std::string name;
    float score;
};
int main()
{
    Student *_s = new Student{"Nida", 88.912};
    std::cout << "Student: " << _s->name << "\nScore: " << _s->score << '\n';
    try
    {
        _s->name = "Ola";
        (*_s).score = 98.912;
        std::cout << "\n[+] Changed\n";
        std::cout << "Student: " << _s->name << "\nScore: " << _s->score;
    }
    catch (...)
    {
        std::cerr << "\n[!] Something is wrong and nothing changes.\n";
    }
    return 0;
}