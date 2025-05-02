#include <iostream>
using namespace std;
int power(int m, int n)
{
    if (n == 0)
        return 1;
    return m * power(m, n - 1);
}
int main()
{
    cout << power (10,3);
}