//board.cpp
//Board class implementation
#include <iostream>
#include "board.h"
using namespace std;

board::board()
{
	*victor = '\0';
	//cout << "Board constructor call\n Initialising array with values: ";

	for (int i = 0; i<10; i++)  
		{
			int row = i/3;
			int collumn = i%3;

			char cVal = '0' + i;
			
			boardArray[row][collumn] = cVal;
		}
	//cout << "\nConstructor complete\n";
}


//=================================CHECKVICTORY=================================
bool board::checkVictory()
{
	char testR[3];//TestRow
	char testC[3];//TestCollumn
	char testD1[3];
	char testD2[3];
	//loop rows
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			testR[j] = boardArray[i][j];
			testC[j] = boardArray[j][i];

		

		}

		testD1[i] = boardArray[i][i];
		testD2[i] = boardArray[i][2-i];

		if(board::testArray(testR))
		{
			cout<<"\tRow Complete"<<endl;
			return true; 
		}

		if(board::testArray(testC))
		{	
			cout<<"\tColumn Complete"<<endl;
			return true;
		}

		if(board::testArray(testD1))
		{
			cout << "\tDiagonal Complete" << endl;
			return true;
		}

		if(board::testArray(testD2))
		{
			cout << "\tDiagonal Complete" << endl;
			return true;
		}
	
	}

	
	return false;
}

bool board::testArray(char array[3])
{
	if(array[0]==array[1] && array[1]==array[2])
	{	
		return true;
		*victor = array[0];
	}
	return false;
}

bool board::makeMove(char piece)//Needs to change to take int, move logic to game methods
{
	int r,c;
	int move;
	if (!(cin >> move) || move > 9) //Check that its a valid integer
	{
		cout << "\nEnter a valid square to move to: ";
	
		cin.clear();
		cin.ignore();
		return false;

	}
	
	
	r = move/3;
	c = move%3;
	if((boardArray[r][c] == 'X')||(boardArray[r][c] == 'O'))
	{
		cout << "\nThat space is already taken, enter another: ";
		return false;
	}
	
		//Int/3 always rounds down, 
	boardArray[r][c] = piece;
	printBoard();
	return true;
}

//==============Print Board Function====================
void board::printBoard()
{
	cout << "\n\n";
	for (int i = 0; i < 5; i++)
	{
		cout << "\t\t";
		for (int j = 0; j < 5; j++)
		{
			//EVEN rows & colums print i/2,j/2
			if ( (i % 2 == 0) && (j % 2 == 0))
				cout << boardArray[i/2][j/2];

			//EVEN row & ODD colum print |
			else if ((i % 2 == 0) && !(j % 2 == 0))
				cout << " | ";

			//ODD row & EVEN colum print _
			else if (!(i % 2 == 0) && (j % 2 == 0))
				cout << "__";

			//ODD row & ODD colum print |_
			else
				cout << "|_";
		}

		cout <<" \n";
	}
}
