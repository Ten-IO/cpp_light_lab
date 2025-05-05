#include <iostream>
using namespace std;

void assignPoint(int **p, int *n)
{
    *p = n;
    cout << p << " " << n << endl;
}
void assignPoint(int *&p, int &n)
{
    p = &n;
}

int main()
{
    int n1 = 7, n2 = 3, n3 = 15;
    int *p1, *p2, *p3;
    cout << p1 << " " << p2 << " " << p3 << endl;

    assignPoint(&p1, &n1);
    assignPoint(&p2, &n2);
    assignPoint(&p3, &n3);
    
    cout << *p1 << " " << *p2 << " " << *p3;
    assignPoint(p1, n1);
    assignPoint(p2, n2);
    assignPoint(p3, n3);
    cout << *p1 << " " << *p2 << " " << *p3;
}