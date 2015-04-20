#include "board.h"
#ifndef HELPERS
#define HELPERS

class bigBoard: board
{

private:
    
    short emptygrids;
    bool freePlay;

public:
    board biggrid[9];    
    bigBoard();
    bool open(int last); // checks if it's playable or returns freeplay
    int whereToPlay(int last); // limits the scope of playing to 1 grid 
    void print();
    void setValue(int bigPlace , int smallPlace , int player, int & lasts);
    int checkBig();
};

#endif
