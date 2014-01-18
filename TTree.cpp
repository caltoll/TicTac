//TTree.cpp
//Special tree class to map the possible moves in tictactoe
//Aim to implement into an AI player

//

#include "board.h"
#include <iostream>
using namespace std;

struct node
{
    board nodeBoard;
    char turn; //Which side won
    int move;
    node * childNode[9];
};

class TTree
{
	public:
		TTree();
		~TTree();

		void destroyTree();
		void fillTree();//generate the possible game state

	private: 
    	void destroyTree(node * leaf);
    	void fillTree(node * leaf);
    	node * root;
};

TTree::TTree()
{
	cout << "TTree constructor" << endl;
	root = NULL;
}

TTree::~TTree()
{
	cout << "TTree destructor" << endl;
	destroyTree();
}

void TTree::destroyTree()
{
	destroyTree(root);
}

void TTree::destroyTree(node * leaf)
{
	cout << "DestroyTree() Call" << endl;
	if (leaf!=NULL)
	{

		for(int i = 0; i < 9; i++)
		{
			cout << "Destroying Childnode " << i << endl;
			destroyTree(leaf->childNode[i]);
		}
		delete leaf;
		leaf = 0;
	}
	cout << "Complete" << endl;
}


//Build tree needs 2 versions, one to start and initialise the node it is in, one to make the 
//move, then initialise the nodes below, and copy the board state into each of them

void TTree::fillTree()
{
	cout << "FillTree start\n";
	if (root != NULL)
		fillTree(root);
	else
	{
		root = new node;
		
		for (int i=0; i<9; i++)
		{
			cout << "Child Node " << i << endl;
			root -> childNode[i] = new node;
			root -> childNode[i] -> nodeBoard = root -> nodeBoard; //!!! this will crash with current setup of board
			root -> childNode[i] -> turn = 'O';
			//make each childnode's childnodes NULL
			for(int j =0; j<9 ; j++)
				root -> childNode[i] -> childNode[j] = NULL;
		} 

	}

}

void TTree::fillTree(node * leaf)
{	
	if (!(leaf->nodeBoard.makeMove(leaf->turn, leaf->move)))
	{
		destroyTree(leaf);
		return;
	}

	for (int i=0; i<9; i++)
		{
			leaf -> childNode[i] = new node;
			leaf -> childNode[i] -> nodeBoard = leaf -> nodeBoard; //!!! this will crash with current setup of board
			leaf -> childNode[i] -> move = i;
			if(leaf -> turn == 'O')
				leaf -> childNode[i] -> turn = 'X';
			else if (leaf -> turn == 'X')
				leaf -> childNode[i] -> turn = 'O';
		} 
}

int main()
{
	TTree test;
	test.fillTree();
}
