A 9*9 XoXo board game and the winner is declared when the player have a winning pattern in the big grid (he has to win in the small grids and form winning pattern in the big grid ) - using C++ & minmax algorithm

TicTacCeption is a game based on the original TicTacToe player vs computer. basically this game is different, harder and much more interesting.
in this game there is a 3*3 board and inside every block there is 3*3 small grids (check the pictures below).

the game rules : 
- players take turns to play :
- the big blocks is changed based on the last play position
- if the position is now a current locked big board the player gets a free play
the player have to win the small blocks in the normal tic tac toe rules (forming a winning pattern )
- the winner is specified if one of the two players got a winning pattern on the big blocks


how to play :
the first player chooses a big block and then chooses a small block ( inside the big block he previously chose )  now the other player turn and he can only play inside the big block that is corresponding to the small block that the other player had played in 
and so on 
if the block that the player should play in is locked ( someone won it or it's draw ) the player gets a free play . a free play is a free move where the user can play in any big & small block that he chooses 


sorry for the bad design but it will be improved 

1- : intial playgame : https://www.dropbox.com/s/zv09spp334hal9r/1.jpg?dl=0 

2- after playing some rounds (
player 1 played in 1-9 
player 2 played in 9-3
player 1 played in 3-7
player 2 played in 7-5
player 1 played in 5-5
player 2 plays in 5-(1-9 but 5)

https://www.dropbox.com/s/rpi93hjmzdmnq7j/2.jpg?dl=0
