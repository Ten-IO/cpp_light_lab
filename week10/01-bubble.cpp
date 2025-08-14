/*
    [+] Write a C++ program to sort 5 integer numbers stored in an array from user input using bubble sort
        algorithm. Sort from smallest to largest and also sort from largest to smallest. Display result on screen.
*/
#include <iostream>
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void bubbleAscend(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = false;
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag = true;
            }
        if (!flag)
            break;
    }
}

void bubbleDescend(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = false;
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] < arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag = true;
            }
        if (!flag)
            break;
    }
}
int main()
{
    int num[] = {3, 1, 3, 5, 6};
    std::cout << "Ascend: ";
    bubbleAscend(num, sizeof(num) / sizeof(num[0]));
    for (int i:num)std::cout << i<<' ';
    std::cout << "\nDescend: ";
    bubbleDescend(num, sizeof(num) / sizeof(num[0]));
    for (int i:num)std::cout << i<<' ';
}