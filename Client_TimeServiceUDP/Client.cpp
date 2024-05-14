#include "Client.h"
#define TIME_PORT	27015 


Client::Client()
{
	InitWinsock();
	CreateSocket();
	ConnectToServer();
}

Client::~Client()
{
	closesocket(connSocket);
	WSACleanup();
}

void Client::InitWinsock()
{
	// Initialize Winsock (Windows Sockets).
	WSAData wsaData;
	if (NO_ERROR != WSAStartup(MAKEWORD(2, 2), &wsaData)) //startup to load dll 
	{
		cout << "Time Client: Error at WSAStartup()\n";
		return;
	}
}
void Client::CreateSocket()
{
	// Create a socket and connect to an internet address.
	SOCKET connSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (INVALID_SOCKET == connSocket)
	{
		cout << "Time Client: Error at socket(): " << WSAGetLastError() << endl;
		WSACleanup();
		return;

	}
}
void Client::ConnectToServer()
{
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1"); // this address is "local host" or "loopback" (the same).
	server.sin_port = htons(TIME_PORT); //convert from big/small endian 
}


void Client::start()
{

}

