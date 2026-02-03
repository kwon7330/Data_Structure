#include <iostream>
#include "MyQueue.h"
#include "MyStack.h"

using namespace std;

void Print_Arr(int* _iArr, int _iSize)
{
	for (int i = 0; i < _iSize; i++)
	{
		cout << _iArr[i] << " ";
	}
	cout << endl;
}

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



int main()
{
	const char Infix[] = "(1+2)*3";
	int iSize = sizeof(Infix) - 1;
	
	MyQueue<char>Infixq(iSize);

	for (int i = 0; i < iSize; i++)
	{
		Infixq.Enqueue(Infix[i]);
	}

	Infixq.Print_Queue();

	MyQueue<char> Output(iSize);

	InfixToPostFix(Infixq,Output);

	Output.Print_Queue();
	
	cout << CalcutateOutFix(Output) << endl;

	return 0;
}