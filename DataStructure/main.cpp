#include <iostream>
#include "MySort.h"
#include "MySearch.h"

using namespace std;



int main()
{
	int iArr[] = { 0,1,2,3,4,5,6,7,8,9 };
	int iSize = sizeof(iArr) / sizeof(iArr[0]);

	BinarySearch(iArr,iSize,5);


	return 0;
}