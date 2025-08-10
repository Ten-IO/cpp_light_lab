/* 
 [+] Write a program to reverse the contents of a 1D array.
    Example:
   ▪ Input : 1 2 3 4 5 6
   ▪ Output : 6 5 4 3 2 1
*/
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << "Init array: {";
    for (int i : arr)
    {
        cout << i;
        if (i != (sizeof(arr) / sizeof(arr[0])))
            cout << ", ";
    }
    cout << "}\n> reverse: {";
    for (int i = (sizeof(arr) / sizeof(arr[0]) - 1); i >= 0; i--)
    {
        cout << arr[i];
        if (i != 0)
            cout << ", ";
    }
    cout << "}" << endl;
    system("pause");
}