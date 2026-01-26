#include "MySparsePolynomial.h"
#include <iostream>

using namespace std;

CMySparsePolynomial::CMySparsePolynomial()
{
}

CMySparsePolynomial::~CMySparsePolynomial()
{
    if (nullptr != m_pTerms)
    {
        delete[] m_pTerms;
        m_pTerms = nullptr;
    }
}

float CMySparsePolynomial::Eval(int _fX)
{
    float fResult = 0.f;
    for (int i = 0; i < m_iNumTerm; i++)
    {
         fResult += m_pTerms[i].fCoef* powf(_fX,static_cast<float>(m_pTerms[i].iExp));
    }
    return fResult;
}

void CMySparsePolynomial::NewTerm(float _fCoef, int _iExp)
{
    if (_fCoef == 0)
        return;

    if (m_iNumTerm >= m_iCapacity)
    {
        m_iCapacity = m_iCapacity > 0 ? m_iCapacity * 2 : 1;

        TERM* pNewTerm = new TERM[m_iCapacity];

        if (m_pTerms)
            memcpy(pNewTerm, m_pTerms, sizeof(TERM) * m_iNumTerm);

        delete[] m_pTerms;
        m_pTerms = pNewTerm;
    }

    m_pTerms[m_iNumTerm].fCoef = _fCoef;
    m_pTerms[m_iNumTerm].iExp = _iExp;

    m_iNumTerm++;

}

void CMySparsePolynomial::NewTerm_Sort(float _fCoef, int _iExp)
{
    if (_fCoef == 0)
        return;

    for (int i = 0; i < m_iNumTerm; i++)
    {
        if (m_pTerms[i].iExp == _iExp)
        {
            m_pTerms[i].fCoef += _fCoef;
            return;
        }
    }

    if (m_iNumTerm >= m_iCapacity)
    {
        m_iCapacity = m_iCapacity > 0 ? m_iCapacity * 2 : 1;

        TERM* pNewTerm = new TERM[m_iCapacity];
        if (m_pTerms)
            memcpy(pNewTerm, m_pTerms, sizeof(TERM) * m_iNumTerm);

        delete[] m_pTerms;
        m_pTerms = pNewTerm;
    }

    int iIndex = 0;
    while (iIndex < m_iNumTerm && m_pTerms[iIndex].iExp < _iExp)
    {
        iIndex++;
    }

    for (int i = m_iNumTerm; i > iIndex; i--)
    {
        m_pTerms[i] = m_pTerms[i - 1];
    }

    m_pTerms[iIndex].fCoef = _fCoef;
    m_pTerms[iIndex].iExp = _iExp;

    m_iNumTerm++;
}

void CMySparsePolynomial::Print()
{
    bool isFirst = true;

    for (int i = 0; i < m_iNumTerm; i++)
    {
        if (!isFirst)
            cout << " + ";
        cout << m_pTerms[i].fCoef;

        if (m_pTerms[i].iExp != 0)
            cout << "*" << "x^" << m_pTerms[i].iExp;
        isFirst = false;
    }
    cout << endl;
}

CMySparsePolynomial CMySparsePolynomial::Add(const CMySparsePolynomial& _Poly)
{
    CMySparsePolynomial Temp;

    int i = 0;
    int j = 0;

    while (i < m_iNumTerm && j < _Poly.m_iNumTerm)
    {
        if (m_pTerms[i].iExp == _Poly.m_pTerms[j].iExp)
        {
            Temp.NewTerm(m_pTerms[i].fCoef + _Poly.m_pTerms[j].fCoef,m_pTerms[i].iExp);
            i++;
            j++;
        }
        else if (m_pTerms[i].iExp < _Poly.m_pTerms[j].iExp)
        {
            Temp.NewTerm(m_pTerms[i].fCoef,m_pTerms[i].iExp);
            i++;
        }
        else
        {
            Temp.NewTerm(_Poly.m_pTerms[j].fCoef, _Poly.m_pTerms[j].iExp);
            j++;
        }

    }

    for (; i < m_iNumTerm; i++)
    {
        Temp.NewTerm(m_pTerms[i].fCoef,m_pTerms[i].iExp);
    }
    for (; j < _Poly.m_iNumTerm; j++)
    {
        Temp.NewTerm(_Poly.m_pTerms[j].fCoef, _Poly.m_pTerms[j].iExp);

    }

    return Temp;
}
