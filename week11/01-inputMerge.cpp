/*
    [+] Write a C++ program to sort 5 integer numbers stored in an array from user input using Merge sort
        algorithm. Sort from smallest to largest and also sort from largest to smallest. Display result on screen.
*/

#include <iostream>
void mergeAscend(int arr[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = 0;
    int n = ub - lb + 1;
    int b[n];
    while (i <= mid && j <= ub)
    {
        if (arr[i] < arr[j])
            b[k++] = arr[i++];
        else
            b[k++] = arr[j++];
    }
    while (i <= mid)
        b[k++] = arr[i++];
    while (j <= ub)
        b[k++] = arr[j++];
    for (k = 0; k < n; k++)
        arr[lb + k] = b[k];
}
void mergeDescend(int arr[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = 0;
    int n = ub - lb + 1;
    int b[n];
    while (i <= mid && j <= ub)
    {
        if (arr[i] > arr[j])
            b[k++] = arr[i++];
        else
            b[k++] = arr[j++];
    }
    while (i <= mid)
        b[k++] = arr[i++];
    while (j <= ub)
        b[k++] = arr[j++];
    for (k = 0; k < n; k++)
        arr[lb + k] = b[k];
}
void mergeSort(int a[], int lb, int ub, bool asc_Def)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        mergeSort(a, lb, mid, asc_Def);
        mergeSort(a, mid + 1, ub, asc_Def);
        if (asc_Def)
            mergeAscend(a, lb, mid, ub);
        else
            mergeDescend(a, lb, mid, ub);
    }
}
int main()
{
    int sz = 5, num[sz];
    for (int i = 0; i < sz; i++)
    {
        std::cout << "Input #" << i+1 << ": ";
        std::cin >> num[i];
    }
    bool asc;
    std::cout << "Ascend: ";
    asc = true;
    mergeSort(num, 0, sz - 1, asc);
    for (int i : num)
        std::cout << i << " ";
    std::cout << "\nDescend: ";
    asc = false;
    mergeSort(num, 0, sz - 1, asc);
    for (int i : num)
        std::cout << i << " ";
}