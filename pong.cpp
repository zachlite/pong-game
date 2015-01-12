
#include "pong.h"
#include "paddle.h"
#include "renderer.h"

Pong::Pong(int mode){

	gameMode = mode;
	endGame = false;


}

void Pong::StartGame(){
	cout << "start game" <<endl;

	Renderer *renderer = new Renderer(screenWidth, screenHeight);

	Paddle *player_paddle = new Paddle();

	


    SDL_Event event; 
 
    int x = 20, y = 20;
    int width = 40, height = 50;

    while (!endGame)
    {


        while (SDL_PollEvent(&event))
        {
         
            if (event.type == SDL_QUIT)
            {
                endGame = true;
            }
            
            if ( (event.type == SDL_KEYUP) && (event.key.keysym.sym == SDLK_ESCAPE))//release a key
            {
                endGame = true;
            }

            if ( (event.type == SDL_KEYUP) && (event.key.keysym.sym == SDLK_p) )
            {
            	if (!isPaused) isPaused = true;
            	else isPaused = false;
            }
        }



        //logic



        //render
        renderer -> InitRenderFrame();
        renderer -> RenderFrame();
        renderer -> CleanRenderFrame();

        // SDL_Delay(100);//ms

   }

	
}

void Pong::TogglePause(){
	cout << "pause game" <<endl;
}


void Pong::SetScreenWidth(int width){
	screenWidth = width;
}
void Pong::SetScreenHeight(int height){
	screenHeight = height;
}


//event handling

//