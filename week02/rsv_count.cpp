#include <iostream>
using namespace std;

int fun(int n, int &count)
{
    count++;
    if (n <= 1)
        return n;
    else
        return fun(n - 1, count) + fun(n - 2, count);
}
int main()
{
    int count = 0;
    cout << fun(5, count) << endl;
    cout << "count: " << count << endl;
    return 0;
}