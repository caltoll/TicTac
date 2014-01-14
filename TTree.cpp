//TTree.cpp
//Special tree class to map the possible moves in tictactoe
//Aim to implement into an AI player

//

#include "board.h"

struct node
{
    board nodeBoard;
    bool victory; //Check if victory achieved, for AI later
    char victor; //Which side won
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
    	node * root;
};

TTree::TTree()
{
	root = NULL;
}

TTree::~TTree()
{
	destroyTree();
}

void TTree::destroyTree()
{
	destroyTree(root);
}

void TTree::destroyTree(node * leaf)
{
	if (leaf!=NULL)
	{
		for(int i = 0; i < 9; i++)
			destroyTree(leaf->childNode[i]);

		delete leaf;
	}
}

//Build tree needs 2 versions, one to start and initialise the node it is in, one to make the 
//move, then initialise the nodes below, and copy the board state into each of them