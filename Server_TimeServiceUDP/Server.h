#pragma once
using namespace std;
#pragma comment(lib, "Ws2_32.lib")
#include <iostream>
#include <winsock2.h>
#include <string.h>
#include <time.h>
#include "RequestHandler.h"

class Server
{
private:
	SOCKET m_socket;
	WSAData wsaData;
	sockaddr_in serverService;

public:
	Server();
	~Server();
	void Start();
	void InitWinsock();
	void CreateSocket();
	void BindSocket();
	

};