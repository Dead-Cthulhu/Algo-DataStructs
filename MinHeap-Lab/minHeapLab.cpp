#include <iostream>
#include <ctime>
#include "minHeap.h"
using namespace std;

template <class THING>
void heapSort(THING * items, int start, int end)
{
	minHeap<int> p;

	for (int i = start; i <= end; ++i)
		p.insert(items[i]);

	for (int i = start; i <= end; ++i)
		items[i] = p.extractMin();
}

int main()
{
	///////////////////////////////////////////////////
	//Step 1:  Implement a min-heap
	////////////////////////////////////////////////////


	minHeap<double> pq;

	pq.insert(57);
	pq.insert(32);
	pq.insert(105);
	pq.insert(17);
	pq.display();
	cout << pq.extractMin() << endl; //17
	cout << pq.extractMin() << endl; //32
	cout << endl;

	pq.insert(68);
	pq.insert(5);
	pq.insert(43);

	cout << pq.extractMin() << endl; //5
	cout << pq.extractMin() << endl; //43
	cout << pq.extractMin() << endl; //57
	cout << endl;

	pq.insert(120);
	pq.insert(500);
	pq.insert(3);
	pq.insert(73);
	pq.insert(29);

	//3 29 68 73 105 120 500
	while (!pq.empty())
	{
		cout << pq.extractMin() << endl;
	}
	cout << endl;

	///////////////////////////////////////////////////////////////////
	//Step 2: now, write a sorting routine that uses the heap sort
	///////////////////////////////////////////////////////////////////

	//fill a big array with random numbers
	int size = 1000000;
	int * numbers = new int[size];

	for (int i = 0; i < size; i++)
	{
		numbers[i] = rand();
	}

	//sort the array using a priority queue to help you
	clock_t startTime = clock();
	heapSort(numbers, 0, size - 1);
	clock_t endTime = clock();

	cout << "Heap Sort took: " << (endTime - startTime) / (double)CLOCKS_PER_SEC << " seconds." << endl;

	//now array should be in sorted order
	/*for (int i = 0; i < size; i++)
	{
		cout << numbers[i] << endl;
	}*/

	return 0;
}