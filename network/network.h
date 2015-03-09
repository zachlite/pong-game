//
//  network.h
//  WebServer
//
//  Created by Zach Lite on 7/12/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#ifndef NETWORK_H
#define NETWORK_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <poll.h>
#include <stdbool.h>


typedef enum {SERVER, CLIENT} HostType_t;

typedef struct{
    char client_addr[INET6_ADDRSTRLEN];
    int new_client_fd;
}new_client;

//returns a file descriptor
int net_open(const char *host, const char *port, HostType_t hostType);


#endif
