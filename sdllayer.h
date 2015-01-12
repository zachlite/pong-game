#include <SDL/SDL.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>

#include <iostream>
#include <string>
using namespace std;


class SDLLayer
{
	public:
		SDLLayer(const char * windowName, int width, int height);
		~SDLLayer();

	private:	
		void Init_Memory();
		void Setup_Window(const char * windowName, int width, int height);
};