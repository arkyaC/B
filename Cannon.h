#ifndef Cannon_H
#define Cannon_H
#include<simplecpp>
#include<cmath>
#include<stdio.h>
#include<conio.h>
#include"tracker.h"

class Cannon
{public:
    double cx,cy,x1,y1,f;
    Circle C1;
    Rectangle *b;

		void fire(bool pl);
		void explode(double x2,double y2);
		void moveC(bool pl);
		void canRotate(bool pl);
		void aim(bool pl);
		double getY1();
		double getX1();
};
#endif
