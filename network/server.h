#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


class Server{

	public:
		Server(const char *h, const char *p);
		~Client();

		int Send(const char *data)

};



#endif
