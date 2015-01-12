#include "renderer.h"

Renderer::Renderer(int width, int height){
	screenWidth = width;
	screenHeight = height;
}


void Renderer::InitRenderFrame(){
	glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();//start phase
    glOrtho(0,screenWidth,screenHeight,0,-1,1);//set the matrix
}

void Renderer::RenderFrame(vector<Shape> &shapes){

	// for now
	int x = 20;
	int y = 20;
	int width = 20;
	int height = 80;

    glBegin(GL_QUADS);
    glColor3ub(0, 0xff, 0xff);
    glVertex2f(x, y);
    glVertex2f(x+width, y);
    glVertex2f(x+width, y+height);
    glVertex2f(x, y+height);
    glEnd();

    //eventually...
    //for each shape in array of shapes to render...

    for (int i = 0; i < shapes.size(); i++)
    {
    	cout << "iterate" << endl;
    }



}

void Renderer::CleanRenderFrame(){

	  glPopMatrix();//end
      SDL_GL_SwapBuffers();//re-draws
}