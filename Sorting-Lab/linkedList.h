/*
* Daniel Espinoza
* Sorting Lab
* Implement mergesort for a doubly linked list
* and quicksort for arrays
*/
#include <iostream>
using namespace std;

template <class T>
class linkedList
{
private:
	class node
	{
	public:
		T data;
		node * next;
		node * prev;

		node(T x)
		{
			data = x;
			next = NULL;
			prev = NULL;
		}
	};

	node * head;
	node * tail;

	int numItems;

	//Split function
	void split(node *h1, node *t2, node * &t1, node * &h2)
	{
		node * p = h1;
		node *fast = h1;

		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				p = p->next;
				fast = fast->next;
			}
		}

		t1 = p->prev;
		h2 = p;
		t1->next = NULL;
		h2->prev = NULL;
	}

	//Merge function
	void merge(node * &h1, node * t1, node * h2, node * &t2)
	{
		node *curr = NULL, //Node for traversal across the list
			*start = NULL;

		//Find the smaller of two list for starting point
		if (h1->data <= h2->data)
		{
			curr = h1;
			h1 = h1->next;
		}
		else
		{
			curr = h2;
			h2 = h2->next;
		}
		start = curr;

		while (h1 != NULL && h2 != NULL)
		{
			if (h1->data <= h2->data)
			{
				curr->next = h1;
				h1->prev = curr;
				h1 = h1->next;
			}
			else
			{
				curr->next = h2;
				h2->prev = curr;
				h2 = h2->next;
			}
			curr = curr->next;
		}

		//Append the non-empty list
		if (h1 == NULL)
		{
			curr->next = h2;
			h2->prev = curr;
		}
		else
		{
			curr->next = h1;
			h1->prev = curr;
		}

		//Update tail if necessary
		if (t1->next == NULL)
		{
			t2 = t1;
		}

		h1 = start;
	}

	//merge sort the list from node h to t
	void mergeSort(node * &h, node * &t)
	{
		if (h != NULL && h != t) //2 or more items, otherwise base case of nothing
		{
			//step 1: split list into 2
			//point t1 and h2 to nodes such that: 
			//the left half of the list is from node h to t1, right half from node h2 to t
			node * t1 = NULL;
			node * h2 = NULL;
			split(h, t, t1, h2);

			//step 2: sort 2 halves
			mergeSort(h, t1);
			mergeSort(h2, t);

			//step 3: merge sorted halves back together
			//into a single sorted list
			merge(h, t1, h2, t);
		}
	}
		

public:
	linkedList()
	{
		head = NULL;
		tail = NULL;
		numItems = 0;
	}

	//frees all dynamically allocated memory (the nodes in the list)
	~linkedList()
	{
		while (!empty())
		{
			pop_front();
		}
	}

	int size()
	{
		return numItems;
	}

	//add item x to back of list
	void push_back(T x)
	{
		numItems++;
		if (head == NULL)
		{
			head = new node(x);
			tail = head;
		}
		else
		{
			tail->next = new node(x);
			tail->next->prev = tail;
			tail = tail->next;
		}
	}

	//remove and return the first item in the list
	T pop_front()
	{
		numItems--;
		T output = head->data;
		if (head == tail)
		{
			delete head;
			head = NULL;
			tail = NULL;
		}
		else
		{
			head = head->next;
			delete head->prev;
			head->prev = NULL;
		}
		return output;
	}

	void display()
	{
		node * c = head;
		while (c != NULL)
		{
			cout << c->data << ",";
			c = c->next;
		}
		cout << endl;
	}

	bool empty()
	{
		return (numItems == 0);
	}

	void mergeSort()
	{
		mergeSort(head, tail);
	}
};