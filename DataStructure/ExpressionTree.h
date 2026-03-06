#pragma once
#include <iostream>
#include <stack>

using namespace std;

template <typename T>

class CExpressionTree
{
public:
	typedef struct tagNode
	{
		tagNode*	pLeft;
		tagNode*	pRight;
		T			Data;

	}NODE;
public:
	CExpressionTree(const char* Infix);
	~CExpressionTree();

public:

	int				Evaluate_ET(NODE* pNode); // 수식 계산 
	void			Infix_ET(NODE* pNode); // 중위 표기 식 출력
	void			Posfix_ET(NODE* pNode); // 후위 표기 식 출력  
	void			Delete_ET();


private:
	NODE*			m_pRoot = { nullptr };
};

template<typename T>
inline CExpressionTree<T>::CExpressionTree(const char* Infix)
{
	stack<char> Operator;

	while (*Infix != '\0')
	{
		char c = *Infix;

		if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			Operator.push(c);
		}
		Infix++;
	}
	while (!Operator.empty())
	{
		cout << Operator.top() << " ";
		Operator.pop();
	}
}

template<typename T>
inline CExpressionTree<T>::~CExpressionTree()
{

}

template<typename T>
inline int CExpressionTree<T>::Evaluate_ET(NODE* pNode)
{
	return 0;
}

template<typename T>
inline void CExpressionTree<T>::Infix_ET(NODE* pNode)
{
}

template<typename T>
inline void CExpressionTree<T>::Posfix_ET(NODE* pNode)
{
}

template<typename T>
inline void CExpressionTree<T>::Delete_ET()
{
}
