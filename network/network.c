//
//  network.c
//  WebServer
//
//  Created by Zach Lite on 7/10/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "network.h"




int net_open(const char *host, const char *port, HostType_t hostType)
{
    
    int sockfd;
    struct addrinfo hints, *netinfo;
    
    
    //initialize socket structures
    memset(&hints, 0, sizeof(hints));
    
    hints.ai_family = AF_INET; //IPv4 or IPv6 indifferent.
    hints.ai_socktype = SOCK_STREAM; //TCP stream sockets
    hints.ai_flags = AI_PASSIVE; //fill in my IP for me
    
    int getaddrerror;
    if ((getaddrerror = getaddrinfo(host, port, &hints, &netinfo) != 0))
    {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(getaddrerror));
        return -1;
    }
    

    
    //create socket
    sockfd = socket(netinfo->ai_family, netinfo->ai_socktype, netinfo->ai_protocol); //returns a socket descriptor!
    if (sockfd == -1)
    {
        fprintf(stderr, "socket failed : %s\n", strerror(errno));
        printf("sockfd value : %d\n", sockfd);
        return -1;
    }
    else fprintf(stderr, "socket created\n");
    
    
    //bind to socket
    if (hostType == SERVER)
    {
        if (bind(sockfd, netinfo->ai_addr, netinfo->ai_addrlen) != 0)
        {
            fprintf(stderr, "bind failed %s\n", strerror(errno));
            printf("errno value : %d\n", errno);
            return -1;
        }
        else fprintf(stderr, "socket bound to port %s\n", port);
    }
    else //go ahead and connect to server if you're the client!
    {
        if(connect(sockfd, netinfo->ai_addr, netinfo->ai_addrlen) != 0)
        {
            fprintf(stderr, "connect failed %s\n", strerror(errno));
            return -1;
        }
        else fprintf(stderr, "connected to host %s on port %s\n", host, port);
    }
    
    
    freeaddrinfo(netinfo);
    
    return sockfd;
}
