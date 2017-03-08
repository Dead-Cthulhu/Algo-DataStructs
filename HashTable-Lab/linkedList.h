#include <string>
using namespace std;

class linkedList
{
private:
	class Node 
	{
	public:
		string word;
		Node *next;

		Node(string w)
		{
			word = w;
			next = NULL;
		}
	};

	Node *head;
	Node *back;
	int length;

public:
	linkedList()
	{
		head = NULL;
		back = head;
		length = 0;
	}

	void add(string w)
	{
		if (head == NULL)
		{
			head = new Node(w);
			back = head;
		}
		else
		{
			back->next = new Node(w);
			back = back->next;
		}

		length++;
	}

	int size()
	{
		return length;
	}

	bool contains(string x)
	{
		bool exist = false;
		Node *ptr = head;

		while (ptr != NULL)
		{
			if (ptr->word == x)
			{
				exist = true;
				break;
			}

			ptr = ptr->next;
		}

		return exist;
	}
};