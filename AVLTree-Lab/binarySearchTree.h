#include <iostream>
using namespace std;

class binarySearchTree
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

	node * root;

	int getHeight(node *ptr)
	{
		return ptr ? ptr->height : -1;
	}

	void updateHeight(node *ptr)
	{
		int hl = getHeight(ptr->left),
			hr = getHeight(ptr->right);

		ptr->height = (hl >= hr ? hl : hr) + 1;
	}

	//insert x into tree rooted at p
	void insert(double x, node * &p)
	{
		if (p == NULL)
		{
			p = new node(x);
		}
		else
		{
			if (x < p->data)
			{
				//put in left subtree
				insert(x, p->left);
				updateHeight(p);
			}
			else
			{
				//put in right subtree
				insert(x, p->right);
				updateHeight(p);
			}
		}
	}

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
			cout << p->data << endl;
			display(p->right);
		}
	}

public:
	binarySearchTree()
	{
		root = NULL;
	}

	void insert(double x)
	{
		insert(x, root);
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