#include <iostream>
using namespace std;

void sum1(double *sum, int n)
{
    if (n == 0)
        return;
    *sum += 1.0 / (n * 10 + 2);
    sum1(sum, n - 1);
}
int main()
{
    double result;

    sum1(&result, 5);
    cout << result << endl;
    return 0;
}