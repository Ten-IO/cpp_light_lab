#include <iostream>
#include <cmath>

using namespace std;

void solveEquation(int a, int b, int c, float *x1, float *x2, float *delta)
{
    *delta = b * b - 4 * a * c;
    if (a == 0)
    {
        *x1 = *x2 = -c / b;
    }
    else
    {
        if (*delta > 0)
        {
            *x1 = -b + sqrtf(*delta) / (2 * a);
            *x2 = -b + -sqrtf(*delta) / (2 * a);
        }
        else if (*delta == 0)
        {
            *x1 = *x2 = -b / (2 * a);
        }
        else
        {
            cerr << "error: delta < 0, not supported yet";
        };
    }
}
int main()
{
    float x1 = 1.2f, x2 = 1.2f, delta;
    solveEquation(1, -2, 1, &x1, &x2, &delta);
    cout << x1 << " " << x2 << " " << delta;
}