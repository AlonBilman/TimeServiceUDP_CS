#pragma once
#include "Server.h"
#include "TimeService.h"

class RequestHandler
{
private: 
	SOCKET m_socket;

public:
	RequestHandler(SOCKET socket) : m_socket(socket) { cout << "Time Server: Wait for clients' requests.\n"; }

	sockaddr client_addr;
	int client_addr_len = sizeof(client_addr);
	int bytesSent = 0;
	int bytesRecv = 0;
	char sendBuff[255]="0";
	char recvBuff[255]="0";
	void getReq();
	void sentRes();
	void SentErrorCheck();
	void RecieveErrorCheck();

};

