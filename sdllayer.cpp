#include "sdllayer.h"

SDLLayer::SDLLayer(const char * windowName, int width, int height){

	screenWidth = width;
	screenHeight = height;

	SDL_Init(SDL_INIT_EVERYTHING);
	Init_Memory();
	Setup_Window(windowName, width, height);

}

void SDLLayer::Init_Memory(){

   	SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8);
    
    SDL_GL_SetAttribute( SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1);
}

void SDLLayer::Setup_Window(const char * windowName, int width, int height){


	SDL_WM_SetCaption (windowName, NULL); //window caption
    SDL_SetVideoMode(width,height,32,SDL_OPENGL); //window size, rendering settings
    //draw something every frame
    glClearColor(1,1,1,1); // color used to clear screen every frame
        

    glViewport(0,0,width,height); //viewing area

    glShadeModel(GL_SMOOTH);//shader model
    glMatrixMode(GL_PROJECTION);//2D rendering
    glLoadIdentity();//"save" it     
    glDisable(GL_DEPTH_TEST);//disable depth checking for 2D rendering

}


