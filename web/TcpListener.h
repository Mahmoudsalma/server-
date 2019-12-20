#pragma once
#include <iostream>
#include <WS2tcpip.h>
#include <string>
#include <sstream>

#pragma comment (lib, "ws2_32.lib")
class TcpListener

{

public :
	TcpListener(const char* ipAddress, int port):
	   m_ipAddress(ipAddress), m_port(port) {
	
	}
	    // initialize the listener 
	int init();
		// run the listener 
	int run();

protected :
	//Handler for client connections 
    virtual  void    onClientConnected();
	//Handler for client disconnections 
	virtual void    onClientDisconnected();
	// Handler for when a message received from the client 
	virtual void onMessageReceived(int clientSocket, const char*msg, int length);
	//send a message to a client 
	void    sentToClient(int clientSocket , const char * msg, int length );
    //Broad cast a message from a client 
	void    BroadcastToClient(int sendingclient, const char * msg, int length);
	



	
private :
	const char*      m_ipAddress; //Ip Address will be run on 
	int              m_port;       // port # for the web service 
	int              m_socket;   // Internal FD for the listening socket 
	fd_set           master;      //Master file descriptor set 




};
