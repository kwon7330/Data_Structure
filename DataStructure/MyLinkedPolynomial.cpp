#include "MyLinkedPolynomial.h"

CMyLinkedPolynomial::CMyLinkedPolynomial()
{
}

CMyLinkedPolynomial::~CMyLinkedPolynomial()
{
}

void CMyLinkedPolynomial::NewTerm_SLP(float fCoef, int fExp)
{
    TERM NewTerm = { fCoef,fExp };

    if (m_List.isEmpty_SLL())
    {
        m_List.Push_Back_SLL(NewTerm);
        return;
    }

    auto pCurrent = m_List.Get_FristNode();

    while (nullptr != pCurrent)
    {
        if (pCurrent->item.iExp == NewTerm.iExp)
        {
            pCurrent->item.fCoef += NewTerm.fCoef;
            return;
        }

        if (pCurrent->item.iExp < NewTerm.iExp)
        {
            m_List.Push_Front_SLL(NewTerm);
            return;
        }
        pCurrent = pCurrent->pNextNode;
    }

    m_List.Push_Back_SLL(NewTerm);
}

void CMyLinkedPolynomial::Print_SLP()
{
   auto* pCurrentNode = m_List.Get_FristNode();
    for (int i = 0; i < m_List.Size_SLL(); i++)
    {
        if (pCurrentNode && pCurrentNode->item.iExp > 1)
            cout << pCurrentNode->item.fCoef << "x" << "^" << pCurrentNode->item.iExp << " ";
        else
            cout << pCurrentNode->item.fCoef;

        if(nullptr != pCurrentNode->pNextNode)
            cout << " + " ;

        pCurrentNode = pCurrentNode->pNextNode;
    }
}

float CMyLinkedPolynomial::Eval_SLP(float FX)
{
    float fSum = 0;
    auto* pCurrent = m_List.Get_FristNode();

    while (nullptr != pCurrent)
    {
        fSum += pCurrent->item.fCoef * pow(FX, pCurrent->item.iExp);
        pCurrent = pCurrent->pNextNode;
    }

    return fSum;
}

CMyLinkedPolynomial CMyLinkedPolynomial::Add_SLP(const CMyLinkedPolynomial& Poly)
{
    CMyLinkedPolynomial NewPoly = {};

    auto pCurrent1 = m_List.Get_FristNode();
    auto pCurrent2 = Poly.m_List.Get_FristNode();

    while (nullptr != pCurrent1 && nullptr != pCurrent2)
    {
        
        if (pCurrent1->item.iExp == pCurrent2->item.iExp)
        {
            NewPoly.NewTerm_SLP(pCurrent1->item.fCoef + pCurrent2->item.fCoef,pCurrent1->item.iExp);
            pCurrent1 = pCurrent1->pNextNode;
            pCurrent2 = pCurrent2->pNextNode;
        }
        else if (pCurrent1->item.iExp > pCurrent2->item.iExp)
        {
            NewPoly.NewTerm_SLP(pCurrent1->item.fCoef,pCurrent1->item.iExp);
            pCurrent1 = pCurrent1->pNextNode;
        }
        else if (pCurrent2->item.iExp > pCurrent1->item.iExp)
        {
            NewPoly.NewTerm_SLP(pCurrent2->item.fCoef, pCurrent2->item.iExp);
            pCurrent2 = pCurrent2->pNextNode;
        }
    }

    return NewPoly;
}
