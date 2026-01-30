#include "CMyString.h"
#include <iostream>

using namespace std;

CMyString::CMyString()
{

}

CMyString::CMyString(const char* Init)
{
    
    m_iSize = 0;
    while (Init[m_iSize] != '\0')
        m_iSize++;

    m_szStr = new char[m_iSize + 1];

    for (int i = 0; i < m_iSize; i++)
    {
        m_szStr[i] = Init[i];
    }
    m_szStr[m_iSize] = '\0';

}

CMyString::CMyString(const CMyString& str)
{
    m_szStr = new char[m_iSize + 1];
    for (int i = 0; i < m_iSize; i++)
        m_szStr[i] = str.m_szStr[i];

    m_szStr[m_iSize] = '\0';
    
}

CMyString::~CMyString()
{
    delete[] m_szStr;
    m_szStr = nullptr;
}

bool CMyString::isEmpty()
{
    if (m_iSize == 0)
        return true;
    return false;
}

bool CMyString::isEqual(const CMyString& _str)
{
    if (m_iSize != _str.m_iSize)
        return false;

    for (int i = 0; i < m_iSize; i++)
    {
        if (m_szStr[i] != _str.m_szStr[i])
            return false;
    }

    return true;
}

int CMyString::Length()
{
    return m_iSize;
}

int CMyString::Find(CMyString Pat)
{
    int iIndex = -1;

    for (int i = 0; i <= m_iSize - Pat.Length(); i++)
    {
        for (int j = 0; j < Pat.Length(); j++)
        {
            if (m_szStr[i + j] != Pat.m_szStr[j])
                break;
            if(Pat.m_iSize - 1 == j)
                return i;
        }
    }
    
    return iIndex;
}

void CMyString::Resize(int _iNewSize)
{
    char* pTempStr = new char[_iNewSize + 1];

    int iSize = (_iNewSize < m_iSize) ? _iNewSize : m_iSize;

    for (int i = 0; i < iSize; i++)
    {
        pTempStr[i] = m_szStr[i];
    }
    pTempStr[iSize] = '\0';

    delete[] m_szStr;

    m_iSize = _iNewSize;
    m_szStr = pTempStr;
    

}


void CMyString::Print()
{
    for (int i = 0; i < m_iSize; i++)
    {
        cout << m_szStr[i];
    }

    cout << endl;
}



CMyString CMyString::Substr(int _iStart, int _iNum)
{

    char* strTemp = new char[_iNum + 1];

    for (int i = 0; i < _iNum; ++i)
    {
        strTemp[i] = m_szStr[_iStart + i];
    }

    strTemp[_iNum] = '\0';

    CMyString Result(strTemp);
    delete[] strTemp;

    return Result;
}

CMyString CMyString::Concat(CMyString App_Str)
{
    int iNewSize = m_iSize + App_Str.Length();

    char* strTemp = new char[iNewSize + 1];

    for (int i = 0; i < m_iSize; i++)
    {
        strTemp[i] = m_szStr[i];
    }

    for (int i = 0; i < App_Str.Length(); ++i)
    {
        strTemp[m_iSize + i] = App_Str.m_szStr[i];
    }

    strTemp[iNewSize] = '\0';

    CMyString Result(strTemp);
    delete[] strTemp;

    return Result;
}

CMyString CMyString::Insert(CMyString _t, int _iStart)
{
    int iNewSize = m_iSize + _t.Length();

    char* strTemp = new char[iNewSize + 1];

    for (int i = 0; i < _iStart; i++)
        strTemp[i] = m_szStr[i];

    for (int i = 0; i < _t.Length(); i++)
        strTemp[_iStart + i] = _t.m_szStr[i];

    for (int i = _iStart; i < m_iSize; i++)
        strTemp[_t.Length() + i] = m_szStr[i];

    strTemp[iNewSize] = '\0';

    CMyString Result(strTemp);
    delete[] strTemp;
    strTemp = nullptr;

    return Result;
}
