#include <iostream>

using namespace std;

void mergeSort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        mergeSort(a[], lb, mid);
        mergeSort(a[], mid + 1, ub);
        merge(a[], lb, mid, ub);
    }
}
void merge(int a[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = 0;
    int n = ub - lb + 1;
    int b[n];

    while (i <= mid && j <= ub)
    {
        if (a[i]< a[j])
            b[k++] = b[i];
        else
            b[k++] = b[j];

        while (i <= mid)
            b[k++] = a[i++];
        while (j <= ub)
            b[k++] = a[j++];

        for (k = 0; k < n; k++)
            a[lb + k] = b[k];
    }
}
void show(int a[], int size)
{
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";
}
int main()
{
    int a[] = {1, 2, 23, 5, 4, 2};
    int n = sizeof(a) / sizeof(a[0]);
    show(a, n);
        
    mergeSort(a[], 0, n);
    show(a, n);
}