#pragma once
#include "MyQueue.h"

template<typename T>
class MyDeque : public MyQueue<T>
{
public:
	typedef MyQueue<T> BASE;
	


public:
	MyDeque(int _iCapacity) : MyQueue<T>(_iCapacity) {};


public:
	T&			Get_Front() { return BASE::Get_Front(); }
	T&			Get_Rear() { return BASE::Get_Rear(); }



	void		Push_Front_Deq(const T& Item);
	void		Push_Back_Deq(const T& Item);
	void		Pop_Front_Deq();
	void		Pop_Back_Deq();

};

template<typename T>
inline void MyDeque<T>::Push_Front_Deq(const T& Item)
{
	if (BASE::isFull_Queue())
		BASE::Resize_Queue();

	BASE::m_pQueue[BASE::m_iFront] = Item;
	BASE::m_iFront = (BASE::m_iFront - 1 + BASE::m_iCapacity) % BASE::m_iCapacity;

}

template<typename T>
inline void MyDeque<T>::Push_Back_Deq(const T& Item)
{
	BASE::Enqueue(Item);
}

template<typename T>
inline void MyDeque<T>::Pop_Front_Deq()
{
	BASE::Dequeue();
}

template<typename T>
inline void MyDeque<T>::Pop_Back_Deq()
{
	if (BASE::isEmpty_Queue())
		return;

	BASE::m_iRear = (BASE::m_iRear - 1 + BASE::m_iCapacity) % BASE::m_iCapacity;
}
