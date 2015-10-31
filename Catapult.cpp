#include"Catapult.h"

void Catapult::fire(bool pl)// write code using bl!!
    {double theta=atan(abs(f));
     double init_vel=sqrt(pow(x1-cx,2)+pow(y1-cy,2))/17;
     double vy=(-1)*init_vel*abs(sin(theta));
     if(!pl)
        {
        C1=Circle(cx-20,cy,8);
        C1.setFill(1);
        Text t(500,300,"Fire in the hole!!");

        double vx=init_vel*cos(theta);
        swing(pl);
            while(C1.getY()<=cy and C1.getX()<960)
                {
                        wait(0.01);
                    C1.move(vx,vy);
                    vy+=1;
                }

        }
    else{
        C1=Circle(cx+20,cy,8);
        C1.setFill(1);

        Text t(500,300,"Fire in the hole!!");

        double vx=(-1)*init_vel*cos(theta);
            swing(pl);
            while(C1.getY()<=cy and C1.getX()>40)
                {
                    wait(0.01);
                    C1.move(vx,vy);
                    vy+=1;
                }

    }
    C1.hide();
    wait(1);
 }//end of fire()

 void Catapult::swing(bool pl){
    double theta=atan(abs(f));
    double c=0;
    if(!pl){
        while(c<theta){
            (*l1).rotate(0.1);
            c+=0.1;
            double l=20*tan(0.1);
            (*l1).move(l*sin(c),-l*cos(c));
            C1.moveTo((*l1).getX()-20*cos(c),(*l1).getY()-20*sin(c));
            }
        }
    else{
        while(c<theta){
            (*l1).rotate(-0.1);
            c+=0.1;
            double l=20*tan(0.1);
            (*l1).move(-l*sin(c),-l*cos(c));
            C1.moveTo((*l1).getX()+20*cos(c),(*l1).getY()-20*sin(c));
        }
    }
 }

void Catapult::moveC(bool pl)
{Text t(500,300,"Move the catapult with left and right arrow keys, and hit enter when ready");

    while(true)
        {
        char a=getch();
        if(a==KEY_RIGHT)
            {
             if(!pl){
                if(cx<475)
                {cx=cx+10;
                (*b).move(10,0);
                (*l1).move(10,0);
                }
                else continue;
                }
                else{
                if(cx<975)
                {cx=cx+10;
                (*b).move(10,0);
                (*l1).move(10,0);
                }
                else continue;
                }
            }
        else if(a==KEY_LEFT)
            {
             if(!pl){
                if(cx>25)
                {cx=cx-10;
                (*b).move(-10,0);
                (*l1).move(-10,0);
                }
                else continue;
                }
             else{
                if(cx>525)
                {cx=cx-10;
                (*b).move(-10,0);
                (*l1).move(-10,0);
                }
                else continue;
                }
            }
        else if(a=='\r')
            {
                break;
            }
        }

    t.hide();
    return;
}
void Catapult::create(bool pl)
    {if(!pl)//test values--change later
        {cx=120;
            cy=700;
        }
        else
        {cx=880;
            cy=700;
        }
        b = new Rectangle;
        *b=Rectangle(cx,cy,50,15);
       (*b).setColor(COLOR(0,255,0));
       (*b).setFill(1);
       l1 = new Rectangle;
       *l1=Rectangle(cx,cy,40,5);
       (*l1).setFill(1);
    }

    void Catapult::canRotate()
       {
        f=(cy-y1)/(x1-cx+25);
       }
    void Catapult::aim(bool pl)
        {
        Text t(500,300,"aiming");
        int cl=getClick();
             x1=cl/65536;
             y1=cl%65536;
            canRotate();
            wait(2);
            t.hide();
            fire(pl);
        }

double Catapult::getY1(){
    return C1.getY();
}

double Catapult::getX1(){
    return C1.getX();
}

/*int main()
 {
    initCanvas("testing",1000,800);
    Catapult b1;
    b1.create(0);
    b1.moveC(0);
    wait(2);
    b1.aim(0);
}*/

