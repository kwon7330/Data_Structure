#pragma once
#include "MySingleLinkedList.h"

class CMyLinkedPolynomial
{
public:
	typedef struct tagTerm
	{
		float fCoef = 0.f;
		int iExp = 0;

	}TERM;


public:
	CMyLinkedPolynomial();
	~CMyLinkedPolynomial();

public:
	void				NewTerm_SLP(float fCoef, int iExp); // 새로운 항을 추가
	void				Print_SLP(); 
	float				Eval_SLP(float FX); // 합계산


	CMyLinkedPolynomial Add_SLP(const CMyLinkedPolynomial& Poly); // 두개 다항식 합치기

private:
	CMySingleLinkedList<TERM> m_List;

};

