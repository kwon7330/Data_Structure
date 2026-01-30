#include <iostream>
#include "MyDeque.h"

using namespace std;

void Print_Arr(int* _iArr, int _iSize)
{
	for (int i = 0; i < _iSize; i++)
	{
		cout << _iArr[i] << " ";
	}
	cout << endl;
}



int main()
{
	MyDeque<int>Deq(5);

	for (int i = 0; i < 5; i++)
		Deq.Push_Front_Deq(0);


	cout << Deq.Get_Front() << endl;

	return 0;
}