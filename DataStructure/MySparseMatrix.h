#pragma once
typedef struct tagTerm
{
	int		iRow = 0;
	int		iCol = 0;
	float	fValue = 0.f;

}TERM;


class MySparseMatrix
{
public:
	MySparseMatrix();
	MySparseMatrix(int _iNumRows, int _iNumCols, int _iCapacity);
	MySparseMatrix(const MySparseMatrix& _Mat);
	~MySparseMatrix();

public:
	float				Get_Value(int _iRow, int _iCol) const;
	void				Set_Value(int _iRow, int _iCol, int iValue);

public:
	void				Print();
	void				Print_Term();
	MySparseMatrix		Transpose();

private:
	TERM*				m_pTerms = { nullptr };
	int					m_iNumRows = {};
	int					m_iNumCols = {};
	int					m_iCapacity = {};
	int					m_iNumTerms = {};

};

