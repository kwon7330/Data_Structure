#include "MySort.h"

SWAPVALUE MySwapValue(int _A, int _B)
{
	SWAPVALUE tSwapValue{};
	tSwapValue.iA = _B;
	tSwapValue.iB = _A;

	return tSwapValue;
}

void MySwapPtr(int* _A, int* _B)
{
	int iTemp = *_A;
	*_A = *_B;
	*_B = iTemp;
}

void MySwapRef(int& _A, int& _B)
{
	int iTemp = _A;
	_A = _B;
	_B = iTemp;
}

bool CheckSorted(int _iA, int _iB)
{
	if (_iB >= _iA)
		return true;

	return false;
}

bool ChecKSorted(int* _iArr, int _iSize)
{
	for (int i = 0; i < _iSize - 1; i++)
	{
		if (_iArr[i] > _iArr[i + 1])
			return false;

		return true;
	}
}

void Print(int* _iArr, int iSize)
{
	for (int i = 0; i < iSize; i++)
	{
		cout << _iArr[i] << " ";
	}
	cout << endl;
}

int FindMinNumber(int* iArr, int iSize)
{
	int iMinNumber = iArr[0];

	for (int i = 1; i < iSize; i++)
	{
		if (iMinNumber > iArr[i])
			iMinNumber = iArr[i];
	}

	return iMinNumber;
}

inline int FindMinNumberIndex(int* iArr, int iSize)
{
	int iMinNumber = iArr[0];
	int iMinIndex = 0;

	for (int i = 1; i < iSize; i++)
	{
		if (iMinNumber > iArr[i])
		{
			iMinNumber = iArr[i];
			iMinIndex = i;
		}
	}

	return iMinIndex;
}

void SelectionSort(int* iArr, int iSize)
{
	int iMinIndex = 0;

	Print(iArr, iSize);

	for (int i = 0; i < iSize - 1; i++)
	{
		iMinIndex = i;

		for (int j = i + 1; j < iSize; j++)
		{
			if (iArr[iMinIndex] > iArr[j])
				iMinIndex = j;
		}

		swap(iArr[i], iArr[iMinIndex]);

		Print(iArr, iSize);
		cout << boolalpha;
		cout << ChecKSorted(iArr, iSize) << endl;
	}
}

void BubbleSort(int* iArr, int iSize)
{
	//BubbleSort
	// 중복 검사 제외
	bool isSorted = { false };

	for (int i = 0; i < iSize - 1; i++)
	{
		// 중복 검사 제외
		for (int j = 0; j < iSize - i - 1; j++)
		{
			if (iArr[j] > iArr[j + 1])
			{
				swap(iArr[j], iArr[j + 1]);
				isSorted = false;
			}
			else
				isSorted = true;
		}
		Print(iArr, iSize);
		if (isSorted)
			break;
	}
}

void InsertionSort(int* iArr, int iSize)
{
#pragma region 구현 연습

	//// 1. 오른쪽으로 하나씩 밀기
	//int i = 4;
	//int iTemp = iArr[i];
	//int j = i;
	//for (; j > 0; j--)
	//{
	//	if (iArr[j-1] <= iTemp)
	//		break;
	//	//2. iTemp 보다 작은 값들만 하나씩 밀기(오름차순)
	//		iArr[j] = iArr[j - 1];

	//	Print(iArr, iSize);
	//}
	//// 3. 삽입
	//iArr[j] = iTemp;
	//Print(iArr, iSize);

#pragma endregion

	// 오답 : int i = 0 -> 생각해보니 0은 이미 정렬되어있어서 의미없는 루프 한바퀴를 돈다.
	for (int i = 1; i < iSize; i++)
	{
		int iKey = iArr[i];
		int j = i;
		for (; j > 0; j--)
		{
			if (iArr[j - 1] <= iKey)
				break;
			iArr[j] = iArr[j - 1];
			Print(iArr, iSize);

		}
		iArr[j] = iKey;
		Print(iArr, iSize);

	}
}
