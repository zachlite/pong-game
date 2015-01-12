#include <iostream>

#include <SDL/SDL.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>

using namespace std;

class Pong
{
	public:
		Pong(int mode);//constructor
		~Pong();//deconstructor

		void StartGame(void);

		void SetScreenWidth(int width);
		void SetScreenHeight(int height);


	private:
		int gameMode;	
		bool endGame;
		bool isPaused;
		void TogglePause(void);

		int screenHeight;
		int screenWidth;

		//array to hold objects to render
};

