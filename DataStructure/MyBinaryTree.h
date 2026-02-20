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
		tagNode* pRight = { nullptr };
		tagNode* pLeft = { nullptr };

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
	void			Preoreder(NODE* pNode);
	void			Inorder() { Inorder(m_pRoot); }
	void			Inorder(NODE* pNode);
	void			Postorder() { Postorder(m_pRoot); }
	void			Postorder(NODE* pNode);
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
	return 0;
}

template<typename T>
inline void CMyBinaryTree<T>::Visit_BT(NODE* pNode)
{
	// 트리를 순회하다가 해당 노드에 방문해서 작업을 하는 함수.
	cout << pNode->Item << "";
}

template<typename T>
inline void CMyBinaryTree<T>::Preoreder(NODE* pNode)
{
}

template<typename T>
inline void CMyBinaryTree<T>::Inorder(NODE* pNode)
{
}

template<typename T>
inline void CMyBinaryTree<T>::Postorder(NODE* pNode)
{
}

template<typename T>
inline void CMyBinaryTree<T>::Delete_Tree(NODE* pNode)
{

}

