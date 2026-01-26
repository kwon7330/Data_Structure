#pragma once

typedef struct tagTerm
{
	float	fCoef = 0.f;
	int		iExp = 0.f;

}TERM;


// 희소 다항식

/* 0인 항은 저장하지 않음
항의 개수 = 실제 의미 있는 항의 개수
보통 지수 기준 정렬이 매우 중요 */

class CMySparsePolynomial
{
public:
	CMySparsePolynomial();
	~CMySparsePolynomial();


public:
	TERM*				Get_Terms_Ptr() const { return m_pTerms; }
	int					Get_NumTerm() const { return m_iNumTerm; }


public:
	float				Eval(int _fX);
	void				NewTerm(float _fCoef, int _iExp);
	void				NewTerm_Sort(float _fCoef, int _iExp);
	void				Print();
	CMySparsePolynomial Add(const CMySparsePolynomial& _Poly);

private:
	int					m_iNumTerm = {};
	int					m_iCapacity = {};
	
	TERM*				m_pTerms = { nullptr };


};

