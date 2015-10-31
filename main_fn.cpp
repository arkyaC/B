//map-->can it be used?
#include<simplecpp>
#include<cstdlib>
#include<time.h>
#include"Player.h"
void showMessage(string msg);

int main()
{
    initCanvas("Battlepults",1000,1000);
    //showMessage("!!!!!!*****  WELCOME TO BATTLEPULTS  *****!!!!!!");wait(0.5);
	//showMessage("A Game by Vedant Basu and Arkya Chatterjee");wait(0.5);
    Rectangle r(500,850,1000,300);
    r.setColor(COLOR("green"));//ground
    r.setFill(1);
    r.imprint();
    r.reset(500,350,1000,700);
    r.setColor(COLOR(128,128,255));//sky
    r.setFill(1);
    r.imprint();
    showMessage("!!!!!!*****  WELCOME TO BATTLEPULTS  *****!!!!!!");wait(0.5);
		showMessage("A Game by Vedant Basu and Arkya Chatterjee");wait(0.5);


  	Player p1,p2;//player creation



bool turn=false;


wait(2);
showMessage("Coin Toss");
    double ti=0.1;
    time_t seconds;
    time(&seconds);
    simplecpp::srand((unsigned int)seconds);
    int n=rand()%15+10;
    Circle coin(500,350,50);
    coin.setFill(1);
    coin.setColor(COLOR("yellow"));
    showMessage("Player 1");
    coin.hide();
    wait(0.5);
    coin.show();
    coin.reset(500,350,50);
    coin.setFill(1);
    coin.setColor(COLOR("yellow"));
    showMessage("Player 2");
    showMessage("Starting toss!");
        while(n>0){

            if(!turn){
                coin.show();
                Text temp(500,350,"Player 1");
                wait(ti);
                coin.hide();
                }
            else{
                coin.show();
                Text temp(500,350,"Player 2");
                wait(ti);
                coin.hide();
                }
            turn=!(turn);
            ti*=1.1;
            n--;
        }
    //wait(2);
    coin.hide();
    turn=!(turn);
    if(!turn){showMessage("Player 1 gets first turn");}
    else{showMessage("Player 2 gets first turn");}

if(!turn){
    showMessage("Player 1 may place his blocks");
    showMessage("Player 2 may place his blocks");
      }
  else{
    showMessage("Player 2 may place his blocks");
    showMessage("Player 1 may place his blocks");
  }

 while(true)//main game control
  {
    if(!turn){
      showMessage("Player 1 may choose a weapon");
      p1.setchoice();
      p1.creator(0);
      p1.setOpp(p2.getBlocks());
      p1.firing(0);//perform tracking
      }
    else{
      showMessage("Player 2 may choose a weapon");
      p2.setchoice();
      p2.creator(1);
      p2.setOpp(p1.getBlocks());
      p2.firing(1);//perform tracking
      }





    turn=!(turn);
  }

}


void showMessage(string msg){
    Text t1(500,350,msg);
	wait(3);
}
