#include <iostream>

#include <SDL/SDL.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>

#include "shape.h"


using namespace std;


typedef struct{
	int X1;
	int X2;
	int Y1;
	int Y2;
}Rect;


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
		bool RectInRect(Rect rect1, Rect rect2);


		int screenHeight;
		int screenWidth;

		//array to hold objects to render
};

