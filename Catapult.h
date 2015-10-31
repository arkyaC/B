#ifndef Catapult_H
#define Catapult_H

#include<simplecpp>
#include<conio.h>
#include<cstdio>
#include"tracker.h"

class Catapult
{public:
    double cx,cy,x1,y1,f;
    Circle C1;
    Rectangle *b;
    Rectangle *l1;

		void fire(bool pl);
 		void swing(bool pl);
		void moveC(bool pl);
		void create(bool pl);
    void canRotate();
    void aim(bool pl);
		double getY1();
		double getX1();
};
#endif
