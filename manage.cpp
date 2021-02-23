#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <windows.h>
#pragma comment(lib, "IPHLPAPI.lib")
#pragma comment(lib, "Ws2_32.lib")
//Add and remove IP addresses. The gui equivelent is control panel -> Network settings -> Change adapters settings -> IPV4 configuration
//cl manage.c && manage.exe
int main()
{
	ULONG NTEContext = 0;
	ULONG NTEInstance = 0;
	UINT iaIPAddress;
	UINT iaIPMask;
	DWORD dwRetVal;
	MIB_IPADDRTABLE *pIPAddrTable;
	DWORD dwSize = 0;
	iaIPAddress = inet_addr("10.0.1.4");
	iaIPMask = inet_addr("255.0.0.0");
	pIPAddrTable = (MIB_IPADDRTABLE*) malloc(sizeof(MIB_IPADDRTABLE));
	if (GetIpAddrTable(pIPAddrTable, &dwSize, 0) == ERROR_INSUFFICIENT_BUFFER) {
		free(pIPAddrTable);
		pIPAddrTable = (MIB_IPADDRTABLE *) malloc(dwSize);
	}
	if ((dwRetVal = GetIpAddrTable(pIPAddrTable, &dwSize, 0)) != NO_ERROR) {
		printf("GetIPAddrTable call failed with %d\n", dwRetVal);
	}
	//table[x] x = adapter#
	dwRetVal = AddIPAddress(iaIPAddress, iaIPMask, pIPAddrTable->table[0].dwIndex, &NTEContext, &NTEInstance);
	if (dwRetVal != NO_ERROR) {
		printf("AddIPAddress call failed with %d\n", dwRetVal);
	}
	if (dwRetVal = 5010) {
			printf("The error code 5010 means the IP address is already assigned to the interface");
		}
	if (pIPAddrTable)
        free(pIPAddrTable);
	//printf(iaIPAddress);
}
