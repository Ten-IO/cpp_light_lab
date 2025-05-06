#include <iostream>
using namespace std;
void display(const float *arr, int n)
{
    cout << "Your input: ";
    for (int i = 0; i < n; i++)
        cout << *(arr++) << " ";
}
float Sum(const float *arr, int n)
{
    if (n == 0)
        return 0;

    return Sum(arr + 1, n - 1) + *arr;
}
float Multiply(const float *arr, int n)
{
    if (n == 0)
        return 1;
    return Multiply(arr + 1, n - 1) * *arr;
}
int main()
{
    float *f = new float[10];
    int n = 0;
    cout << "-- input 7 numbers --\n";
    while (n < 7)
    {
        cout << n + 1 << " value: ";
        cin >> *(f++);
        n++;
    }
    f = f - 7;
    cout << "Summation: " << Sum(f, n);
    cout << "\nMultiplication: " << Multiply(f, n);
    delete[] f;
}