#include <iostream>
#include "MySort.h"

using namespace std;

int main()
{
	int iArr[] = { 1,2,4,5,3,6};
	//int iArr[] = { 1,2,3,5,4 };
	int iSize = sizeof(iArr) / sizeof(iArr[0]);

	Print(iArr, iSize);

	InsertionSort(iArr,iSize);
	



	return 0;
}