#include "board.h"
#include "helpers.h"
#include <iomanip>
#include <vector>
#include <iostream>

using namespace std;
 
bigBoard::bigBoard()
{
	board x;
	for(int i=0;i<9;i++)
	{
		biggrid[i]=x;
	}

	emptygrids=9;
	freePlay=0;

}

void bigBoard::setValue(int bigPlace , int smallPlace , int player, int & last)
{
	if (player == -1)
		{
			last=biggrid[bigPlace].bestplace();
			biggrid[bigPlace].fillPlace(last , player);
		}

	else
		biggrid[bigPlace].fillPlace(smallPlace , player);
}

bool bigBoard::open(int last)
{
	if (biggrid[last].isOver)
	{
		return 0;
	}

	return 1;
}
int bigBoard::checkBig()
{
int lol;
	for (int i = 0 ; i < 9 ; ++i)
		lol = biggrid[i].reallycheck();

	
		 if (biggrid[0].winner == biggrid[1].winner && biggrid[1].winner == biggrid[2].winner && biggrid[2].winner)
		return biggrid[0].winner;
 
	else if (biggrid[3].winner == biggrid[4].winner && biggrid[4].winner == biggrid[5].winner && biggrid[5].winner)
		return biggrid[3].winner;
 
	else if (biggrid[6].winner == biggrid[7].winner && biggrid[7].winner == biggrid[8].winner && biggrid[8].winner)
		return biggrid[6].winner;
 
	else if (biggrid[0].winner == biggrid[3].winner && biggrid[3].winner == biggrid[6].winner &&  biggrid[6].winner)
		return biggrid[0].winner;
 
	else if (biggrid[1].winner == biggrid[4].winner && biggrid[7].winner == biggrid[4].winner && biggrid[4].winner )
		return biggrid[1].winner;
 
	else if (biggrid[2].winner == biggrid[5].winner && biggrid[5].winner == biggrid[8].winner && biggrid[8].winner  )
		return biggrid[2].winner;
 
	else if (biggrid[0].winner == biggrid[4].winner && biggrid[8].winner == biggrid[4].winner  && biggrid[4].winner)
		return biggrid[0].winner;
 
	else if (biggrid[2].winner == biggrid[4].winner && biggrid[4].winner == biggrid[6].winner && biggrid[6].winner )
		return biggrid[2].winner;
 
	return 0 ;
}

void bigBoard::print()
{
	for(int i = 0 ; i < 3 ; ++i)
	{
		biggrid[i].print(0 , 3);
	}
	cout << endl;
	for(int i = 0 ; i < 3 ; ++i)
	{
		biggrid[i].print(3 , 6);
	}
	cout << endl;
	for(int i = 0 ; i < 3 ; ++i)
	{
		biggrid[i].print(6 , 9);
	}


	cout << endl;
	for (int i = 0 ; i < 33 ; ++i)
		cout << "_" ;
 	cout << endl;


 
	for(int i = 3 ; i < 6 ; ++i)
	{
		biggrid[i].print(0 , 3);
	}
	cout << endl;
	for(int i = 3 ; i < 6 ; ++i)
	{
		biggrid[i].print(3 , 6);
	}
	cout << endl;
	for(int i = 3; i < 6 ; ++i)
	{
		biggrid[i].print(6 , 9);
	}

	cout << endl;
	for (int i = 0 ; i < 33 ; ++i)
		cout << "_" ;
	cout << endl;

	for(int i = 6 ; i < 9 ; ++i)
	{
		biggrid[i].print(0 , 3);
	}
	cout << endl;
	for(int i = 6 ; i < 9 ; ++i)
	{
		biggrid[i].print(3 , 6);
	}
	cout << endl;
	for(int i = 6 ; i < 9; ++i)
	{
		biggrid[i].print(6 , 9);
	}

	cout << endl;
	for (int i = 0 ; i < 33 ; ++i)
		cout << "_" ;
	cout << endl;

	cout << endl;
	cout << endl;
}



int bigBoard::whereToPlay(int last)
{

	if (open(last))
	{
		return last;
	}

	else
	{
		return -1;
	}

}

