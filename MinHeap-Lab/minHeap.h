/*
* Daniel Espinoza
* MinHeap Lab
*/
#include <vector>
#include <iostream>
using namespace std;


template <class T> 
class minHeap
{
private:
	vector<T> items;

	void swap(T &a, T &b)
	{
		T temp = a;
		a = b;
		b = temp;
	}


/* --------------------------------Index Returning Functions-------------------------------- */
	int getParent(int child)
	{
		return (child-1) / 2;
	}

	int getLChild(int parent)
	{
		return (2 * parent) + 1;
	}

	int getRChild(int parent)
	{
		return (2 * parent) + 2;
	}


/* ------------------------------Functions that Maintain Heap------------------------------ */
	void bubbleUp(int index)
	{
		int parent = getParent(index);

		if (items[index] < items[parent])
		{
			swap(items[index], items[parent]);
			bubbleUp(parent);
		}
	}

	void bubbleDown(int index)
	{
		int lChild = getLChild(index);
		int rChild = getRChild(index);
		int size = items.size();
		int min;

		// Check if parent is father/mother of two children
		if (lChild < size && rChild < size)
		{
			min = items[lChild] < items[rChild] ? lChild : rChild;

			if (items[min] < items[index])
			{
				swap(items[index], items[min]);
				bubbleDown(min);
			}
		}
		// If not it should only have either left child
		else if (lChild < size)
		{
			if (items[lChild] < items[index])
			{
				swap(items[index], items[lChild]);
				bubbleDown(lChild);
			}
		}
		// Or none
		else
		{
			// Maybe the kids went off to college or something
		}
	}

public:
	minHeap()
	{	}

	void insert(T x)
	{
		items.push_back(x);
		bubbleUp(items.size() - 1);
	}

	void display()
	{
		for (T n : items)
			cout << n << " ";
		cout << endl;
	}

	bool empty()
	{
		return items.empty();
	}

	T extractMin()
	{
		T min = items[0];

		items[0] = items.back();
		items.pop_back();

		bubbleDown(0);

		return min;
	}
};