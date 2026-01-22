#pragma once
#include <iostream>

using namespace std;

void Func2()
{
	int i = 0;
	cout << "is Func2 " << endl;
}

void Func1()
{
	int j = 1;
	Func2();
	cout << "is Func1" << endl;

}

void RecursionFunc(int _iCount)
{

	if (_iCount == 0)
		return;

	RecursionFunc(_iCount - 1); // 함수 호출 시점에 따라서 결과가 달라지게 된다.

	cout << _iCount << endl;

	//RecursionFunc(_iCount - 1);
}


inline int RecursionSum(int* _iArr, int iSize)
{
	int iIndex = iSize - 1;

	if (iIndex < 0)
		return 0;

	int iSum = RecursionSum(_iArr, iIndex) + _iArr[iIndex];

	return iSum;

	// 재귀를 호출을 하면 스택에 쌓이는 메모리가 보다 많다. 
	// 공간 복잡도 O(N), 시간 복잡도 O(N)
}



inline int Fibonacci(int iValue)
{
	if (iValue == 0)
		return 0;
	else if (iValue == 1)
		return 1;
	else
	{
		int iPrev1 = 0;
		int iPrev2 = 1;
		int iTemp = 0;

		for (int i = 2; i < iValue + 1; i++)
		{
			iTemp = iPrev1 + iPrev2;
			iPrev1 = iPrev2;
			iPrev2 = iTemp;
		}

		return iTemp;
	}
}

inline int RecursionFibonacci(int iValue)
{
	if (iValue == 0)
		return 0;
	else if (iValue == 1)
		return 1;

	return RecursionFibonacci(iValue - 1) + RecursionFibonacci(iValue - 2);

}


inline int RecursionBinarySearch(int* _iArr, int _iLeft, int _iRight, int iTarget)
{
	if (_iLeft <= _iRight)
	{
		int iMiddle = (_iLeft + _iRight) / 2;

		if (iTarget < _iArr[iMiddle])
		{
			return RecursionBinarySearch(_iArr, _iLeft, _iRight - 1, iTarget);
		}

		else if (iTarget > _iArr[iMiddle])
		{
			return RecursionBinarySearch(_iArr, _iLeft + 1, _iRight, iTarget);
		}

		else
			return iMiddle;
	}
	return -1;
}

// 실패
void RecursionPermutation(char* _szArr, int _iLeft, int _iRight)
{
	if (_iLeft == _iRight)
	{
		for (int i = 0; i < _iRight; i++)
		{
			cout << _szArr[i] << " ";
		}
		cout << endl;
	}
	else
	{
		for (int i = 0; i < _iRight; i++)
		{
			if (i == 0)
				swap(_szArr[i], _szArr[i]);
			else
				swap(_szArr[0], _szArr[i + 1]);

			RecursionPermutation(_szArr, _iLeft + 1, _iRight);
			_iLeft = 0;
		}

		cout << endl;
	}
}