/*
* Daniel Espinoza
* Hash Table Lab
* Insert a dictionary to a chaining Hash Table
* Then find any fake words used by poet Edgar Allen Poe
* in The Raven and display them
*/
#include <string>
#include "linkedList.h"
using namespace std;

class chainingTable
{
private:
	//hash table conists of a table of lists
	linkedList * table;

	//size of table
	int capacity;

	//number of items in hash table
	int numItems;

	// Hasing function
	unsigned int hash(string str)
	{
		unsigned int hash = 5381;

		for (int i = 0; i < str.size(); ++i)
			hash = (hash * 33) + str[i];

		return hash % capacity;
	}

public:
	chainingTable(int size)
	{
		table = new linkedList[size];
		capacity = size;
	}

	chainingTable()
	{
		delete table;
	}

	//use this to measure how good your
	//hash function is.
	double averageSearchCost()
	{
		double sumSquares = 0;
		for (int i = 0; i<capacity; i++)
		{
			sumSquares += (table[i].size()*table[i].size());
		}
		return sumSquares / numItems;
	}

	void insert(string x)
	{
		int h = hash(x);

		table[h].add(x);
	
		numItems++;
	}

	bool contains(string x)
	{
		int h = hash(x);

		return table[h].contains(x);
	}
};