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

		int getNodesCreated() const{ return nodesCreated;}
		int getNodesDestroyed() const { return nodesDestroyed;}

	private: 
    	void destroyTree(node * leaf);
    	void fillTree(node * leaf);
    	node * root;

    	int nodesCreated;
    	int nodesDestroyed;
};

TTree::TTree()
{
	cout << "TTree constructor" << endl;
	root = NULL;
	nodesDestroyed=0;
	nodesCreated=0;
}

TTree::~TTree()
{
	cout << "TTree destructor" << endl;
	destroyTree();
	cout << "TTree destructor complete" << endl;
	cout << getNodesCreated() << " nodes created" << endl;
	cout << getNodesDestroyed() << " nodes destroyed" << endl;
}

void TTree::destroyTree()
{
	cout << "Destroy root\n"; 
	destroyTree(root);
}

void TTree::destroyTree(node * leaf)
{
	//cout << "DestroyTree() Call" << endl;
	
	if (leaf!=NULL)
	{
		nodesDestroyed++;

		for(int i = 0; i < 9; i++)
		{
			if ((leaf -> childNode[i]) != NULL)
			{
				//cout << "Destroying Childnode " << i << endl;
				destroyTree(leaf->childNode[i]);
			}
		}
	//	cout << "Delete leaf\n";
		delete leaf;
		leaf = NULL;
	}
	
}//At some point I am calling delete on a null pointer




//Build tree needs 2 versions, one to start and initialise the node it is in, one to make the 
//move, then initialise the nodes below, and copy the board state into each of them

void TTree::fillTree()
{
	//cout << "FillTree start\n";
	
	if (root != NULL)
		fillTree(root);
	else
	{
		//cout << "initialising root" << endl;
		root = new node;
		nodesCreated++;
		
		for (int i=0; i<9; i++)
		{
			nodesCreated++;
			//cout << "Child Node of root " << i << endl;
			root -> childNode[i] = new node;
			root -> childNode[i] -> nodeBoard = root -> nodeBoard;
			root -> childNode[i] -> turn = 'O';
			root -> childNode[i] -> move = i;
			//make each childnode's childnodes NULL
			for(int j =0; j<9 ; j++)
				root -> childNode[i] -> childNode[j] = NULL;

			fillTree(root->childNode[i]);
		} 

	}

}

void TTree::fillTree(node * leaf)
{	
	
	if ((leaf->nodeBoard.makeMove(leaf->turn, leaf->move))) 
	{
			

		for (int i=0; i<9; i++)
		{
			//cout <<"FillTree(node)";
			nodesCreated++;
			//cout << "Child Node " << i << endl;
			leaf -> childNode[i] = new node;
			leaf -> childNode[i] -> nodeBoard = leaf -> nodeBoard; 
			leaf -> childNode[i] -> move = i;
			//cout<<"Setting childnodes to NULL...";
			for(int j =0; j<9 ; j++)
				leaf -> childNode[i] -> childNode[j] = NULL;
			//cout << "Done\n";

			//cout << "Setting turns...";
			if(leaf -> turn == 'O')
				leaf -> childNode[i] -> turn = 'X';
			else if (leaf -> turn == 'X')
				leaf -> childNode[i] -> turn = 'O';
			//cout << "Done\n";

			fillTree(leaf -> childNode[i]);
		}
	} 
}

int main()
{
	TTree test;
	test.fillTree();
	cout << test.getNodesCreated() << " nodes created" << endl;
	cout << test.getNodesDestroyed() << " nodes destroyed" << endl;
	cin.ignore();
}
