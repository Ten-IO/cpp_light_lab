#include <iostream>
using namespace std;
int main()
{
    int *p = nullptr;
    // cout << p << " " << *p << endl; // since *p is null(0), 
    //it will crash on runtime, if we try stream out

    int x = 100;
    p = &x;
    int **pp = &p;
    cout << **pp;
    return 0;
}
