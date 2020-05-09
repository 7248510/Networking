#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
//compile tags with -lws2_32
int main()
{
    WSADATA d;
    if (WSAStartup(MAKEWORD(2,2), &d)) 
    {
        printf("Failed to initialize.");
        return -1;
    }
    //0 = Okay/If function returns 0 then everything is okay.
    WSACleanup();
    printf("Okay");
    return 0;
}