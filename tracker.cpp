#include"tracker.h"
bool tracker::track(int w,Circle &C1)
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

