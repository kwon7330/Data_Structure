#pragma once

typedef struct tagTerm
{
	float	fCoef = 0.f;
	int		iExp = 0.f;

}TERM;

class CMySparsePolynomial
{
public:
	CMySparsePolynomial();
	~CMySparsePolynomial();

public:
	float				Eval(int _fX);
	void				NewTerm(float _fCoef, int _iExp);
	void				Print();
	CMySparsePolynomial Add(const CMySparsePolynomial& _Poly);

private:
	int					m_iNumTerm = {};
	int					m_iCapacity = {};
	
	TERM*				m_pTerms = { nullptr };


};

