#include <iostream>
#include "MyStack.h"

using namespace std;

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


int main()
{
	MAZEPOS Pos{};
	Pos.iRow = 1;
	Pos.iCol = 1;

	PrintMaze();
	RecurMaze(Pos);
	cout << endl;
	PrintMaze();

	return 0;
}