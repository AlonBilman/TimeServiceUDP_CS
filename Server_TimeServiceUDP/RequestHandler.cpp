#include "RequestHandler.h"


void RequestHandler::getReq()
{
	bytesRecv = recvfrom(m_socket, recvBuff, 255, 0, &client_addr, &client_addr_len);
	RecieveErrorCheck();
	recvBuff[bytesRecv] = '\0'; //add the null-terminating to make it a string
	cout << "Server: Recieved: " << bytesRecv << " bytes of \"" << recvBuff << "\" message.\n";


}
void RequestHandler::sentRes()
{
	bytesSent = sendto(m_socket, sendBuff, (int)strlen(sendBuff), 0, (const sockaddr*)&client_addr, client_addr_len);
	SentErrorCheck();
	cout << "Server: Sent: " << bytesSent << "\\" << strlen(sendBuff) << " bytes of \"" << sendBuff << "\" message.\n";
}
void RequestHandler::SentErrorCheck()
{
	if (SOCKET_ERROR == bytesSent)
	{
		cout << "Server: Error at sendto(): " << WSAGetLastError() << endl;
		closesocket(m_socket);
		WSACleanup();
		exit(0);
	}
}
void RequestHandler::RecieveErrorCheck()
{
	if (SOCKET_ERROR == bytesRecv)
	{
		cout << "Server: Error at recvfrom(): " << WSAGetLastError() << endl;
		closesocket(m_socket);
		WSACleanup();
		return;
	}
}