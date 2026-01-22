#include "MyRecursion.h"

using namespace std;

int main()
{
	int iArr[] = { 1,3,5,7,9 };
	int iSize = sizeof(iArr) / sizeof(iArr[0]);
	
	char szArr[] = "abc";
	iSize = sizeof(szArr) - 1;

	RecursionPermutation(szArr,0,iSize);

	return 0;
}