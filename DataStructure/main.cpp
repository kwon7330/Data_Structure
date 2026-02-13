#include <iostream>
#include "MyQueue.h"
#include "MyStack.h"
#include "MyDoubleLinkedList.h"

using namespace std;

void Print_Arr(int* _iArr, int _iSize)
{
	for (int i = 0; i < _iSize; i++)
	{
		cout << _iArr[i] << " ";
	}
	cout << endl;
}

typedef struct tagNode
{
	int Data = 0;
	tagNode* pNextNode = nullptr;

}NODE;

#pragma region 사칙연산

int Prec(char _Operator)
{
	int iPriority = 0;

	if (_Operator == '-' || _Operator == '+')
		iPriority = 1;
	else if (_Operator == '*' || _Operator == '/')
		iPriority = 2;

	return iPriority;
}

void InfixToPostFix(MyQueue<char>& _Input, MyQueue<char>& _Output)
{
	MyStack<char>OperatorStk;

	while (!_Input.isEmpty_Queue())
	{
		char cValue = _Input.Get_Front();
		_Input.Dequeue();

		if (cValue >= '0' && cValue <= '9')
			_Output.Enqueue(cValue);
		else if (cValue == '(')
			OperatorStk.Push_Stack(cValue);

		else if (cValue == ')')
		{
			while (OperatorStk.Top() != '(')
			{
				_Output.Enqueue(OperatorStk.Top());
				OperatorStk.Pop_Stack();
			}
			OperatorStk.Pop_Stack();
		}
		else
		{
			while (!OperatorStk.isEmpty() && Prec(cValue) <= Prec(OperatorStk.Top()))
			{
				_Output.Enqueue(OperatorStk.Top());
				OperatorStk.Pop_Stack();
			}

			OperatorStk.Push_Stack(cValue);
		}


	}

	while (!OperatorStk.isEmpty())
	{
		_Output.Enqueue(OperatorStk.Top());
		OperatorStk.Pop_Stack();
	}

}

int CalcutateOutFix(MyQueue<char>& _Output)
{
	int iResult = 0;
	MyStack<int>Stk;

	while (!_Output.isEmpty_Queue())
	{
		char cValue = _Output.Get_Front();
		_Output.Dequeue();
		if (cValue >= '0' && cValue <= '9')
		{
			Stk.Push_Stack(cValue - '0');
		}
		else
		{
			int iValue1 = Stk.Top();
			Stk.Pop_Stack();
			int iValue2 = Stk.Top();
			Stk.Pop_Stack();

			switch (cValue)
			{
			case '+' :
				iResult = iValue1 + iValue2;
				break;
			case '-':
				iResult = iValue2 - iValue1;
				break;
			case '*':
				iResult = iValue1 * iValue2;
				break;
			case '/':
				iResult = iValue2 / iValue1;
				break;
			}

			Stk.Push_Stack(iResult);
		}
	}

	return iResult;
}

#pragma endregion


void RecurPrint(NODE* pNode)
{
	if (nullptr == pNode)
		return;

	cout << pNode->Data << " ";
	RecurPrint(pNode->pNextNode);

}
void IterPrint(NODE* pNode)
{
	NODE* pCurrent = pNode;

	while (true)
	{
		cout << pCurrent->Data << " ";
		pCurrent = pCurrent->pNextNode;

		if (pCurrent->pNextNode == nullptr)
		{
			cout << pCurrent->Data << endl;
			break;
		}
	}

	delete pCurrent;
	pCurrent = nullptr;
}


int main()
{
	CMyDoubleLinkedList<int> DLL;
	DLL.Push_Back_DLL(1);
	DLL.Push_Back_DLL(2);
	DLL.Push_Front_DLL(0);

	DLL.Print_DLL();
	cout << endl;

	DLL.Reverse_DLL();
	DLL.Print_DLL();

	CMyDoubleLinkedList<int>::NODE* pNode = DLL.Find_DLL(2);

	if(nullptr != pNode)
		cout << pNode->Item << endl;
	
	DLL.Remove_DLL(pNode);
	DLL.Print_DLL();

	return 0;
}