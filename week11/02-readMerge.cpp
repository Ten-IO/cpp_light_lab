/*
    [+] Read data from the txt file below and store in an array. Sort that array using the Merge sort algorithms
        and write sorted array into new files namely selection.txt.
*/
#include <iostream>
#include <fstream>
void merge(int arr[], int lb, int mid, int ub)
{
    int i = lb, j = mid + 1, k = 0, n = ub - lb + 1, b[n];
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
    for (int k = 0; k < n; k++)
        arr[lb + k] = b[k];
}
void mergeSort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}
int main()
{
    int curr = 0, sz = 10, arr[sz];
    std::fstream read("sample.txt");
    if (!read)
    {
        std::cerr << "[!] Cannot read file sample.txt";
        return 1;
    }
    std::ofstream write("selection.txt");
    while (read >> arr[curr] && curr < sz)
        curr++;
    read.close();
    std::cout << "[+] From file: ";
    for (int i : arr)
        std::cout << i << ' ';
    mergeSort(arr, 0, sz - 1);
    std::cout << "\n[+] Sorted: ";
    for (int i : arr)
        std::cout << i << ' ';
    for (int i : arr)
        write << i << '\n';
    std::cout << "\n[+] Wrote!";
}