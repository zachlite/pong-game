//
//  main.c
//  WebClient
//
//  Created by Zach Lite on 7/10/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#include "client.h"

void cli_listen_for_server(int sockfd);
void cli_send_to_server(int sockfd);

static const char *HOST = "127.0.0.1";



void cli_listen_for_server(int sockfd)
{

    char welcome_message[512];
    recv(sockfd, welcome_message, sizeof(welcome_message) - 1, 0);
    net_print_received_data(welcome_message);

   
}


void cli_send_to_server(int sockfd)
{

  
    if (net_is_connected(sockfd))
    {
       char intro[] = "client here!";
       send(sockfd, intro, sizeof(intro), 0);

    }

}




int cli(const char *PORT)
{
    int sockfd;

    printf("initializing client\n");

    if ((sockfd = net_open(HOST, PORT, CLIENT)) == -1)
    {
        fprintf(stderr, "error: client initialization failed.  is there a server running?\n");
        return -1;
    }


    //introduce yourself
    char intro[] = "client connected!";
    send(sockfd, intro, sizeof(intro), 0);



    //cli_listen_for_server(sockfd);




    return sockfd;
}


