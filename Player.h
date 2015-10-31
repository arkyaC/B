#ifndef Player_H
#define Player_H
#include"Cannon.h"//weapon 1
#include"Catapult.h"//weapon 2
#include"Block.h"
//#include"tracker.h"

class Player{
private:
    Cannon c1;
    Catapult c2;
    char choice;
    long int score;
    Block b[5];
    Block opp[5];
    
		public:
		int ctr;
		
    void setchoice();
    void creator(bool n);
    void blockcreate(bool n);
    void move(bool n);
    int track(Block a[]);
    void impact(int i);
    long int getScore();
    void firing(bool pl);
		Block* getBlocks();
		void setOpp(Block &inp);
		bool track(int w,Circle &C1);
};
#endif
