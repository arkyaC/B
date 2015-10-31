#include"Cannon.h"

void Cannon::fire(bool pl)
{   tracker obj;
    if(!pl)
        {
        C1=Circle(cx+25*cos((*b).getOrientation()),cy-25*abs(sin((*b).getOrientation())),5);
        C1.setFill(1);
        explode(C1.getX(),C1.getY());
        Text t(500,500,"Fire in the hole!!");
        double init_vel=sqrt(pow(x1-cx,2)+pow(y1-cy,2))/12;
        double theta=atan((double)(y1-cy)/(x1-cx));
        double vx=init_vel*cos(theta);
        double vy=(-1)*init_vel*abs(sin(theta));
        //C1.penDown();
            while(C1.getY()<=cy+25*abs(sin((*b).getOrientation())) and C1.getX()<960)
                {
                    wait(0.01);
                    C1.move(vx,vy);
                    vy+=1;
                    obj.track(C1.getX(),C1.getY());
                }
        explode(C1.getX(),C1.getY());
        C1.hide();
        }
    else{
        C1=Circle(cx-25*cos((*b).getOrientation()),cy-25*abs(sin((*b).getOrientation())),5);
        C1.setFill(1);
        explode(C1.getX(),C1.getY());
        Text t(500,500,"Fire in the hole!!");
        double init_vel=sqrt(pow(x1-cx,2)+pow(y1-cy,2))/12;
        double theta=atan((double)(y1-cy)/(x1-cx));
        double vx=-init_vel*cos(theta);
        double vy=(-1)*init_vel*abs(sin(theta));
        while(C1.getY()<=cy+25*abs(sin((*b).getOrientation())) and C1.getX()>40)
                {
                    wait(0.01);
                    C1.move(vx,vy);
                    vy+=1;
                }
        explode(C1.getX(),C1.getY());
    C1.hide();
    }


        wait(2);
    }
    void Cannon::explode(double x2,double y2)
    {   Circle c1(x2,y2,10);
        c1.setColor(COLOR("red"));
        c1.setFill(1);
        int r=10;
        while(r<15)
        {
            c1.reset(x2,y2,r);
            c1.setColor(COLOR("red"));
        c1.setFill(1);
        //wait(0.01);
        r+=1;
        }
        c1.hide();
    }

void Cannon::moveC(bool pl)
{Text t(500,400,"Move the cannon with left and right arrow keys, and hit enter when ready");


    while(true)
    {
        char a=getch();
        if(a==KEY_RIGHT)//'M'
            {
             if(!pl){
                if(cx<475)
                {cx=cx+10;
                (*b).move(10,0);}
                else continue;
                }
                else{
                if(cx<975)
                {cx=cx+10;
                (*b).move(10,0);}
                else continue;
                }
            }
        else if(a==KEY_LEFT)//'K'
            {
             if(!pl){
                if(cx>25)
                {cx=cx-10;
                (*b).move(-10,0);}
                else continue;
                }
             else{
                if(cx>525)
                {cx=cx-10;
                (*b).move(-10,0);}
                else continue;
                }
            }
        else if(a=='\r')
            {
                break;
            }
    }
    t.hide();
}
void Cannon::create(bool pl)
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
       (*b).setColor(COLOR("black"));
       (*b).setFill(1);
    }

void Cannon::canRotate(bool pl)
                {double c=0;
                if(!pl){
                        f=(-y1+cy)/(x1-cx+25);
                            double theta=atan(f);
                            while(c<theta){
                                (*b).rotate(-0.1);
                                c+=0.1;
                                double l=25*tan(0.1);
                                (*b).move(-l*sin(c),-l*cos(c));
                            }
                           }
                    else{
                        f=(-y1+cy)/(cx+25-x1);
                            double theta=atan(f);
                            while(c<theta){
                                (*b).rotate(0.1);
                                c+=0.1;
                                double l=25*tan(0.1);
                                (*b).move(l*sin(c),-l*cos(c));
                                }
                        }
                    cx=(*b).getX();
                   cy=(*b).getY();
                }
    void Cannon::aim(bool pl)
    {

    Text t(500,500,"aiming");
    int cl=getClick();
     x1=cl/65536;
     y1=cl%65536;
     t.hide();
    canRotate(pl);
    wait(2);
    fire(pl);
}

double Cannon::getY1(){
    return C1.getY();
}

double Cannon::getX1(){
    return C1.getX();
}


};
/*int main()
 {
    initCanvas("testing",1000,1000);
    Cannon b1;
    b1.create(800,550);//test values reset to 200,850 later for 1000x1000
    b1.moveC(1);
    wait(2);
    b1.aim(1);
}
*/
