#include <iostream>
#include <bits/stdc++.h>
#include "board.h"
#include "helpers.h"

using namespace std;

int main()
{
	bigBoard game;
	game.print();

	int x , y,last;
	int player = 1;
	int emptyPlaces = 81;
    int w;
    while(emptyPlaces > 0)
    {
   
    		cout << "enter the big square number" << endl;
    		cin >> x;
    		cout << "then enter the small square number" << endl;
        	cin >> y ;
        	 game.setValue(x,y,player,last);
        	 game.setValue(y,x,-1,last);
        	 game.print();

           while(1)
           {    
                w=game.checkBig();
                if(w)
                {
                    if(w==1)
                        cout<<"YOU WIN!!!"<<endl;
                    else 
                        cout<<"YOU LOSE!!"<<endl;
                    return 0;
                }

        		if (game.whereToPlay(last) == -1 )
        		{
        			cout<<"You can play Anywhere, Choose a place to play in"<<endl;
        			cin >> x;
                    while (!game.open(x))
                    {
                        cout<<"The place is unavailable\nTry again"<<endl;
                        cin>>x;
                    }
        			cout << "then enter the small  square number" << endl;
        		}
        	 	else
        	 	{
        	 		x= last;
        	 		cout<<"You are playing in the "<<x<<"-th game, make your move"<<endl;
        	 	}
    	
        	 cin >> y ;

        	 while (!game.biggrid[x].isempty(y))
        	 {
        	 	cout<<"The place is unavailable\nTry again"<<endl;
        	 	cin>>y;
        	 }
        	 	

                last = y;
        	 	game.setValue(x,y,player,last);

                w=game.checkBig();
                if(w)
                {
                    if(w==1)
                        cout<<"YOU WIN!!!"<<endl;
                    else 
                        cout<<"YOU LOSE!!"<<endl;
                    return 0;
                }

        		if(game.whereToPlay(y)== -1)
        		{
        			int n =(int) rand()%9;
        			while (!game.open(n))
                    {
                        n =(int) rand()%9;
                    }
        	 		y=n;
        		}

        	 	game.setValue(y,x,-1,last);
                game.checkBig();
        		emptyPlaces-=2;
				game.print();
        	         	 
            }
    
    }
    
    

	return 0;
}