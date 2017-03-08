#include <iostream>
#include "AVLTree.h"
#include "binarySearchTree.h"
using namespace std;

int main()
{
	//step 1: add a "height" variable to your node class.
	//Modify your insert method so that node height is
	//properly updated.  Create a getHeight() method
	//that returns the height of the root node to test
	//if height is being update properly.
	

	//step 2: create an AVLTree class, starting with your
	//binary search tree code.  Create 4 routine routines:
	//void leftRotation(node *&p), void rightRotation(node *&p), void leftRight(node *&p), void rightLeft(node *&p)

	//step 3:  Modify your insertion algorithm so that after inserting, you check for AVL-imbalance.
	//If there is an imbalance, figure out which case you are in, and call the appropriate rotation.


	//step 4:  Test your avl tree and compare it to a normal bst.
	const int MAX = 1000000;
	const int MAX2 = 1000;

	//test 1: random numbers
	binarySearchTree basicTree;
	AVLTree avlTree;

	for(int i=0; i<MAX; i++)
	{
		int x = rand();
		basicTree.insert(x);
		avlTree.insert(x);
	}

	//test with small number
	//avlTree.display();


	cout << "basic tree has height: " << basicTree.getHeight() <<endl;
	cout << "AvL tree has height: " << avlTree.getHeight() << endl;


	//test 2: increasing nubmers
	binarySearchTree basicTree2;
	AVLTree avlTree2;

	for(int i=0; i<MAX2; i++)
	{
		basicTree2.insert(i);	
		avlTree2.insert(i);
	}
	
	cout << "basic tree has height: " << basicTree2.getHeight() <<endl;
	cout << "AvL tree has height: " << avlTree2.getHeight() << endl;

	return 0;
}