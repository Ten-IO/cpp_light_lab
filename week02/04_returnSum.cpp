#include <iostream>

int findsum(int a[], int n)
{
    if (n <= 0)
        return a[n];
    return (a[n] + findsum(a, n-1));
}
int main()
{
    int a[] = {2, 2, 3};
    std::cout << findsum(a, sizeof(a) / sizeof(a[0])-1);
}