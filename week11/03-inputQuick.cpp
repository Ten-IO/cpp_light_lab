
/*
    [+] Write a C++ program to sort 5 integer numbers stored in an array from user input using Quick sort
        algorithm. Sort from largest to smallest. Display result on screen.
*/
#include <iostream>

using namespace std;

int partitionA(int a[], int lb, int ub);
int partitionD(int a[], int lb, int ub);
void QuickSort(int a[], int lb, int ub, bool asc_DEF)
{
    if (lb < ub)
    {
        int pos;
        if (asc_DEF)
            pos = partitionA(a, lb, ub);
        else
            pos = partitionD(a, lb, ub);
        QuickSort(a, lb, pos - 1, asc_DEF);
        QuickSort(a, pos + 1, ub, asc_DEF);
    }
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int partitionA(int a[], int lb, int ub)
{
    int pivot = a[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while (a[start] <= pivot && start <= ub)
            start++;
        while (a[end] > pivot && end >= lb)
            end--;

        if (start < end)
            swap(a[start], a[end]);
    }
    swap(a[lb], a[end]);
    return end;
}
int partitionD(int a[], int lb, int ub)
{
    int pivot = a[lb], start = lb, end = ub;
    while (start < end)
    {
        while (a[start] >= pivot && start <= ub)
            start++;
        while (a[end] < pivot && end >= lb)
            end--;
        if (start < end)
            swap(a[start], a[end]);
    }
    swap(a[lb], a[end]);
    return end;
}
int main()
{
    int sz = 5, num[sz];
    for (int i = 0; i < sz; i++)
    {
        std::cout << "Input #" << i + 1 << ": ";
        std::cin >> num[i];
    }
    bool asc;
    std::cout << "Ascend: ";
    asc = true;
    QuickSort(num, 0, sz - 1, asc);
    for (int i : num)
        std::cout << i << " ";
    std::cout << "\nDescend: ";
    asc = false;
    QuickSort(num, 0, sz - 1, asc);
    for (int i : num)
        std::cout << i << " ";
}