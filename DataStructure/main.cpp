#include <iostream>
#include "MyQueue.h"

using namespace std;

void Print_Arr(int* _iArr, int _iSize)
{
	for (int i = 0; i < _iSize; i++)
	{
		cout << _iArr[i] << " ";
	}
	cout << endl;
}

void Josephus(int _iSize, int _iK)
{
	MyQueue<int>Queue(_iSize);

	for (int i = 0; i < _iSize; i++)
	{
		Queue.Enqueue(i + 1);
	}

	while (Queue.Size_Queue() != 1)
	{
		for (int i = 0; i < _iK - 1; i++)
		{
			int iTemp = Queue.Get_Front();
			Queue.Dequeue();
			Queue.Enqueue(iTemp);
		}

		Queue.Dequeue();
	}

	cout << Queue.Get_Front() << endl;
}

int main()
{
	
	Josephus(5,2);

	return 0;
}