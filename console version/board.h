#ifndef BOARD
#define BOARD

class board
{
private:
     short grid[9];
     short emptyPlaces;
     
     

public:
    bool isOver;
    short winner;
    board();

    bool over(); // checks if the board is done or not. returns isOver
    bool isFull(); // check if exists any empty places in the board
    short check();  // checks for a winner (within MinMax)
    short reallycheck();  // checks for a winner (overall)
    short whoWon(); // returns the winner of the board
    short bestPlace(); // the computer's next move
    void print(int x , int y); // obviously
    void fillPlace(short place, short player); // fills the grid with the players' moves
    bool isempty(short place);
    int  bestplace();
    int  min(int depth, int place);
    int  max(int depth, int place);

    // maybe private : fillplace , check , is full
};



#endif
