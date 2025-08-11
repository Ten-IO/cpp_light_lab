/*
    Reverse Recursive Display
*/
#include <iostream>
void display(int n)
{
    if (n == 0)
        return;
    else
    {
        display(n - 1); // call self-recursive, when meet base n==0, it starts the std::cout under here.
        std::cout << n << " ";
    }
}
int main()
{
    display(10);
    return 0;
}