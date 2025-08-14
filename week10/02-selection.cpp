/*
    [+] Read data from the txt file below and store in an array. Sort that array using the selection sort algorithms
        and write sorted array into new files namely selection.txt.
*/
#include <iostream>
#include <fstream>
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void selectionAscend(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        if (minIndex != i)
            swap(&arr[i], &arr[minIndex]);
    }
}
void selectionDescend(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] > arr[minIndex])
                minIndex = j;
        if (minIndex != i)
            swap(&arr[i], &arr[minIndex]);
    }
}

int main()
{
    int num[] = {3, 1, 3, 5, 6};
    std::cout << "Ascend: ";
    selectionAscend(num, sizeof(num) / sizeof(num[0]));
    for (int i : num)
        std::cout << i << ' ';
    std::cout << "\nDescend: ";
    selectionDescend(num, sizeof(num) / sizeof(num[0]));
    for (int i : num)
        std::cout << i << ' ';

    int SIZE = 10, curr = 0, arr[SIZE];
    std::ifstream read("sample.txt");
    if (!read)
    {
        std::cerr << "[!] Unable to open file\n";
        return 1;
    }
    while (  curr < SIZE&&read >> arr[curr])
        curr++;
    read.close();
    std::cout << "\nFrom file: ";
    // for (int i : arr)
    // std::cout << i << ' ';

    for (int i=0; i < curr; i++)
        std::cout << arr[i] << ' ';

    selectionAscend(arr, curr);
    std::cout << "\nSort: ";
    
    /* Bad practice, since we have holes of spaces*/
    // for (int i : arr)
    //     std::cout << i << ' ';

    for (int i=0; i < curr; i++)
        std::cout << arr[i] << ' ';

    std::ofstream write("selection.txt");
    for (int i=0; i < curr; i++)
        write << arr[i] << '\n';
}
