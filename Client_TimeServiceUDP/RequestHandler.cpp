#define _CRT_SECURE_NO_WARNINGS
#include "RequestHandler.h"
#include "Menu.h"
#include <iostream>
#include <string>
#include "RequestType.h"
#include "vector"

void RequestHandler::getReq()
{
	// Gets the server's answer using simple recieve (no need to hold the server's address).
	bytesRecv = recv(connSocket, recvBuff, 255, 0); 
	recvBuff[bytesRecv] = '\0'; //add the null-terminating to make it a string
	cout << "Client: Recieved: " << bytesRecv << " bytes of \"" << recvBuff << "\" message.\n";
}

void RequestHandler::sentRes(bool& finish,bool& Answered)
{
	int choice = Menu::printMenu();

	if (choice == (int)RequestType::Exit) { cout << "\nbye!!!\n"; finish = true; return;}// If we want to end the communication

	else if (choice == (int)RequestType::CalcRTT) { RTT_calc(); Answered = true; return; }//If we want the client to calculate RTT + flag that we answered the question already.	

	else if (choice == (int)RequestType::CalcDelay) { Client_delay(); Answered = true; return; }//If we want the client to calculate Delay + flag that we answered the question already.	

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
		exit(0);
	}
}

void RequestHandler::RecieveErrorCheck()
{
	if (SOCKET_ERROR == bytesRecv)
	{
		cout << "Client: Error at recv(): " << WSAGetLastError() << endl;
		closesocket(connSocket);
		WSACleanup();
		exit(0);
	}
}

void RequestHandler::RTT_calc() //sould I start the measure before the sendto command or after???
{
	char WhatsTheTime[] = "1"; // the question "whats the time" in the protocol is "1". 
	unsigned int calc = 0; //about 49 days at the maxinum measure, ofc its more than enough
	unsigned int currQTime = 0;
	unsigned int sendTime = 0;

	for (int i = 0; i < LoopForRttMeasure; i++)
	{
		sendTime = GetTickCount();
		bytesSent = sendto(connSocket, WhatsTheTime, sizeof(WhatsTheTime), 0, (const sockaddr*)&server, sizeof(server));
		getReq();
		currQTime = GetTickCount();
		calc += currQTime - sendTime;
	}
		std::cout << "\n\n==================================================================";
		std::cout << "\n\nThe RTT time (average of 100 requests and responses) is: " << (static_cast<double>(calc) / LoopForRttMeasure)<<" milliseconds";
}

void RequestHandler::Client_delay()
{
	std::vector<double> TimesToHold;
	char DelayEst[] = "4";
	double avg_answer=0;

	for (int i = 0; i < (int)RequestType::DelayLoopNum; i++) //100 requests in a row
	{
		sendto(connSocket, DelayEst, sizeof(DelayEst), 0, (const sockaddr*)&server, sizeof(server)); 
	}

	for (int i = 0; i < (int)RequestType::DelayLoopNum; i++) 
	{
		getReq(); // get the answer -> put it in recvBuff
		TimesToHold.push_back(static_cast<double>(stoi(recvBuff))); //push inside all the time stamps
	}

	//calculating the avg 
	for (int i = 0; i < (int)RequestType::DelayLoopNum - 1; i++) 
		avg_answer += TimesToHold[i+1] - TimesToHold[i];

	std::cout << "\n\n==================================================================";
	cout << "\n\nThe Client To Server Delay Estimation is : " << avg_answer/ (double)RequestType::DelayLoopNum<<" milliseconds";
}
	