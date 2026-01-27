#include <iostream>
#include "MyStack.h"

using namespace std;

int main()
{
	// 문자열 뒤집기

	char szArr[] = "Hello World!";
	int iSize = sizeof(szArr) - 1;

	MyStack<char> Stk(iSize);

	cout << "Input : " << szArr << endl;

	for (int i = 0; i < iSize; i++)
	{
		Stk.Push_Stack(szArr[i]);
	}


	for (int i = 0; i < iSize; i++)
	{
		cout << Stk.Top();
		Stk.Pop_Stack();
	}
	
	cout << endl;

	return 0;
}