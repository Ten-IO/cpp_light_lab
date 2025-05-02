#include <iostream>

using namespace std;

void printRowStar(int row)
{
    if (row == 0)
        return;
    cout << "*";
    return printRowStar(row - 1);
}
void starRC(int row, int col)
{
    if (col == 0)
    {
        return;
    }
    printRowStar(row);
    cout << endl;

    return starRC(row, col - 1);
}

int main()
{
    cout << "\n-- Star Printer --\n";
    starRC(4, 4);
}