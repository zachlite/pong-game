#include <SDL/SDL.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>

#include <vector>

#include "shape.h"

#include <iostream>
using namespace std;

class Renderer
{
	public:
		Renderer(int width, int height);
		~Renderer();

		void SetFrame();

		void InitRenderFrame();
		void RenderFrame(vector<Shape> &shapes);
		void CleanRenderFrame();

	/* data */
	private:
		int screenWidth;
		int screenHeight;	

		
		//frame.  a frame is vector of shapes
};