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
    int arr[7], *ptr = arr;
    for (int i = 0; i < 7; i++)
    {
        cout << ">> Your input: ";
        cin >> arr[i];
    }
    int max = sizeof(arr), min = sizeof(arr[0]);
    findMaxMin(ptr, &max, &min);
    cout << "max: " << max << " min: " << min;
}