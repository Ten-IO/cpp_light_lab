#include <iostream>

int findMin(int a[], int n)
{
    if (n <= 0)
        return a[n];
    if (a[n] < a[n - 1])
    {
        a[n - 1] = a[n]; // std::cout << a[n-1]<<"-" << a[n]<<" ";
    }
    // std::cout << n;
    return findMin(a, n - 1);
}
int main()
{
    int arr[] = {299, -22, 32, 1, 2};
    std::cout << findMin(arr, sizeof(arr) / sizeof(arr[0]) - 1);
}