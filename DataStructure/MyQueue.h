#pragma once
#include <iostream>

using namespace std;

template<typename T>
class MyQueue
{
public:
	MyQueue(int _iCapacity);
	~MyQueue();


public:
	T&			Get_Front();
	T&			Get_Rear();

public:
	bool		isEmpty_Queue();
	bool		isFull_Queue();
	int			Size_Queue();

	void		Resize_Queue();
	void		Enqueue(const T& Item);
	void		Dequeue();
	


protected:
	T*			m_pQueue = { nullptr };
	int			m_iFront = {};
	int			m_iRear = {};
	int			m_iCapacity = {};

};

template<typename T>
inline MyQueue<T>::MyQueue(int _iCapacity)
{
	if (_iCapacity < 2)
		m_iCapacity = 2;
	
	m_iCapacity = _iCapacity;
	m_pQueue = new T[m_iCapacity];
	m_iFront = 0;
	m_iRear = 0;
}

template<typename T>
inline MyQueue<T>::~MyQueue()
{
	if (nullptr != m_pQueue)
	{
		delete[] m_pQueue;
		m_pQueue = nullptr;
	}
}

template<typename T>
inline T& MyQueue<T>::Get_Front()
{
	return m_pQueue[(m_iFront + 1) % m_iCapacity];
}

template<typename T>
inline T& MyQueue<T>::Get_Rear()
{
	return m_pQueue[m_iRear];
}

template<typename T>
inline bool MyQueue<T>::isEmpty_Queue()
{
	if (m_iFront == m_iRear)
		return true;

	return false;
}

template<typename T>
inline bool MyQueue<T>::isFull_Queue()
{
	if (m_iFront == (m_iRear + 1) % m_iCapacity)
		return true;

	return false;
}

template<typename T>
inline int MyQueue<T>::Size_Queue()
{
	// Front가 Rear앞에 있을 때, Rear가 Front 앖에 있을때, Front와 Rear가 같을 때

	if (m_iFront == m_iRear)
		return 0;

	else if (m_iFront < m_iRear)
	{
		return m_iRear - m_iFront;
	}
	else
	{
		return m_iCapacity - (m_iFront - m_iRear);
	}

	return 0;
}

template<typename T>
inline void MyQueue<T>::Resize_Queue()
{
	int iNewCapacity = m_iCapacity * 2;
	T* pNewQueue = new T[iNewCapacity];

	int iSize = Size_Queue();

	for (int i = 0; i < iSize; i++)
	{
		pNewQueue[i + 1] = m_pQueue[(m_iFront + 1 + i) % m_iCapacity];
	}

	delete[] m_pQueue;

	m_pQueue = pNewQueue;
	m_iFront = 0;
	m_iRear = iSize;
	m_iCapacity = iNewCapacity;

}

template<typename T>
inline void MyQueue<T>::Enqueue(const T& Item)
{
	if (isFull_Queue())
		Resize_Queue();

	m_iRear = (m_iRear + 1) % m_iCapacity;
	m_pQueue[m_iRear] = Item;
	
}

template<typename T>
inline void MyQueue<T>::Dequeue()
{
	if (isEmpty_Queue())
		return;

	m_iFront = (m_iFront + 1) % m_iCapacity;
}
