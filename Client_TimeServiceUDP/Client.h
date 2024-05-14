#pragma once

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
using namespace std;
#pragma comment(lib, "Ws2_32.lib")
#include <winsock2.h> 
#include <string.h>


class Client
{
private:
	SOCKET connSocket;
	WSAData wsaData;
	sockaddr_in server;

public:
	Client();
	~Client();
	void InitWinsock();
	void CreateSocket();
	void ConnectToServer();
	void start();
};