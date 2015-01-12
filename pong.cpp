
#include "pong.h"

Pong::Pong(int mode){

	gameMode = mode;
	endGame = false;


}

void Pong::Start(){
	cout << "start game" <<endl;



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


        //Render to the screen
        glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();//start phase
        glOrtho(0,400,300,0,-1,1);//set the matrix
        /////////////////////////////////////////////

        glBegin(GL_QUADS);
        glColor3ub(0, 0xff, 0xff);
        glVertex2f(x, y);
        glVertex2f(x+width, y);
        glVertex2f(x+width, y+height);
        glVertex2f(x, y+height);
        glEnd();

        ///////////////////////////////////////////
        //end rendering
        glPopMatrix();//end
        SDL_GL_SwapBuffers();//re-draws

        SDL_Delay(100);//ms

   }

	
}

void Pong::TogglePause(){
	cout << "pause game" <<endl;
}



//event handling

//