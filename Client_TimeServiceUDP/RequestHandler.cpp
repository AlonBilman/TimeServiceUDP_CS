#define _CRT_SECURE_NO_WARNINGS
#include "RequestHandler.h"
#include "Menu.h"
#include <iostream>
#include <string>


void RequestHandler::getReq()
{
	// Gets the server's answer using simple recieve (no need to hold the server's address).
	bytesRecv = recv(connSocket, recvBuff, 255, 0); 
	recvBuff[bytesRecv] = '\0'; //add the null-terminating to make it a string
	cout << "Client: Recieved: " << bytesRecv << " bytes of \"" << recvBuff << "\" message.\n";
}
void RequestHandler::sentRes(bool& finish)
{
	int choice = Menu::printMenu();
	if (choice == 0) // If we want to end the communication
	{
		cout << "\nbye!!!\n";
		finish = true;
		return;
	}
	// Convert the integer choice to a string, had to do it like that for some reason...
	std::string choiceStr = std::to_string(choice);
	strcpy(sendBuff, choiceStr.c_str());

	bytesSent = sendto(connSocket, sendBuff, (int)strlen(sendBuff), 0, (const sockaddr*)&server, sizeof(server));
	cout << "Client: Sent: " << bytesSent << "/" << strlen(sendBuff) << " bytes of \"" << sendBuff << "\" message.\n";
}
void RequestHandler::SentErrorCheck()
{
	if (SOCKET_ERROR == bytesSent)
	{
		cout << "Client: Error at sendto(): " << WSAGetLastError() << endl;
		closesocket(connSocket);
		WSACleanup();
		return;
	}
}

void RequestHandler::RecieveErrorCheck()
{
	if (SOCKET_ERROR == bytesRecv)
	{
		cout << "Client: Error at recv(): " << WSAGetLastError() << endl;
		closesocket(connSocket);
		WSACleanup();
		return;
	}
}

