/*
* Daniel Espinoza
* Binary Tree and AVL Binary Tree Lab
*
*/
#include <iostream>

class AVLTree
{
private:
	class node
	{
	public:
		double data;
		int height;
		node * left;
		node * right;

		node(double x)
		{
			data = x;
			height = 0;
			left = NULL;
			right = NULL;
		}
	};

	node *root;


	/* ----------------------------Functions About Height---------------------------- */
	int getHeight(node *ptr)
	{
		return ptr ? ptr->height : -1;
	}

	void updateHeight(node *&ptr)
	{
		int hl = getHeight(ptr->left),
			hr = getHeight(ptr->right);

		ptr->height = (hl >= hr ? hl : hr) + 1;
	}


	/* -----------------------------Rotation Functions------------------------------- */
	void rightRotation(node *&p)
	{
		node *a = p;
		node *b = p->left;
		node *br = b->right;

		p = b;
		a->left = br;
		b->right = a;		

		updateHeight(a);
		updateHeight(b);
	}

	void leftRotation(node *&p)
	{
		node *a = p;
		node *b = a->right;
		node *bl = b->left;

		p = b;
		a->right = bl;
		b->left = a;

		updateHeight(a);
		updateHeight(b);
	}

	void leftRightRotation(node *&p)
	{
		leftRotation(p->left);
		rightRotation(p);
	}

	void rightLeftRotation(node *&p)
	{

		rightRotation(p->right);
		leftRotation(p);
	}

	void balance(node *&ptr)
	{
		int bal_factor = getHeight(ptr->left) - getHeight(ptr->right);

		// Heavy on the left
		if (bal_factor > 1)
		{
			if (getHeight(ptr->left->left) - getHeight(ptr->left->right) > 0)
				rightRotation(ptr);
			else
				leftRightRotation(ptr);
		}
		// Heavy on the right
		else if (bal_factor < -1)
		{

			if (getHeight(ptr->right->left) - getHeight(ptr->right->right) > 0)
				rightLeftRotation(ptr);
			else
				leftRotation(ptr);
		}
	}


	/* --------------------------Copied from Binary Search Tree---------------------------- */
	//print all items in tree rooted at p
	void display(node * p)
	{
		if (p == NULL)
		{
			return;
		}
		else
		{
			display(p->left);
			std::cout << p->data << std::endl;
			display(p->right);
		}
	}

	void insert(node *&ptr, double x)
	{
		if (ptr == NULL)
		{
			ptr = new node(x);
		}
		else
		{
			if (x < ptr->data)
			{
				//put in left subtree
				insert(ptr->left, x);
				updateHeight(ptr);
				balance(ptr);
			}
			else
			{
				//put in right subtree
				insert(ptr->right, x);
				updateHeight(ptr);
				balance(ptr);
			}
		}
	}

public:
	AVLTree()
	{
		root = NULL;
	}

	void insert(double x)
	{
		insert(root, x);
	}

	void display()
	{
		display(root);
	}

	int getHeight()
	{
		return getHeight(root);
	}
};