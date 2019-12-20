#pragma once
#include "TcpListener.h"

class MultiClientChat : puplic TcpListener
{


puplic :
	MultiClientChat(const char * ipAddress, int port) :
		TcpListener(ipAddress, port) {}

protected :
	//Handler for client connections 
	virtual  void    onClientConnected();
	//Handler for client disconnections 
	virtual void    onClientDisconnected();
	// Handler for when a message received from the client 
	virtual void onMessageReceived(int clientSocket, const char*msg, int length);


};