#include "MySparseMatrix.h"
#include <iostream>

using namespace std;

MySparseMatrix::MySparseMatrix()
    :m_pTerms(nullptr), m_iNumRows(0), m_iNumCols(0), m_iCapacity(0), m_iNumTerms(0) {}

MySparseMatrix::MySparseMatrix(int _iNumRows, int _iNumCols, int _iCapacity)
{
    m_iNumRows = _iNumRows;
    m_iNumCols = _iNumCols;
    m_iCapacity = _iCapacity;
    m_iNumTerms = 0;

    m_pTerms = new TERM[m_iCapacity];
  
}

MySparseMatrix::MySparseMatrix(const MySparseMatrix& _Mat)
{
    m_iNumRows = _Mat.m_iNumRows;
    m_iNumCols = _Mat.m_iNumCols;
    m_iCapacity = _Mat.m_iCapacity;
    m_iNumTerms = _Mat.m_iNumTerms;

    m_pTerms = new TERM[m_iCapacity];

    memcpy(m_pTerms,_Mat.m_pTerms,sizeof(TERM) * m_iNumTerms);
}

MySparseMatrix::~MySparseMatrix()
{
    delete[] m_pTerms;
    m_pTerms = nullptr;
}

float MySparseMatrix::Get_Value(int _iRow, int _iCol) const
{
    for (int i = 0; i < m_iCapacity; i++)
    {
        if (m_pTerms[i].iRow == _iRow && m_pTerms[i].iCol == _iCol)
            return m_pTerms[i].fValue;
    }

    return -1;
}

void MySparseMatrix::Set_Value(int _iRow, int _iCol, int iValue)
{
    int iIndex = 0;

    while()
}

void MySparseMatrix::Print()
{
}

void MySparseMatrix::Print_Term()
{
}

MySparseMatrix MySparseMatrix::Transpose()
{
    return MySparseMatrix();
}
