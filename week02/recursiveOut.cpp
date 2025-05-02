// ONE case here: 1 loop = 1 recursive func.
// To create a row and col that iterate, it needs more const param to rely on or either create distinct func to handle them as the needed of 2 logical loop.

#include <iostream>
using namespace std;

void starSQ(int n)
{
    if (n == 0)
        return;

    cout << "*";
    if (n % 5 == 0)
        cout << " ";
    return starSQ(n - 1);
}
void starRC(int r, int c, const int a)
{
    if (c == 0)
        return;
    cout << "*";
    if (r == 1)
    {
        r = a;
        cout << endl;
        return starRC(r, c - 1, a);
    }
    return starRC(r - 1, c, a);
}

void starRC(int r, int c)
{

    if (r <= 0)
        return;
    cout << "*";
    if (c % r == 0)
    {
        cout << endl;
    }
    return starRC(r - 1, c + 1);
}

void DecrementstarRC(int r, int c)
{

    if (c <= 0)
        cout << "*";
    return;
    if (r <= 1)
    {
        r += c;
        cout << endl;
        return DecrementstarRC(r, c - 1);
    }
    return DecrementstarRC(r - 1, c);
}
int main()
{
    system("cls");
    // cout << "3 params\n";
    // starRC(4, 2, 4);
    // cout << "\n2 params\n";
    starRC(4, 2);
    // starSQ(3);
}
