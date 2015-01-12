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

		void Start(void);


	private:
		int gameMode;	
		bool endGame;
		bool isPaused;
		void TogglePause(void);

};

