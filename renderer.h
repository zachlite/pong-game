#include <SDL/SDL.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>

#include <iostream>
using namespace std;

class Renderer
{
	public:
		Renderer(int width, int height);
		~Renderer();
		void InitRenderFrame();
		void RenderFrame();
		void CleanRenderFrame();

	/* data */
	private:
		int screenWidth;
		int screenHeight;	
};