#include <iostream>
#include <stdlib.h>


#include "pong.h"
#include "sdllayer.h"



int main(int argc, char * argv[]){


    string windowName = "Pong";
    SDLLayer * sdl = new SDLLayer(windowName.c_str(), 400, 300);


    //create a new pong game object
    Pong *pongGame = new Pong(1);
    pongGame->SetScreen(300,400);

    pongGame->StartGame();

    //chose game mode

    //start game



    free(sdl);
    free(pongGame);






 
    return 0;

}




