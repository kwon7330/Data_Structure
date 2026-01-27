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