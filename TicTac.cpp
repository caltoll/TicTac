//ticTac.cpp
//game of tic tac toe from command line 
//Goal: Separate game implementation and board implementation. No board method should
//print to the command line.

//TODO
//Put turn logic in its own class
//Move player input from board class to game implementation, 
//	make makeMove(char) take an integer input makeMove(int, char)


#include <iostream>
#include "board.h"
using namespace std;



void turn()
{

}

//=================================MAIN=================================
int main()
{
	cout 	<<"\n\n\t==================================== \n"
			<<"\t Noughts and Crosses (1986 version) \n" 
			<<" \t====================================\n"
			<<"\n\n\t *For two players \n\n\t *Enter the number shown on the square you want"
			<<"\n\n\t *Continue taking turns until one or the other completes\n\t  a row, a column or a diagonal"
			<<"\n\n\n\t\t--Press enter to start a game--"
			<< endl;

			cin.ignore();
	while(true)
	{	
		board gameBoard = board();
		//cout << "Back to main" << endl; //Debug text
		
		char cont = '\0'; //Char will be set to y or n
		char victory = '\0'; //Char will be set to X or O
	
		int move;
		int turn = 0;

		gameBoard.printBoard();
		
		
		
		while(true)
		{

			//Nought's Turn
			turn++;
			cout << "\n\tNought: ";
			while(!gameBoard.makeMove( 'O'))
			{}

			if(gameBoard.checkVictory())
			{
				victory = 'O';
				break;
			}

			if(turn==9) //Awkward, but this loop has to stop after 9 turns
				break;

			//Cross' Turn
			turn++;
			cout << "\n\tCross: ";
			while(!gameBoard.makeMove('X'))
			{}

			if(gameBoard.checkVictory())
			{
				victory = 'X';
				break;
			}
		}
		
		victory = gameBoard.getVictor();
		cout << "\n\t *****Game Over*****"<<endl;
		if(victory=='O')
		{
			cout << "\n\t Nought is the winner!"<<endl;
		}

		else if(victory=='X')
		{
			cout << "\n\t Cross is the winner! "<<endl;
		}

		else 
		{
			cout << "Tie game!";
		}
		cout << "\n\tWould you like another game?" << endl;
		
		while(cont != 'y' && cont != 'n')
		{
			cout << "\t(y/n): ";
			cin >> cont;
		}

		if (cont == 'n')
			break;
		
	} 

	cout << "\tGoodbye" << endl;
	return 0;

	
}


