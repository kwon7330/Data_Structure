#pragma once
#include <iostream>

using namespace std;

template<typename T>
class MyStack
{
public:
	MyStack(int iCapacity = 1);
	~MyStack();


public:
	bool			isEmpty() const;
	int				Stack_Size() const;
	T&				Top();
	void			Resize_Stack(int iNewCapacity);
	void			Print_Stack();
	void			Push_Stack(const T& Item);
	void			Pop_Stack();

private:
	T*				m_pStack = { nullptr };
	int				m_iTop = -1;
	int				m_iCapacity = 0;
};

template<typename T>
inline MyStack<T>::MyStack(int iCapacity)
{
	if(iCapacity > 0)
		Resize_Stack(iCapacity);
}

template<typename T>
inline MyStack<T>::~MyStack()
{
	delete[] m_pStack;
	m_pStack = nullptr;
}

template<typename T>
inline bool MyStack<T>::isEmpty() const
{
	if (m_iTop == -1)
		return true;

	return false;
}

template<typename T>
inline int MyStack<T>::Stack_Size() const
{
	return m_iTop + 1;
}

template<typename T>
inline T& MyStack<T>::Top()
{
	return m_pStack[m_iTop];
}

template<typename T>
inline void MyStack<T>::Resize_Stack(int iNewCapacity)
{
	T* pNewStack = new T[iNewCapacity];

	for (int i = 0; i <= m_iTop; ++i)
		pNewStack[i] = m_pStack[i];

	delete[] m_pStack;
	m_pStack = pNewStack;
	m_iCapacity = iNewCapacity;

}

template<typename T>
inline void MyStack<T>::Print_Stack()
{
	for (int i = 0; i < Stack_Size(); i++)
	{
		cout << m_pStack[i] << " ";
	}
	cout << endl;
}

template<typename T>
inline void MyStack<T>::Push_Stack(const T& Item)
{
	if(m_iTop == m_iCapacity - 1)
		Resize_Stack(m_iCapacity * 2);
	//m_iTop++;
	//m_pStack[m_iTop] = Item;

	m_pStack[++m_iTop] = Item;
}

template<typename T>
inline void MyStack<T>::Pop_Stack()
{
	if (isEmpty())
		return;

	m_iTop--;
}


#pragma region 예제 : 문자열 뒤집기

// 문자열 뒤집기

//char szArr[] = "Hello World!";
//int iSize = sizeof(szArr) - 1;
//
//MyStack<char> Stk(iSize);
//
//cout << "Input : " << szArr << endl;
//
//for (int i = 0; i < iSize; i++)
//{
//	Stk.Push_Stack(szArr[i]);
//}
//
//
//for (int i = 0; i < iSize; i++)
//{
//	cout << Stk.Top();
//	Stk.Pop_Stack();
//}
//
//cout << endl;

#pragma endregion


#pragma region 미로 찾기

constexpr int iNumRows = 10;
constexpr int iNumCols = 9;

char szMaze[iNumRows][iNumCols] =
{
	{ '1', '1', '1', '1', '1', '1', '1', '1', '1' },
	{ '1', 'S', '0', '0', '0', '0', '0', '0', '1' },
	{ '1', '0', '0', '0', '0', '0', '0', '0', '1' },
	{ '1', '0', '1', '1', '1', '1', '1', '1', '1' },
	{ '1', '0', '0', '0', '0', '0', '0', '0', '1' },
	{ '1', '1', '1', '1', '1', '0', '1', '1', '1' },
	{ '1', '1', '1', '1', '1', '0', '1', '1', '1' },
	{ '1', '1', '1', '0', '0', '0', '1', '0', '1' },
	{ '1', '0', '0', '0', '0', '0', '0', 'G', '1' },
	{ '1', '1', '1', '1', '1', '1', '1', '1', '1' },
};


void PrintMaze()
{
	for (int i = 0; i < iNumRows; i++)
	{
		for (int j = 0; j < iNumCols; j++)
		{
			cout << szMaze[i][j] << " ";
		}
		cout << endl;
	}
}

typedef struct tagMazePosition
{
	int iRow = 0;
	int iCol = 0;

}MAZEPOS;

void RecurMaze(MAZEPOS Position)
{
	int iRow = Position.iRow;
	int iCol = Position.iCol;

	const char cMark = szMaze[Position.iRow][Position.iCol];

	if (szMaze[iRow][iCol] == 'G')
	{
		cout << "Found!" << endl;
		return;
	}

	if (szMaze[iRow][iCol] != '1' && szMaze[iRow][iCol] != 'X')
	{
		szMaze[iRow][iCol] = 'X';
		RecurMaze({ iRow - 1, iCol });
		RecurMaze({ iRow + 1, iCol });
		RecurMaze({ iRow, iCol - 1 });
		RecurMaze({ iRow, iCol + 1 });
	}

}
#pragma endregion

#pragma region 하노이 탑

MyStack<char> Tower[3];

void PrintTowers()
{
	cout << "Towers" << endl;
	cout << "0 : ";
	Tower[0].Print_Stack();
	cout << "1 : ";
	Tower[1].Print_Stack();
	cout << "2 :";
	Tower[2].Print_Stack();

}
void MoveDisk(int _iFrom, int _iTo)
{
	if (Tower[_iFrom].isEmpty())
	{
		cout << "Tower" << _iFrom << "is Empty" << endl;
		return;
	}

	int iSelectedDisk = Tower[_iFrom].Top();

	if (!Tower[_iTo].isEmpty() && Tower[_iTo].Top() > iSelectedDisk)
	{
		cout << " Cant Move Disk " << _iFrom << " To " << _iTo;
		return;
	}

	Tower[_iFrom].Pop_Stack();
	Tower[_iTo].Push_Stack(iSelectedDisk);

	cout << "Disk Moved " << _iFrom << " To " << _iTo << endl;

}

void RecurMoveDisk(int _iNumDisk, int _iFrom, int _iTemp, int _iTo)
{

	if (_iNumDisk == 0)
		return;

	RecurMoveDisk(_iNumDisk - 1, _iFrom, _iTo, _iTemp);
	MoveDisk(_iFrom, _iTo);
	RecurMoveDisk(_iNumDisk - 1, _iTemp, _iFrom, _iTo);



	/*int iNumDisks = 3;

	for (int i = 0; i < iNumDisks; i++)
	{
		Tower[0].Push_Stack(i + 'A');
	}

	PrintTowers();

	RecurMoveDisk(iNumDisks, 0, 1, 2);

	PrintTowers();*/


}
#pragma endregion