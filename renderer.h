#include <SDL/SDL.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>


#include "shape.h"

#include <iostream>
using namespace std;

class Renderer
{
	public:
		Renderer(int width, int height);
		~Renderer();

		void SetFrame();

		void SetRenderColor(int r, int g, int b, int a);

		void InitRenderFrame();
		void RenderFrame(Shape *shape);
		void CleanRenderFrame();

	/* data */
	private:
		int screenWidth;
		int screenHeight;	
		int red;
		int green;
		int blue;
		int alpha;

		
		//frame.  a frame is vector of shapes
};