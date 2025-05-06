#include <iostream>
using namespace std;

void findMaxMin(int *arr, int *max, int *min)
{
    int size = *max / *min;
    *max = *arr;
    *min = *arr;
    for (int i = 0; i < size; i++)
    {
        if (*max > *arr)
            *max = *arr;
        if (*min < *arr)
            *min = *arr;
        arr += 1;
    }
}
int main()
{
    int arr[] = {2, 4, 1, 3}, *ptr = arr;
    int max = sizeof(arr), min = sizeof(arr[0]);
    findMaxMin(ptr, &max, &min);
    cout << "max: " << max << " min: " << min;
}