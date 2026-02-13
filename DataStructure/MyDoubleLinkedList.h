#pragma once
#include<iostream>

using namespace std;


template<typename T>
class CMyDoubleLinkedList
{
public:
	typedef struct tagNode
	{
		T	Item = {};
		tagNode* pRight = { nullptr };
		tagNode* pLeft = { nullptr };
	}NODE;

public:
	CMyDoubleLinkedList() {}
	CMyDoubleLinkedList(const CMyDoubleLinkedList& DLL)
	{
		NODE* pNewNode = DLL.m_pFirstNode;
		while (pNewNode != nullptr)
		{
			Push_Back_DLL(pNewNode->Item);
			pNewNode = pNewNode->pRight;
		}
	}
	~CMyDoubleLinkedList() { Clear_DLL(); }

public:
	bool		isEmpty_DLL();
	int			Size_DLL();
	T			Front_DLL();
	T			Back_DLL();
	void		Clear_DLL();
	void		Remove_DLL(NODE* pNode);
	void		Print_DLL();
	void		Reverse_DLL();
	void		Insert_Back_DLL(NODE* pNode, T Item);
	void		Push_Front_DLL(T Item);
	void		Push_Back_DLL(T Item);
	void		Pop_Front_DLL();
	void		Pop_Back_DLL();

	NODE*		Find_DLL(T Item);


private:
	NODE*		m_pFirstNode = { nullptr };

};

template<typename T>
inline bool CMyDoubleLinkedList<T>::isEmpty_DLL()
{
	if (nullptr == m_pFirstNode)
		return true;

	return false;
}

template<typename T>
inline int CMyDoubleLinkedList<T>::Size_DLL()
{
	int iSize = 0;
	NODE* pCurrentNode = m_pFirstNode;
	while (nullptr != pCurrentNode)
	{
		iSize++;
		pCurrentNode = pCurrentNode->pLeft;
	}
	return iSize;
}

template<typename T>
inline T CMyDoubleLinkedList<T>::Front_DLL()
{
	if(!isEmpty_DLL())
		return m_pFirstNode->Item;
}

template<typename T>
inline T CMyDoubleLinkedList<T>::Back_DLL()
{
	NODE* pCurrentNode = m_pFirstNode;
	while (nullptr != pCurrentNode)
	{
		pCurrentNode = pCurrentNode->pLeft;
	}

	return pCurrentNode->Item();
}

template<typename T>
inline void CMyDoubleLinkedList<T>::Clear_DLL()
{
	NODE* pCurrentNode = m_pFirstNode;
	while (nullptr != pCurrentNode)
	{
		NODE* pNextNode = pCurrentNode->pLeft;
		pCurrentNode->pRight = nullptr;
		delete pCurrentNode;
		pCurrentNode = pNextNode;
	}
	m_pFirstNode = nullptr;
}

template<typename T>
inline void CMyDoubleLinkedList<T>::Remove_DLL(NODE* pNode)
{
	NODE* pDeleteNode = m_pFirstNode;

	while (pDeleteNode != nullptr)
	{
		if (pDeleteNode == pNode)
			break;

		pDeleteNode = pDeleteNode->pRight;
	}

	if (pDeleteNode == nullptr)
		return;

	if (pDeleteNode->pLeft != nullptr)
	{
		pDeleteNode->pLeft->pRight = pDeleteNode->pRight;
	}
	else
	{
		m_pFirstNode = pDeleteNode->pRight;
	}

	if (pDeleteNode->pRight != nullptr)
	{
		pDeleteNode->pRight->pLeft = pDeleteNode->pLeft;
	}

	delete pDeleteNode;

}

template<typename T>
inline void CMyDoubleLinkedList<T>::Print_DLL()
{
	NODE* pCurrentNode = m_pFirstNode;
	while (nullptr != pCurrentNode)
	{
		cout << pCurrentNode->Item << " ";
		pCurrentNode = pCurrentNode->pRight;
	}
	cout << endl;
}

template<typename T>
inline void CMyDoubleLinkedList<T>::Reverse_DLL()
{
	NODE* pCurrentNode = m_pFirstNode;
	NODE* pPrevNode = nullptr;

	while (nullptr != pCurrentNode)
	{
		pPrevNode = pCurrentNode;
		pCurrentNode = pCurrentNode->pRight;
		swap(pPrevNode->pLeft,pPrevNode->pRight);
	}
	m_pFirstNode = pPrevNode;
}

template<typename T>
inline void CMyDoubleLinkedList<T>::Insert_Back_DLL(NODE* pNode, T Item)
{
	if (nullptr == pNode)
		return;

	NODE* pNewNode = new NODE;
	pNewNode->Item = Item;

	NODE* pCurrentNode = pNode;

	pNewNode->pLeft = pCurrentNode;
	pNewNode->pRight = pCurrentNode->pRight;


	if (nullptr != pCurrentNode->pRight)
		pCurrentNode->pRight->pLeft = pNewNode;

	pCurrentNode->pRight = pNewNode;

}

template<typename T>
inline void CMyDoubleLinkedList<T>::Push_Front_DLL(T Item)
{
	if (nullptr == m_pFirstNode)
		return;

	NODE* pNewNode = new NODE;
	pNewNode->Item = Item;
	
	m_pFirstNode->pLeft = pNewNode;
	pNewNode->pRight = m_pFirstNode;
	m_pFirstNode = pNewNode;
	
}

template<typename T>
inline void CMyDoubleLinkedList<T>::Push_Back_DLL(T Item)
{
	NODE* pNewNode = new NODE;

	if (nullptr == m_pFirstNode)
	{
		pNewNode->Item = Item;
		m_pFirstNode = pNewNode;
		return;
	}

	NODE* pCurrentNode = m_pFirstNode;
	while (pCurrentNode->pRight != nullptr)
	{
		pCurrentNode = pCurrentNode->pRight;
	}
	pNewNode->Item = Item;
	pNewNode->pLeft = pCurrentNode;
	pCurrentNode->pRight = pNewNode;
	
}

template<typename T>
inline void CMyDoubleLinkedList<T>::Pop_Front_DLL()
{
	if (nullptr == m_pFirstNode)
		return;

	NODE* pDeleteNode = m_pFirstNode;
	m_pFirstNode = pDeleteNode->pRight;

	if (m_pFirstNode != nullptr)
		m_pFirstNode->pLeft = nullptr;

	delete pDeleteNode;
}

template<typename T>
inline void CMyDoubleLinkedList<T>::Pop_Back_DLL()
{
	if (nullptr == m_pFirstNode)
		return;
	NODE* pDeleteNode = m_pFirstNode;

	if (nullptr == m_pFirstNode->pRight)
	{
		m_pFirstNode = nullptr;
		return;
	}

	while (nullptr != pDeleteNode->pRight)
	{
		pDeleteNode = pDeleteNode->pRight;
	}

	pDeleteNode->pLeft->pRight = nullptr;
	delete pDeleteNode;
}

template<typename T>
inline typename CMyDoubleLinkedList<T>::NODE* 
CMyDoubleLinkedList<T>::Find_DLL(T Item)
{
	NODE* pCurrentNode = m_pFirstNode;

	while (nullptr != pCurrentNode)
	{
		if (pCurrentNode->Item == Item)
		{
			return pCurrentNode;
		}
		pCurrentNode = pCurrentNode->pRight;
	}

	return nullptr;
}
