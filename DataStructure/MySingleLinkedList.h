#pragma once
#include <iostream>

using namespace std;

template<typename T>
class CMySingleLinkedList
{
public:
	typedef struct tagNode
	{
		T item = T();
		tagNode* pNextNode = { nullptr };

	}NODE;


public:
	CMySingleLinkedList(): m_pFirstNode(nullptr) {}
	CMySingleLinkedList(const CMySingleLinkedList& _List) : m_pFirstNode(nullptr)
	{
		NODE* pNewNode = _List.m_pFirstNode;

		while (pNewNode != nullptr)
		{
			Push_Back_SLL(pNewNode->item);
			pNewNode = pNewNode->pNextNode;
		}
	}
	~CMySingleLinkedList()
	{
		Clear_SLL();
	}

public:
	NODE*				Get_FristNode() const { return m_pFirstNode; }


public:
	int					Size_SLL();
	bool				isEmpty_SLL();
	T					Front_SLL();
	T					Back_SLL();
	void				Clear_SLL();
	void				Remove_SLL(NODE* pNode);
	void				Print_SLL();
	void				Reverse_SLL();
	void				Insert_Back_SLL(NODE* pNode, T Item);
	void				Push_Front_SLL(T Item);
	void				Push_Back_SLL(T Item);
	void				Pop_Front_SLL();
	void				Pop_Back_SLL();


	NODE*				Find_SLL(T Item);
	

protected:
	NODE*				m_pFirstNode = { nullptr };

};

template<typename T>
inline void CMySingleLinkedList<T>::Clear_SLL()
{
	NODE* pCurrentNode = m_pFirstNode;

	while (pCurrentNode != nullptr)
	{
		NODE* pNextNode = pCurrentNode->pNextNode;

		delete pCurrentNode;

		pCurrentNode = pNextNode;
	}

	m_pFirstNode = nullptr;
}

template<typename T>
inline void CMySingleLinkedList<T>::Remove_SLL(NODE* pNode)
{
	if (nullptr == m_pFirstNode || nullptr == pNode)
		return;
	
	if (m_pFirstNode == pNode)
	{
		m_pFirstNode = m_pFirstNode->pNextNode;
		delete pNode;
		pNode = nullptr;
		return;
	}

	NODE* pPrevNode = m_pFirstNode;

	while (nullptr != pPrevNode->pNextNode && pPrevNode->pNextNode != pNode)
	{
		pPrevNode = pPrevNode->pNextNode;
	}
	
	pPrevNode->pNextNode = pNode->pNextNode;
	pNode->pNextNode = nullptr;
	delete pNode;
	pNode = nullptr;
}

template<typename T>
inline void CMySingleLinkedList<T>::Print_SLL()
{
	NODE* pCurrentNode = m_pFirstNode;

	while (pCurrentNode != nullptr)
	{
		cout << pCurrentNode->item << " ";
		pCurrentNode = pCurrentNode->pNextNode;
	}

	cout << endl;
}

template<typename T>
inline void CMySingleLinkedList<T>::Reverse_SLL()
{
	NODE* pCurrentNode = m_pFirstNode;
	NODE* pPrevNode = nullptr;

	while (nullptr != pCurrentNode)
	{
		NODE* pNextNode = pCurrentNode->pNextNode;
		pCurrentNode->pNextNode = pPrevNode;
		pPrevNode = pCurrentNode;             
		pCurrentNode = pNextNode;
	}
	m_pFirstNode = pPrevNode;


}


template<typename T>
inline void CMySingleLinkedList<T>::Insert_Back_SLL(NODE* pNode, T Item)
{
	if (pNode == nullptr)
		return;

	NODE* pNewNode = new NODE;
	pNewNode->item = Item;
	pNewNode->pNextNode = nullptr;

	pNewNode->pNextNode = pNode->pNextNode;
	pNode->pNextNode = pNewNode;

}

template<typename T>
inline void CMySingleLinkedList<T>::Push_Front_SLL(T Item)
{
	NODE* pCurrentNode = new NODE();

	if (!isEmpty_SLL())
	{
		pCurrentNode->item = Item;
		pCurrentNode->pNextNode = m_pFirstNode;
		m_pFirstNode = pCurrentNode;
	}
	else
	{
		pCurrentNode->item = Item;
		m_pFirstNode = pCurrentNode;
	}
}

template<typename T>
inline void CMySingleLinkedList<T>::Push_Back_SLL(T Item)
{
	NODE* pNewNode = new NODE;
	pNewNode->item = Item;
	pNewNode->pNextNode = nullptr;

	if (isEmpty_SLL())
	{
		m_pFirstNode = pNewNode;
		return;
	}
	
	NODE* pCurrentNode = m_pFirstNode;

	while (nullptr != pCurrentNode->pNextNode)
	{
		pCurrentNode = pCurrentNode->pNextNode;
	}

	pCurrentNode->pNextNode = pNewNode;
}

template<typename T>
inline void CMySingleLinkedList<T>::Pop_Front_SLL()
{
	if (nullptr == m_pFirstNode)
		return;

	NODE* pDeleteNode = m_pFirstNode;
	m_pFirstNode = m_pFirstNode->pNextNode;

	pDeleteNode->pNextNode = nullptr;
	delete pDeleteNode;
	pDeleteNode = nullptr;
}

template<typename T>
inline void CMySingleLinkedList<T>::Pop_Back_SLL()
{
	if (nullptr == m_pFirstNode)
		return;

	NODE* pPrevNode = m_pFirstNode;
	NODE* pCurrentNode = m_pFirstNode;

	while (pCurrentNode->pNextNode != nullptr)
	{
		pPrevNode = pCurrentNode;
		pCurrentNode = pCurrentNode->pNextNode;
	}

	pPrevNode->pNextNode = nullptr;
	delete pCurrentNode;
	pCurrentNode = nullptr;
}

template<typename T>
inline typename CMySingleLinkedList<T>::NODE*
CMySingleLinkedList<T>::Find_SLL(T Item)
{
	NODE* pCurrentNode = m_pFirstNode;

	while (nullptr != pCurrentNode->pNextNode)
	{
		if (pCurrentNode->item == Item)
		{
			return pCurrentNode;
		}
		pCurrentNode = pCurrentNode->pNextNode;
	}

	return nullptr;
}


template<typename T>
inline bool CMySingleLinkedList<T>::isEmpty_SLL()
{
	if (nullptr == m_pFirstNode)
		return true;
	
	return false;
}

template<typename T>
inline int CMySingleLinkedList<T>::Size_SLL()
{
	int iSize = 0;

	NODE* pCurrentNode = m_pFirstNode;

	while (pCurrentNode != nullptr)
	{
		iSize++;
		pCurrentNode = pCurrentNode->pNextNode;
	}

	return iSize;
}

template<typename T>
inline T CMySingleLinkedList<T>::Front_SLL()
{
	return m_pFirstNode->item;
}

template<typename T>
inline T CMySingleLinkedList<T>::Back_SLL()
{
	NODE* pCurrentNode = m_pFirstNode;

	while (nullptr != pCurrentNode->pNextNode)
	{
		pCurrentNode = pCurrentNode->pNextNode;
	}

	return pCurrentNode->item;
}
