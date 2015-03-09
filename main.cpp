#include <iostream>
#include <stdlib.h>
#include "string.h"


#include "pong.h"
#include "sdllayer.h"

#include "network/client.h"
// #include "network/server.h"



int main(int argc, char * argv[]){

    

    // if (strcmp(argv[1], "0") == 0){
    
    //     serve("5000");
    // }
    // else if (strcmp(argv[1], "1") == 0){
    
    //     sockfd = cli("5000");

    // }


    Client *client = new Client("127.0.0.1", "5000");
    client->Send("hello, world");





    // string windowName = "Pong";
    // SDLLayer * sdl = new SDLLayer(windowName.c_str(), 400, 300);


    // Pong *pongGame = new Pong(1);
    // pongGame->SetScreen(300,400);

    // pongGame->StartGame();

    


    // close(sockfd);
    // free(sdl);
    // free(pongGame);

    return 0;

}




