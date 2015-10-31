#ifndef Cannon_H
#define Cannon_H
#include<simplecpp>
class Block{
double cx,cy;
int health;
public:
Rectangle *b;
    Block();
    Block(double c1,double c2);
    void create(double c1,double c2,bool pl);
    void explode();
int damage(int d);
double GX();
double GY();
};
#endif
