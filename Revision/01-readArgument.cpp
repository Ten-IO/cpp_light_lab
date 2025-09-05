/*
    [+] Show how cpp accept argument.
*/
#include <iostream>
int main(int argc, char **argv)
{
    if (!(argc > 2))
        std::cout << "I'm lonely.\n";
    
    std::cout << "Argument Count: " << argc << '\n';
    std::cout << "Here are my token:\n";
    for (int i = 0; i < argc; i++)
        std::cout << "Token " << i + 1 << " : " << argv[i] << std::endl;
    return 0;
}