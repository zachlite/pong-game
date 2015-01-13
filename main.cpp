#include <iostream>
#include <stdlib.h>


#include "pong.h"
#include "sdllayer.h"


#include "network/client.h"
#include "network/server.h"

#include "string.h"


int main(int argc, char * argv[]){


    int sockfd;
    if (strcmp(argv[1], "0") == 0){
    
        serve("5000");
    }
    else if (strcmp(argv[1], "1") == 0){
    
        sockfd = cli("5000");
    }



    string windowName = "Pong";
    SDLLayer * sdl = new SDLLayer(windowName.c_str(), 400, 300);


    //create a new pong game object
    Pong *pongGame = new Pong(1);
    pongGame->SetScreen(300,400);

    pongGame->StartGame();

    //chose game mode

    //start game


    close(sockfd);
    free(sdl);
    free(pongGame);






 
    return 0;

}




