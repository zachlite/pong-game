#include <iostream>

#include <SDL/SDL.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>

#include "shape.h"


using namespace std;

class Pong
{
	public:
		Pong(int mode);//constructor
		~Pong();//deconstructor

		void StartGame(void);

		void SetScreen(int width, int height);


	private:
		int gameMode;	
		bool endGame;
		bool isPaused;
		void TogglePause(void);

		int screenHeight;
		int screenWidth;

		//array to hold objects to render
};

