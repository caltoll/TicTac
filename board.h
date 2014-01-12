//board.h
//Header file for the board class

class board
{

public:
	board();
	~board(){};

	bool checkVictory(); //Check if the board is in a victory state & set getVictor											
	void printBoard(); // Print the board with characters separated by | and _
	bool makeMove(char place);
	char getVictor(){return *victor;}
	void resetBoard();

private: 
	bool testArray(char array[3]); //As part of checkVictory: Test if an array of 3 characters are all equal
	char * victor; //Char which shows which made the winning move, set via pointer through checkVictory
	char boardArray[3][3];
};