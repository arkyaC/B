#include<simplecpp>

class Block{
double cx,cy;
    int health;
public:
Rectangle *b=new Rectangle;


    Block(){
    }
    Block(double c1,double c2)
    {
        cx=0;
        cy=0;
        //c1=0;
        //c2=0;
        //r=0;
        health=5;
        //*b=new Rectangle;
    }


    void create(double c1,double c2,bool pl)
    {
        cx=c1;
        cy=c2;
        *b=Rectangle(cx,cy,80,80);
       if(!pl) (*b).setColor(COLOR("white"));
       else (*b).setColor(COLOR("black"));
       (*b).setFill(1);
    }

    void explode()
    { Circle c1(cx,cy,10);
    c1.setColor(COLOR("red"));
    c1.setFill(1);
    int r=10;
    while(r<75)
    {
        c1.reset(cx,cy,r);
        c1.setColor(COLOR("red"));
    c1.setFill(1);
    wait(0.1);
    r+=10;
    }
    c1.hide();
    delete b;
    }
int damage(int d)//damage taken by the block
{
    health-=d;
    if (health==0)
        {explode();
                return -1;//block destroyed
        }
    return 1;//block survived
}
double GX()
{
    return cx;
}

double GY()
{
    return cy;//cy+75?
}
};
