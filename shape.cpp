#include "shape.h"


Shape::Shape(){


}


void Shape::SetCenter(int x, int y){
	centerPoint.x = x;
	centerPoint.y = y;
}

void Shape::SetColor(char r, char g, char b, char a){
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
}

void Shape::SetWidth(int w){
	width = w;
}

void Shape::SetHeight(int h){
	height = h;

}

void Shape::SetVelocity(float mag, float dir){
	velocity.magnitude = mag;
	velocity.direction = dir;
}