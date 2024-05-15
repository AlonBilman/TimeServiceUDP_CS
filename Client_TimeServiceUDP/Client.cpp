#include "Client.h"
#include "RequestHandler.h"
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
	if (NO_ERROR != WSAStartup(MAKEWORD(2, 2), &wsaData)) //startup to load dll 
	{
		cout << "Client: Error at WSAStartup()\n";
		exit(0);
	}
}
void Client::CreateSocket()
{
	// Create a socket and connect to an internet address.
	connSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (INVALID_SOCKET == connSocket)
	{
		cout << "Client: Error at socket(): " << WSAGetLastError() << endl;
		WSACleanup();
		exit(0);

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
	bool finish = false;
	bool AlreadyAnswered = false;
	RequestHandler requestHandler(connSocket, server);
	char key;

	while (!finish)
	{
		requestHandler.sentRes(finish, AlreadyAnswered);

		if (!finish && !AlreadyAnswered)
			requestHandler.getReq();

		if (!finish)
		{
			std::cout << "\n\n To Continue press any key (and then enter). To exit press 0 : ";
			cin >> key;
			if (key == '0')
				finish = !finish;
		}

		AlreadyAnswered = false;
	}

}

