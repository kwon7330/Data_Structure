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

void Selection_Sort(int* _iArr, int _iSize)
{
	int iMinIndex = 0;

	for (int i = 0; i < _iSize - 1; i++)
	{
		iMinIndex = i;

		// 가장 작은 값이 있는 인덱스를 찾는 부분
		for (int j = i + 1; j < _iSize; j++)
		{
			if (_iArr[iMinIndex] > _iArr[j])
				iMinIndex = j;
		}
		// 가장 작은인덱스를 찾아서 앞에서 부터 바꿔 나간다.
		swap(_iArr[i], _iArr[iMinIndex]);
	}
}

void Bubble_Sort(int* _iArr, int _iSize)
{
	for (int i = 0; i < _iSize - 1; i++)
	{
		// 조기 종료를 위한 bool 변수를 두고
		bool isSorted = true;

		for (int j = 0; j < _iSize - i - 1; j++)
		{
			if (_iArr[j] > _iArr[j + 1])
			{
				swap(_iArr[j], _iArr[j + 1]);
				isSorted = false;
			}
		}
		// 만약 이후 정렬이 되어 있다면 탈출.
		if (isSorted)
			break;
	}
}

void Insertion_Sort(int* _iArr, int _iSize)
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
	for (int i = 1; i < _iSize; i++)
	{
		int iKey = _iArr[i];
		int j = i;
		for (; j > 0; j--)
		{
			if (_iArr[j - 1] <= iKey)
				break;
			_iArr[j] = _iArr[j - 1];

		}
		_iArr[j] = iKey;
	}
}



