#include "MyArray2D.h"
#include <iostream>

using namespace std;

MyArray2D::MyArray2D() :m_ppArr(nullptr), m_iNumRows(0), m_iNumCols(0) {}

MyArray2D::MyArray2D(int _iNumRows, int _iNumCols)
{
    m_iNumRows = _iNumRows;
    m_iNumCols = _iNumCols;

    m_ppArr = new float*[m_iNumRows];
    
    for (int i = 0; i < m_iNumRows; i++)
    {
        m_ppArr[i] = new float[m_iNumCols];

        for (int j = 0; j < m_iNumCols; j++)
        {
            m_ppArr[i][j] = 0.f;
        }
    }

}

MyArray2D::MyArray2D(const MyArray2D& _Arr2D)
{
    m_iNumRows = _Arr2D.m_iNumRows;
    m_iNumCols = _Arr2D.m_iNumCols;

    m_ppArr = new float*[m_iNumRows];
    
    for (int i = 0; i < m_iNumRows; i++)
    {
        m_ppArr[i] = new float[m_iNumCols];

        for (int j = 0; j < m_iNumCols; j++)
        {
            m_ppArr[i][j] = _Arr2D.m_ppArr[i][j];
        }
    }


}

MyArray2D::~MyArray2D()
{
    for (int i = 0; i < m_iNumRows; i++)
    {
        delete[] m_ppArr[i]; 
    }
    delete[] m_ppArr;    
    m_ppArr = nullptr;
}

float MyArray2D::Get_Value(int _iRow, int _iCol) const
{
    return m_ppArr[_iRow][_iCol];
}

void MyArray2D::Set_Value(int _iRow, int _iCol, float _fValue)
{
    m_ppArr[_iRow][_iCol] = _fValue;
}

void MyArray2D::Print()
{
    for (int i = 0; i < m_iNumRows; i++)
    {
        for (int j = 0; j < m_iNumCols; j++)
        {
            cout << m_ppArr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

MyArray2D MyArray2D::Add(const MyArray2D& _Mat)
{
    MyArray2D Temp(m_iNumRows,m_iNumCols);
   
    for (int i = 0; i < m_iNumRows; i++)
    {
        for (int j = 0; j < m_iNumCols; j++)
        {
            Temp.m_ppArr[i][j] =
                m_ppArr[i][j] + _Mat.m_ppArr[i][j];
        }
    }

    return Temp;
}

MyArray2D MyArray2D::Transpose()
{
    MyArray2D Temp(m_iNumCols, m_iNumRows);

    for (int i = 0; i < m_iNumRows; i++)
    {
        for (int j = 0; j < m_iNumCols; j++)
        {
            Temp.Set_Value(j, i, Get_Value(i, j));
        }
    }

    return Temp;
}
