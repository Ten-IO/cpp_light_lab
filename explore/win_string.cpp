#include <iostream>
#include <windows.h>

int main()
{
    LPCSTR ansiString = "hello ANSI";
    LPCWSTR wideString = L"hello Unicode";

    MessageBoxA(NULL, ansiString, "Title", MB_OK);
    MessageBoxW(NULL, wideString, L"Title", MB_OK);
}