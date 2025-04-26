// Write a C++ program to convert a minute to a time format which consists of hour, minute, and 
// second (h:m:s). A user is required to input a minute.  
// ▪ Hours = minutes / 60 
// ▪ Remainderminutes = minutes % 60 
// ▪ Seconds = remainderminutes * 60 

#include <iostream>
using namespace std;

int main()
{
    double minutes;
    cout << "-- Time H-M-S --\n";
    cout << "Enter minutes: ";
    cin >> minutes;

    int hours = minutes / 60;
    int remainMinutes = minutes % 60;
    int seconds = remainMinutes * 60;

    cout << "Time format is " << hours << " hours : " << remainMinutes << " minutes : " << seconds << " seconds.\n";

    return 0;
}
