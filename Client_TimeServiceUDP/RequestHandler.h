#pragma once
#include "Client.h"
#include "Menu.h"

class RequestHandler
{
private:
	SOCKET connSocket;
	sockaddr_in server;
	
public:
	RequestHandler(SOCKET socket, sockaddr_in serverAd):connSocket(socket), server(serverAd) {}

	int bytesSent = 0;
	int bytesRecv = 0;
	char sendBuff[255] = "0";
	char recvBuff[255]= "0"; 

	void getReq();
	void sentRes();
	void SentErrorCheck();
	void RecieveErrorCheck();
	void Menu();
};

