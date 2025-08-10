/*
 [+] Program add all the numbers input by a user until the user inputs zero. 
    Notice that a number is input one by one until user inputs zero, 
    then display the summation and stop the program.
*/
#include <iostream>
#include <vector>

using namespace std;

float sum(vector<float> arr)
    {
    float result = 0;
    for (float &i : arr)
    {
        result += i;
    }

    return result;
}

int main()
{
    vector<float> arr;
    cout << "== Addition Calculator == (0 to finalize the operation)" << endl;
    float i;

    while (i != 0)
    {
        cout << "Your input: ";
        cin >> i;
        if (cin.fail())
        {
            cout << "Incorrect input!" << endl;
            break;
        }
        arr.push_back(i);
    }

    cout << "\n\n>> Your result: " << sum(arr);
    system("pause");
}