#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include "network.h"

// int cli(const char *PORT);
// void close_client();void cli_send_to_server(int sockfd);

class Client{
	
	public:
		Client(const char *h, const char *p);
		~Client();

		int Send(const char *data);
		void Receive();

	private:
		int InitializeNetwork();

		int file_descriptor;	
		const char *host;
		const char *port;
};


#endif