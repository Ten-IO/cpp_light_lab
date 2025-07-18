#include <iostream>

using namespace std;

int partition(int a[], int lb, int ub);
int QuickSort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int pos = partition(a, lb, ub);
        QuickSort(a, lb, pos - 1);
        QuickSort(a, pos + 1, ub);
    }
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int partition(int a[], int lb, int ub)
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
        swap(a[lb], a[end]);
    }
}
int main()
{
    int a[]={2,1,3,3,2,12,3};

}