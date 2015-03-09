//
//  main.c
//  WebServer
//
//  Created by Zach Lite on 7/9/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#include "server.h"

int serve(const char *PORT);
int serv_listen_for_client(int sockfd);
void* serv_client_handler(void *arg);



void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}




void* serv_client_handler(void *arg)
{
    // char *welcomeMessage = "Joined Server successfully";
    // unsigned long msgLength; long byte_sent;
    // msgLength = strlen(welcomeMessage);

    char buffer[1024];

    new_client *nc = (new_client*)arg;
    int clientfd = nc->new_client_fd;
    char *clientaddr = nc->client_addr;

        
    recv(clientfd, &buffer, sizeof(buffer) - 1, 0);          
    net_print_received_data(buffer);
     
    
    free(nc);

    close(clientfd);
    printf("client disconnected\n");
    return NULL;
}




int serv_listen_for_client(int sockfd)
{
    printf("Waiting for connections\n");
    
    
    int listenStatus;
    
    listenStatus = listen(sockfd, 3);
    printf("getting here?\n");
    
    if (listenStatus == -1) {
        fprintf(stderr, "listen failed %s\n", strerror(errno));
        return -1;
    }
    
    
    char s[INET6_ADDRSTRLEN];

    
  

    struct sockaddr_storage their_addr;
    socklen_t addr_size;
    int newfd;
    addr_size = sizeof(their_addr);
    
    
    //accept a new connection and get its file descriptor
    newfd = accept(sockfd, (struct sockaddr *)&their_addr, &addr_size);
    printf("getting here????\n");

    
    inet_ntop(their_addr.ss_family, get_in_addr((struct sockaddr *)&their_addr), s, sizeof(s));
    printf("Server received a connection from %s\n", s);
    



    //thread creation
    pthread_t thread_id;
    void *thread_status;

    //struct to tell the new client handler about the new socket!
    new_client *newc = (new_client*)malloc(sizeof(*newc));
    newc->new_client_fd = newfd;
    strncpy(newc->client_addr, s, INET6_ADDRSTRLEN);


    if (pthread_create(&thread_id, NULL, &serv_client_handler, newc) != 0)
    {
        fprintf(stderr, "can't create thread %s\n", strerror(errno));
        free(newc);
    }


       
        

    
    return 0;
}




int serve(const char *PORT)
{
    
    int sockfd;

    printf("initializing server\n");

    if ((sockfd = net_open(NULL, PORT, SERVER)) == -1)
    {
        fprintf(stderr, "error: server initialization failed\n");
        return -1;
    }
    
    
    if (serv_listen_for_client(sockfd) == -1)
    {
        fprintf(stderr, "error: could not listen on network");
        close(sockfd);
        return -1;
    }
    
      
    return sockfd;    
}



