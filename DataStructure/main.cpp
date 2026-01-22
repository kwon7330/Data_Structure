#include "MyRecursion.h"

using namespace std;

int main()
{
	int iArr[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
				// 0,1,1,2,3,5,8,13,21,34,55
	int iSize = sizeof(iArr) / sizeof(iArr[0]);
	
	cout << "Fibonacci : ";
	for (int i = 0; i < 10; i++)
	{
		cout << " " << Fibonacci(i) << " ";
	}
	
	cout << endl;

	cout << "Fibonacci : ";
	for (int i = 0; i < 10; i++)
	{
		cout << " " << RecursionFibonacci(i) << " ";
	}

	cout << endl;



	return 0;
}