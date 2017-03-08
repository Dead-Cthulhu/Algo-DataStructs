#include <iostream>
#include <fstream>
#include <vector>
#include "chainingTable.h"

int cleanWord(string&);
void insertNew(vector<string>&, string);
void ruinPoetry(chainingTable);

int main()
{
	chainingTable hashtable(202409);
	string word;
	ifstream input("dictionary.txt");

	if (!input)
	{
		cout << "Could not open dictionary" << endl;
		return 1;
	}

	while (input)
	{
		input >> word;
		hashtable.insert(word);
	}
	
	cout << "Average search cost: " << hashtable.averageSearchCost() << endl;

	cout << "Enter 1 to quit" << endl;
	while (word[0] != '1')
	{
		cout << "Word to test: ";
		cin >> word;

		if (hashtable.contains(word))
			cout << "Exist." << endl;
		else
			cout << "Does not exist." << endl;
	}

	ruinPoetry(hashtable);

	return 0;
}

//Read in The Raven by Edgar Allen Poe and 
//display words that are not in dictionary
void ruinPoetry(chainingTable t)
{
	string word;
	vector<string> fake;
	int index = 0;
	ifstream input("raven.txt");

	if (!input)
	{
		cout << "Quoth the Raven \"Missing File\"" << endl;
		return;
	}

	while (input)
	{
		input >> word;

		index = cleanWord(word);

		if (index)
		{
			if (!t.contains(word.substr(0, index)))
				insertNew(fake, word.substr(0, index));
			if (!t.contains(word.substr(index, word.length())))
				insertNew(fake, word.substr(index, word.length()));
		}
		else
		{
			if (!t.contains(word))
				insertNew(fake, word);
		}

		index = 0;
		word.clear();
	}

	cout << endl << "Edgar Allen Poe's fake words:" << endl;
	for (string w : fake)
		cout << w << endl;
}

//Strip the words of non-alpha characters
int cleanWord(string & w)
{
	int index = 0;

	for (int i = 0; i < w.length(); ++i)
	{
		if (isalpha(w[i]))
			w[i] = tolower(w[i]);
		else
		{
			if (w[i] == '-' && i != w.length() - 1)
				index = i;

			w.erase(w.begin() + i);
			i--;
		}
	}

	return index;
}

//Insert unique word to vector
void insertNew(vector<string> & f, string w)
{
	for (int i = 0; i < f.size(); ++i)
	{
		if (f.at(i) == w)
			return;
	}

	f.push_back(w);
}