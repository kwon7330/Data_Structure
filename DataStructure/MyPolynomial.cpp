#include "MyPolynomial.h"
#include <iostream>

using namespace std;

MyPolynomial::MyPolynomial(int _iMaxDegree)
{
	m_iCapacity = _iMaxDegree + 1;
	m_pCoeffs = new float[m_iCapacity];

	for (int i = 0; i < m_iCapacity; i++)
	{
		m_pCoeffs[i] = 0.f;
	}
}

MyPolynomial::MyPolynomial(const MyPolynomial& _Poly)
{
	m_iCapacity = _Poly.m_iCapacity;
	m_pCoeffs = new float[m_iCapacity];
	for (int i = 0; i < m_iCapacity; i++)
	{
		m_pCoeffs[i] = _Poly.m_pCoeffs[i];
	}
}

MyPolynomial::~MyPolynomial()
{
	if (m_pCoeffs != nullptr)
	{
		delete[] m_pCoeffs;
		m_pCoeffs = nullptr;
	}
}

int MyPolynomial::MaxDegree()
{
	return m_iCapacity -1;
}

float MyPolynomial::Eval(float _fX)
{
	float fResult = 0.f;

	for (int i = 0; i < m_iCapacity; i++)
	{
		fResult += m_pCoeffs[i] * powf(_fX, static_cast<float>(i));
	}

	return fResult;
}

void MyPolynomial::NewTerm(const float _fCoef, const int iExp)
{
	m_pCoeffs[iExp] = _fCoef;
}

void MyPolynomial::Print()
{
	bool isFrist = true;
	for (int i = 0; i < m_iCapacity; i++)
	{
		if (m_pCoeffs[i] != 0)
		{
			if (!isFrist)
				cout << " + ";
			cout << m_pCoeffs[i];

			if (i != 0)
				cout << "*" << "x^" << i;
			isFrist = false;
		}
	}
	cout << endl;
}


MyPolynomial MyPolynomial::Add(const MyPolynomial& _Poly)
{

	MyPolynomial TempPoly(MaxDegree());

	for (int i = 0; i < m_iCapacity; i++)
	{
		TempPoly.m_pCoeffs[i] = m_pCoeffs[i] + _Poly.m_pCoeffs[i];
	}

	return TempPoly;
}

MyPolynomial MyPolynomial::Mul(const MyPolynomial& _Poly)
{
	int iResultCap = m_iCapacity + _Poly.m_iCapacity - 1;
	MyPolynomial Temp(iResultCap - 1);

	for (int i = 0; i < m_iCapacity; i++)
	{
		for (int j = 0; j < _Poly.m_iCapacity; j++)
		{
			Temp.m_pCoeffs[i + j] += m_pCoeffs[i] * _Poly.m_pCoeffs[j];
		}
	}

	return Temp;
}
