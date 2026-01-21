#pragma once
#include <iostream>

using namespace std;

typedef struct tagSwapValue
{
	int iA = 0;
	int iB = 0;
}SWAPVALUE;

SWAPVALUE MySwapValue(int _A, int _B);
void MySwapPtr(int* _A, int* _B);
void MySwapRef(int& _A, int& _B);

bool CheckSorted(int _iA, int _iB);
bool ChecKSorted(int* _iArr, int _iSize);

void Print(int* _iArr, int iSize);


// 선택 정렬 : 가장 작은 숫 자를 먼저 선택 하고 남아 있는 것들 중에 탐색

// 1. 가장 작은 수 찾기
int FindMinNumber(int* iArr, int iSize);

// 2. 가장 작은 수의 인덱스 찾기
int FindMinNumberIndex(int* iArr, int iSize);

//SelectionSort
void SelectionSort(int* iArr, int iSize);
//BubbleSort
void BubbleSort(int* iArr, int iSize);

void InsertionSort(int* iArr, int iSize);


#pragma region 정렬 예제 풀이

// 1.
/*for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int iA = j, iB = i;

			if (j > i)
			{
				iA = i;
				iB = j;
			}

			cout << iA << " " << iB << " ";

			if (iB >= iA)
				cout << "Ture" << endl;
			else
				cout << "False" << endl;

		}
	}*/

//2.
	//int iArr[2] = {};
	//
	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//	{
	//		iArr[0] = i;
	//		iArr[1] = j;
	//
	//		if (iArr[0] > iArr[1])
	//			MySwapRef(iArr[0], iArr[1]);
	//
	//		cout << boolalpha;
	//		cout << iArr[0] << " " << iArr[1] << " ";
	//		cout << CheckSorted(iArr[0], iArr[1]) << endl;
	//	}
	//}

//3.
//for (int k = 0; k < 3; k++)
//{
//	for (int j = 0; j < 3; j++)
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			int iArr[3] = { i,j,k };
//			int iSize = sizeof(iArr) / sizeof(iArr[0]);
//
//			for (int e = 0; e < iSize; e++)
//			{
//				cout << iArr[e] << " " << flush;
//			}
//
//			cout << " -> " << flush;
//			// TODO : 정렬 해보기
//			if (iArr[0] > iArr[1])
//				swap(iArr[0], iArr[1]);
//			if (iArr[1] > iArr[2])
//				swap(iArr[1], iArr[2]);
//			if (iArr[0] > iArr[1])
//				swap(iArr[0], iArr[1]);
//
//			for (int e = 0; e < iSize; e++)
//			{
//				cout << iArr[e] << " " << flush;
//			}
//
//			cout << boolalpha;
//			cout << ChecSortedArr(iArr, iSize);
//			cout << endl;
//		}
//	}
//}



#pragma endregion