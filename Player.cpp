#include"Player.h"

    void setchoice()//allows player to choose what weapon he wants to use
    {
        Text t(500,300,"Press z to use a cannon, or x to use a catapult");
        choice=getch();
        t.hide();
    }

    void creator(bool n)//creates a weapon depending on the player's choice
    {
        score=0;
        if (choice=='z'){
            c1.create(n);
            Text msg(500,300,"You chose Cannon!");
            wait(1);
            msg.hide();
            }
        else if(choice=='x'){
            c2.create(n);
            Text msg(500,300,"You chose Catapult!");
            wait(1);
            msg.hide();
            }
    }

    void blockcreate(bool n)//creates blocks at the clicked positions
    {
        for(int i=0;i<5;i++)
        {
           int pos=getClick();
            double c2=pos/65536;
            double c3=pos%65536;
            if(!n and (c2<240 or c2>460 or c3>700)){
                 i--;
                 continue;
                }
            else if(n and (c2>760 or c2<540 or c3>700)){
                 i--;
                 continue;
                }
            b[i].create(c2,c3,n);
        }
    }

    void move(bool n)//moves either the cannon or the catapult
    {
        if (choice=='z')
            c1.moveC(n);
        else if(choice=='x')
            c2.moveC(n);
    }

    int track(Block a[])//common tracking function,returns index of blown block
    {
         if (choice=='z')   {

         for(int i=0;i<5;i++)
         {
             if(abs(a[i].GY()-c1.getY1())<=5)//check on y position,within a small margin
             {
                 if(abs(a[i].GX()-c1.getX1())<=5)
                    return i;
                 else return -1;
             }
             else return -1;
         }
    }
else if (choice=='x')
{
    for(int i=0;i<5;i++)
         {
             if(abs(a[i].GY()-c2.getY1())<=5)//check on y position,within a small margin
             {
                 if(abs(a[i].GX()-c2.getX1())<=5)
                    return i;
                 else return -1;
             }
             else return -1;
         }
        }
    }

    void impact(int i)
    {
        if(i!=-1)//checks for impact
        {
            if (choice=='z')
            {
              int x=b[i].damage(5);//instantly destroys block
              score+=100;
              if (x==-1)
                ctr1-=1;

            }
            else if(choice=='x')
            {
                b[i].damage(3);//two hits
                score+=80;
            }
        }

    }
    long int getScore()
    {
        return score;
    }
    void firing(bool pl)//firing sequence,--> check if the pointer works
    {
        if(choice=='z')
            c1.aim(pl);
        else if(choice=='x')
            c2.aim(pl);
    }

Block* getBlocks(){
    return b;
}

void setOpp(Block &inp){
    for(int i=0;i<5;i++)
        opp[i]=inp[i];
}



    bool track(int w,Circle &C1)
    {
     if(w==1)//cannonball tracker
     {
         for(int i=0;i<5;i++)
         {
             if(abs(a[i].GY()-C1.getY())<=45)
             {
                 if(abs(a[i].GX()-C1.getX())<=45)
                    return true;
                 else return false;
             }
             else return false;
         }
     }
     else if (w==2)//catapult tracker
     {
         for(int i=0;i<5;i++)
         {
             if(abs(a[i].GY()-C1.getY())<=45)
             {
                 if(abs(a[i].GX()-C1.getX())<=45)
                    return true;
                 else return false;
             }
             else return false;
         }
     }
    }
