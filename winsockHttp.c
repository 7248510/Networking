//Sample program request http with Winsock||Instead of a get request this program could be used to communicate with an TCP server
//https://docs.microsoft.com/en-us/windows/win32/winsock/getting-started-with-winsock
//cl /EHsc /sdl /W4 /TC winsockData.c && winsockData.exe
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma comment(lib, "Ws2_32.lib")

int main() {
    WSADATA wsaData;
    int iResult; //Check for error etc
    //Init winsock
    int recvbuflen = 512;
    const char *sendbuf = "GET / HTTP/1.0\r\n\r\n";
    char recvbuf[512];
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        return EXIT_FAILURE;
    }
    struct addrinfo *result = NULL, *ptr = NULL, hints;
    ZeroMemory( &hints, sizeof(hints) );
    hints.ai_family = AF_INET; //IPV4
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP; //TCP
    iResult = getaddrinfo("127.0.0.1", "3000", &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed: %d\n", iResult);
        WSACleanup();
        return 1;
    }
    SOCKET ConnectSocket = INVALID_SOCKET;
        // Attempt to connect to the first address returned by
    // the call to getaddrinfo
    ptr=result;
    // Create a SOCKET for connecting to server
    ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
    if (ConnectSocket == INVALID_SOCKET) {
        printf("Error at socket(): %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return EXIT_FAILURE;
    }
    // Connect to server.
    iResult = connect( ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        closesocket(ConnectSocket);
        ConnectSocket = INVALID_SOCKET;
    }

    // Should really try the next address returned by getaddrinfo
    // if the connect call failed
    // But for this simple example we just free the resources
    // returned by getaddrinfo and print an error message

    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        return 1;
    }
    // Send an initial buffer
    iResult = send(ConnectSocket, sendbuf, (int) strlen(sendbuf), 0);
    if (iResult == SOCKET_ERROR) {
        printf("send failed: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }
    printf("\nBytes Sent: %ld\n", iResult);
    // shutdown the connection for sending since no more data will be sent
    // the client can still use the ConnectSocket for receiving data
    iResult = shutdown(ConnectSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }
    iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
    if (iResult > 0)
        printf("Bytes received: %d\n", iResult);
    else if (iResult == 0)
        printf("Connection closed\n");
    else
        printf("recv failed: %d\n", WSAGetLastError());
    printf("%s",recvbuf); //The string is not formatted correctly. There may be random symbols do to it lacking a null terminator.

    //cleanup(call a destructor in C++)
    closesocket(ConnectSocket);
    WSACleanup();
  return 0;
}
