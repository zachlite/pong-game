#include "shape.h"


Shape::Shape(){


}


void Shape::SetCenter(int x, int y){
	centerPoint.x = x;
	centerPoint.y = y;
}
void Shape::SetY(int y){
	centerPoint.y = y;
}

void Shape::SetColor(int red, int green, int blue, int alpha){
	color.r = red;
	color.g = red;
	color.b = red;
	color.a = red;

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

Point Shape::GetCenter(){
	return centerPoint;
}

int Shape::GetY(){
	return centerPoint.y;
}

Color Shape::GetColor(){
	return color;
}

Velocity Shape::GetVelocity(){
	return velocity;
}

int Shape::GetWidth(){
	return width;
}
int Shape::GetHeight(){
	return height;
}