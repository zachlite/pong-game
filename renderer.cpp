#include "renderer.h"

Renderer::Renderer(int width, int height){
	screenWidth = width;
	screenHeight = height;
}

void Renderer::SetRenderColor(int r, int g, int b, int a){
    red = r;
    green = g;
    blue = b;
    alpha = a;
}


void Renderer::InitRenderFrame(){
	glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();//start phase
    glOrtho(0,screenWidth,screenHeight,0,-1,1);//set the matrix
}

void Renderer::RenderFrame(Shape *shape){


    Point center;
    center = shape->GetCenter();

    int width = shape->GetWidth();
    int height = shape->GetHeight();


    glBegin(GL_QUADS);
    glColor3ub(0x00, 0x00, 0x00);
    glVertex2f(center.x-(width/2.0), center.y-(height/2.0));
    glVertex2f(center.x+(width/2.0), center.y-(height/2.0));
    glVertex2f(center.x+(width/2.0), center.y+(height/2.0));
    glVertex2f(center.x-(width/2.0), center.y+(height/2.0));
    glEnd();



    // Color color;
    // color = shape->GetColor(); 
    // cout << color.r << ":" << color.g << ":" << color.b << endl;
   

}

void Renderer::CleanRenderFrame(){

	  glPopMatrix();//end
      SDL_GL_SwapBuffers();//re-draws
}