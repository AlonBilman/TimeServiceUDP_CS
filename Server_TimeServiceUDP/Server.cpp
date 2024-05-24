#include "Server.h"
#define TIME_PORT	27015


Server::Server()
{
	InitWinsock();
	CreateSocket();
	BindSocket();
}

void Server::InitWinsock()
{
	if (NO_ERROR != WSAStartup(MAKEWORD(2, 2), &wsaData)) {
		std::cerr << "Error at WSAStartup()\n";
		exit(-1);
	}
}

void Server::CreateSocket()
{
	m_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (INVALID_SOCKET == m_socket) //check for errors
	{
		cout << "Server: Error at socket(): " << WSAGetLastError() << endl;
		WSACleanup();
		exit(-1);
	}
}

void Server::BindSocket()
{
	serverService.sin_family = AF_INET;
	serverService.sin_addr.s_addr = INADDR_ANY;	//inet_addr("127.0.0.1");
	serverService.sin_port = htons(TIME_PORT);
	if (SOCKET_ERROR == bind(m_socket, (SOCKADDR*)&serverService, sizeof(serverService)))
	{
		cout << "Server: Error at bind(): " << WSAGetLastError() << endl;
		closesocket(m_socket);
		WSACleanup();
		exit(-1);
	}
}

Server::~Server() 
{
	closesocket(m_socket);
	WSACleanup();
}


void Server::Start()
{
	RequestHandler requestHandler(m_socket);
	TimeService timeService(requestHandler.recvBuff, requestHandler.sendBuff);

	while (true)
	{
		requestHandler.getReq(); //get the req from the client. 
		timeService.updateAnswer();  //Updating the answer
		requestHandler.sentRes(); // Sends the answer to the client
	}
}


