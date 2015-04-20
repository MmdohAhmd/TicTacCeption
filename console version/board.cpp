#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <time.h>
#include <limits.h>
#include "board.h"

using namespace std;
 

board::board()
    {
        for(int i=0;i<9;i++)
        {
            grid[i]=0;
        }
        emptyPlaces=9;
        winner=0;
        isOver=0;
    }


bool board::over()   // checks if the board is done or not. returns isOver
    {
        return isOver;
    }


bool board::isFull() // check if exists any empty places in the board
    {
        for (int i=0;i<9;i++)
        {
            if (grid[i] == 0)
                return 0;
        }
        return 1;
    }


short board::check()  // checks for a winner
    {
    if (grid[0] == grid[1] && grid[1] == grid[2] && grid[0])
    {
        return grid[0];
    }
 
	else if (grid[3] == grid[4] && grid[4] == grid[5] && grid[3])
	{
		return grid[3];
	}
 
	else if (grid[6] == grid[7] && grid[7] == grid[8] && grid[6])
	{
		return grid[6];
	}
 
	else if (grid[0] == grid[3] && grid[3] == grid[6] && grid[0])
	{
		return grid[0];
	}
 
	else if (grid[1] == grid[4] && grid[7] == grid[4] && grid[1])
	{
		return grid[1];
	}
 
	else if (grid[2] == grid[5] && grid[5] == grid[8] && grid[2])
	{
		return grid[2];
	}
 
	else if (grid[0] == grid[4] && grid[8] == grid[4] && grid[0])
	{
		return grid[0];
	}
 
	else if (grid[2] == grid[4] && grid[4] == grid[6] && grid[2])
	{
		return grid[2];
	}
 	
	return 0 ;
    }
short board::reallycheck()  // checks for a winner
    {
    if (grid[0] == grid[1] && grid[1] == grid[2] && grid[0])
    {
        isOver=true;
        winner = grid[0];
        return grid[0];
    }
 
	else if (grid[3] == grid[4] && grid[4] == grid[5] && grid[3])
	{
		isOver=true;
		winner = grid[3];
		return grid[3];
	}
 
	else if (grid[6] == grid[7] && grid[7] == grid[8] && grid[6])
	{
		 isOver=true;
		 winner = grid[6];
		return grid[6];
	}
 
	else if (grid[0] == grid[3] && grid[3] == grid[6] && grid[0])
	{
		 isOver=true;
		 winner = grid[0];
		return grid[0];
	}
 
	else if (grid[1] == grid[4] && grid[7] == grid[4] && grid[1])
	{
		 isOver=true;
		 winner = grid[1];
		return grid[1];
	}
 
	else if (grid[2] == grid[5] && grid[5] == grid[8] && grid[2])
	{
		 isOver=true;
		 winner = grid[2];
		return grid[2];
	}
 
	else if (grid[0] == grid[4] && grid[8] == grid[4] && grid[0])
	{
		 isOver=true;
		 winner = grid[0];
		return grid[0];
	}
 
	else if (grid[2] == grid[4] && grid[4] == grid[6] && grid[2])
	{
		 isOver=true;
		 winner = grid[2];
		return grid[2];
	}
 	else if(isFull())
 	{
 		isOver=true;
 	}
	return 0 ;
    }


short board::whoWon() // returns the winner of the board
    {
        return winner;
    }

void board::print(int x , int y) // obviously
    {
    	for (int i = x ; i < y ; ++i)
    	{
    		 cout <<setw(2) << grid[i] << " | " ;
    	}

    	cout << "|" ;
    }


void board::fillPlace(short place, short player) // fills the grid with the players' moves
	{
		grid[place] = player;
	}
 
bool board::isempty(short place)
	{
		if (grid[place]== 0)
			return 1;

		else
			return 0;
	}


int board::max(int depth, int place)
{

	if (depth == 3)
		return 0;


	grid[place]	= 1;
	if (check()== 1)
	{
		grid[place]=0;
		return depth;
	}

	if (isFull())
		{
			grid[place]=0;
			return 0;
		}


	int best= INT_MIN, placce = -1,v;
	for (int i=0;i<9;i++)
	{
		if (grid[i]==0)
		{
			v = min (depth+1, i);
			if(v>best)
				{
					best=v;
					placce=i;
				}
		}
	}
	v=min(depth+1,placce);
	grid[place]=0;
	return v;
}

int board::min(int depth, int place)
{
	if (depth == 3)
		return 0;


	grid[place]	= -1;
	if (check()== -1){
		grid[place]=0;
		return -depth;
	}

	if (isFull())
		{
			grid[place]=0;
			return 0;
		}

	int best= INT_MAX, placce = -1,v;
	for (int i=0;i<9;i++)
	{
		if (grid[i]==0)
		{
			v=max (depth+1, i);
			if(v<best)
				{
					best=v;
					placce=i;
				}
		}
	}
	v=max(depth+1,placce);
	grid[place]=0;

	return v;
}


int  board::bestplace()
{
	int best= INT_MIN , place = -1,v;

	for (int i=0;i<9;i++)
	{
		if (grid[i]==0)
		{
			v = max (1 , i);
			if(v>best)
				{
					best=v;
					place=i;
				}
		}
	}

    for (int i = 0 ; i < 9 ; i++)
	{
		if (grid[i] == 0)
		{
			grid[i] = 1;

			if(check() == 1)
			{
				grid[i] = 0 ;
				return i ;
			}

			grid[i] = 0 ;
		}
	}	
	
	
	for (int i = 0 ; i < 9 ; i++)
	{
		if (grid[i] == 0)
		{
			grid[i] = -1;

			if(check() == -1)
			{
				grid[i] = 0 ;
				return i ;
			}

			grid[i] = 0 ;
		}
	}	

	return place;
}