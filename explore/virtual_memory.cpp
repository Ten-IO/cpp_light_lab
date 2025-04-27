#include <windows.h>
#include <stdio.h>
#include <iostream>
#include "qprint.h"

// virtual mem : create by disk
int main() {
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);
    DWORDLONG totalVirtualMem = memInfo.ullAvailPageFile;
    
    print("memory info", memInfo.dwLength, "bit");
    print("vitual mem", totalVirtualMem, "byte");
    print("vitual mem", convMB(totalVirtualMem), "MB");
    return 0;

}
