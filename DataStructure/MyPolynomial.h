#pragma once
class MyPolynomial
{

public:
	MyPolynomial(int _iMaxDegree = 100);
	MyPolynomial(const MyPolynomial& _Poly);
	~MyPolynomial();

public:
	int				MaxDegree();
	float			Eval(float _fX);
	void			NewTerm(const float _fCoef, const int iExp);
	void			Print();
	
	MyPolynomial	Add(const MyPolynomial& _Poly);
	MyPolynomial	Mul(const MyPolynomial& _Poly);

private:
	int				m_iCapacity = {};
	float*			m_pCoeffs = { nullptr };
};

