#pragma once

inline int CountTargetNumber(int* _iArr, int iSize, int iTarget)
{
	int iCount = 0;

	for (int i = 0; i < iSize; i++)
	{
		if (_iArr[i] == iTarget)
			iCount++;
	}

	return iCount;
}

inline int SequentialSearch(int* iArr, int iSize, int iTarget)
{
	int iIndex = -1;

	for (int i = 0; i < iSize; i++)
	{
		if (iTarget == iArr[i])
		{
			iIndex = i;
			break;
		}
	}
	return iIndex;
}

inline int SortedCountHelper(int* _iArr, int _iSize, int _iTarget, int _iStart)
{
	int iCount = 0;

	for (int i = _iStart; i < _iSize; i++)
	{
		if (_iArr[i] == _iTarget)
			iCount++;
		else
			break; // 보안점 : 정렬이 되어 있기 때문에 조기종료가 가능하다!
	}
	return iCount;

}

inline int SortedCount(int* _iArr, int _iSize, int _iTarget)
{
	int i = SequentialSearch(_iArr, _iSize, _iTarget);

	if (i >= 0)
		return SortedCountHelper(_iArr, _iSize, _iTarget, i + 1) + 1;
	else
		return 0;
}



inline int BinarySearch(int* iArr, int iSize, int iTarget)
{
	int iLeft = 0;
	int iRight = iSize - 1;

	while (iLeft <= iRight)
	{
		int iMiddle = (iRight + iLeft) / 2;
		cout << "Middle: " << iMiddle << endl;

		if (iArr[iMiddle] < iTarget)
		{
			iLeft = iMiddle + 1;
			cout << "Left : " << iLeft << endl;
		}
		else if (iArr[iMiddle] > iTarget)
		{

			iRight = iMiddle - 1;
			cout << "Right : " << iRight << endl;
		}
		else
		{
			cout << "Found: " << iMiddle << endl;
			return iMiddle;
		}

	}
	cout << "Not Found " << endl;
	return -1;
}