#include <iostream>
using namespace std;
void exchange(float *a, float *b)
{
    float temp = *b;
    *b = *a;
    *a = temp;
}
int main()
{
    float a = 12.21, b = 22.1;
    exchange(&a, &b);
    cout << a << " " << b;
}