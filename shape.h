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
	char r;
	char g;
	char b;
	char a;

}Color;

typedef struct 
{
	float magnitude;
	float direction;

}Velocity;


class Shape
{
	public:
		Shape();
		~Shape();

		void SetCenter(int x, int y);
		void SetColor(char r, char g, char b, char a);
		void SetVelocity(float mag, float dir);
		void SetWidth(int w);
		void SetHeight(int h);


	/* data */
	private:
		Point centerPoint;
		int width;
		int height;
		Color color;
		Velocity velocity;


};



#endif