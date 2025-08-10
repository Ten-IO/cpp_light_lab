/* [+] Program check input character is a vowel or a consonant. Hint: Use ASCII code to test condition.
        ▪ Uppercase letters from: 65 to 90, lowercase letters from 97 to 122
        ▪ Vowel and its ASCII code: a = 97, e = 101, i = 105, o = 111, u = 117
*/
#include <iostream>
using namespace std;

int main()
{
    char input;

    while (true)
    {
        cout << "-- Alphabet Checker --\n>> ";
        cin >> input;

        int ascii = (char)input;
        input += 32;
        if (input == 97 || input == 101 || input == 105 || input == 111 || input == 117)
            cout << "vowel: ";
        else
            cout << "consonant: ";
        cout << char(ascii) << " int: " << ascii << endl;

        if (ascii >= 65 && ascii <= 90)
            cout << " (uppercase)\n";
        else if (ascii >= 97 && ascii <= 122)
            cout << " (lowercase)\n";
        else
        {
            cout << " (Input is not an alphabet)\n";
            return 1;
        }
        system("pause");
        system("cls");
    }
    return 0;
}