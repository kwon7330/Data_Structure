#pragma once
#include <iostream>

using namespace std;

template<typename T>
class CMyBinaryTree
{
public:
	typedef struct tagNode
	{
		T Item = {};
		tagNode* pLeft = { nullptr };
		tagNode* pRight = { nullptr };

	}NODE;

public:
	CMyBinaryTree() {};
	CMyBinaryTree(NODE* pRoot)
	{
		m_pRoot = pRoot;
	}
	~CMyBinaryTree()
	{
		Delete_Tree(m_pRoot);
	}

public:
	bool			IsEmpty_BT();
	int				Sum_BT();
	int				Sum_BT(NODE* pNode);
	int				Height_BT();
	int				Height_BT(NODE* pNode);
	void			Visit_BT(NODE* pNode);
	void			Preorder() { Preorder(m_pRoot); }
	void			Preorder(NODE* pNode);
	void			Inorder() { Inorder(m_pRoot); }
	void			Inorder(NODE* pNode);
	void			Postorder() { Postorder(m_pRoot); }
	void			Postorder(NODE* pNode);
	void			Levelorder(NODE* pNode, int iLevel);
	void			Delete_Tree(NODE* pNode);
	
private:
	NODE* m_pRoot = { nullptr };


};

template<typename T>
inline bool CMyBinaryTree<T>::IsEmpty_BT()
{
	if (nullptr == m_pRoot)
		return true;

	return false;
}

template<typename T>
inline int CMyBinaryTree<T>::Sum_BT()
{
	return Sum_BT(m_pRoot);
}

template<typename T>
inline int CMyBinaryTree<T>::Sum_BT(NODE* pNode)
{
	if (nullptr == pNode)
		return 0;
	
	return pNode->Item + Sum_BT(pNode->pLeft) + Sum_BT(pNode->pRight);
}

template<typename T>
inline int CMyBinaryTree<T>::Height_BT()
{
	return Height_BT(m_pRoot);
}

template<typename T>
inline int CMyBinaryTree<T>::Height_BT(NODE* pNode)
{
	if (nullptr == pNode->pLeft || nullptr == pNode->pRight)
		return 1;

	return Height_BT(pNode->pLeft) + Height_BT(pNode->pRight) + 1;
}

template<typename T>
inline void CMyBinaryTree<T>::Visit_BT(NODE* pNode)
{
	// 트리를 순회하다가 해당 노드에 방문해서 작업을 하는 함수.
	cout << pNode->Item << " ";
}

template<typename T>
inline void CMyBinaryTree<T>::Preorder(NODE* pNode)
{
	if (nullptr == pNode)
		return;

	Visit_BT(pNode);

	Preorder(pNode->pLeft);
	Preorder(pNode->pRight);

}

template<typename T>
inline void CMyBinaryTree<T>::Inorder(NODE* pNode)
{
	if (nullptr == pNode)
		return;

	Inorder(pNode->pLeft);
	Visit_BT(pNode);
	Inorder(pNode->pRight);
}

template<typename T>
inline void CMyBinaryTree<T>::Postorder(NODE* pNode)
{
	if (nullptr == pNode)
		return;

	Postorder(pNode->pLeft);
	Postorder(pNode->pRight);
	Visit_BT(pNode);
}

template<typename T>
inline void CMyBinaryTree<T>::Levelorder(NODE* pNode, int iLevel)
{
	if (nullptr == pNode)
		return;

	if (1 == iLevel)
		Visit_BT(pNode);
	else
	{
		Levelorder(pNode->pLeft, iLevel - 1);
		Levelorder(pNode->pRight, iLevel - 1);
	}


	
}

template<typename T>
inline void CMyBinaryTree<T>::Delete_Tree(NODE* pNode)
{
	if (!pNode) 
		return;

	Delete_Tree(pNode->pLeft);
	Delete_Tree(pNode->pRight);

	delete pNode;
	pNode = nullptr;
}

