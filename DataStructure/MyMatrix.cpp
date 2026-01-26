#include "MyMatrix.h"
#include <iostream>

using namespace std;

MyMatrix::MyMatrix() {}

MyMatrix::MyMatrix(int _iNumRow, int _iNumCol)
{
    m_iNumRows = _iNumRow;
    m_iNumCols = _iNumCol;

    m_pMatrix = new float[_iNumRow * _iNumCol];

    for (int i = 0; i < m_iNumRows; i++)
    {
        for (int j = 0; j < m_iNumCols; j++)
        {
            m_pMatrix[i * m_iNumCols + j] = 0.f;
        }
    }
}

MyMatrix::MyMatrix(const MyMatrix& _Mat)
{
    m_iNumRows = _Mat.m_iNumRows;
    m_iNumCols = _Mat.m_iNumCols;

    int iSize = m_iNumRows * m_iNumCols;
    m_pMatrix = new float[iSize];

    for(int i = 0; i < iSize; i++)
    {
        m_pMatrix[i] = _Mat.m_pMatrix[i];
    }
}

MyMatrix::~MyMatrix()
{
    if (nullptr != m_pMatrix)
    {
        delete[] m_pMatrix;
        m_pMatrix = nullptr;
    }
}

void MyMatrix::Set_Value(int _iRow, int _iCol, float _fValue)
{
    m_pMatrix[_iRow * m_iNumCols + _iCol] = _fValue;
}

float MyMatrix::Get_Value(int _iRow, int _iCol) const
{
    return m_pMatrix[_iRow * m_iNumCols + _iCol];
}

MyMatrix MyMatrix::Add(const MyMatrix& _Mat)
{
    MyMatrix Temp(m_iNumRows, m_iNumCols);

    for (int i = 0; i < m_iNumRows; i++)
    {
        for (int j = 0; j < m_iNumCols; j++)
        {
            int iIndex = i * m_iNumCols + j;
            Temp.m_pMatrix[iIndex] =
                m_pMatrix[iIndex] + _Mat.m_pMatrix[iIndex];
        }
    }

    return Temp;
}

MyMatrix MyMatrix::Transpose()
{
    MyMatrix Temp(m_iNumCols, m_iNumRows);

    for (int i = 0; i < m_iNumRows; i++)
    {
        for (int j = 0; j < m_iNumCols; j++)
        {
            int iIndex = i + m_iNumRows * j;
            Temp.Set_Value(j,i,Get_Value(i,j));
        }
    }
    return Temp;
}

void MyMatrix::Print()
{
    for (int i = 0; i < m_iNumRows; i++)
    {
        for (int j = 0; j < m_iNumCols; j++)
        {
            cout << Get_Value(i,j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}
