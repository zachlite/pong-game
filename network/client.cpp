//initialize

//connect

//listen for data

//send data
#include "network.h"
#include "client.h"

Client::Client(const char *h, const char *p){

	host = h;
	port = p;

	file_descriptor = InitializeNetwork();

	if (file_descriptor == -1)
		exit(EXIT_FAILURE);
}

int Client::InitializeNetwork(){
	//get ur file descriptor!
	return net_open(host, port, CLIENT);
}


int Client::Send(const char * data){

	if (!file_descriptor)
	{
		fprintf(stderr, "client file descriptor has not been set\n");
		return -1;
	}

	printf("file_descriptor of client is %d\n", file_descriptor);
	printf("will send data %s\n", data);
	 // send(file_descriptor, data, sizeof(data), 0);

}
