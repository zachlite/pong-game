#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
using namespace std;


typedef struct
{
	int x;
	int y;

}Point;


typedef struct 
{
	int r;
	int g;
	int b;
	int a;

}Color;

typedef struct 
{
	int x;
	int y;

}Velocity;


class Shape
{
	public:
		Shape();
		~Shape(){};

		void SetCenter(int x, int y);
		void SetY(int y);
		void SetColor(int r, int g, int b, int a);
		void SetVelocity(int x, int y);
		void SetWidth(int w);
		void SetHeight(int h);

		Point GetCenter();
		int GetY();
		Color GetColor();
		Velocity GetVelocity();
		int GetWidth();
		int GetHeight();


	/* data */
	private:
		Point centerPoint;
		int width;
		int height;
		Color color;
		Velocity velocity;



};



#endif