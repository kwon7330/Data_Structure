#pragma once
class MyArray2D
{
public:
	MyArray2D();
	MyArray2D(int _iNumRows, int _iNumCols);
	MyArray2D(const MyArray2D& _Arr2D);
	~MyArray2D();

public:
	float		Get_Value(int _iRow, int _iCol) const;
	void		Set_Value(int _iRow, int _iCol, float _fValue);
	
	void		Print();

	MyArray2D	Add(const MyArray2D& _Mat);
	MyArray2D	Transpose();


private:
	float**		m_ppArr = { nullptr };
	int			m_iNumRows = {};
	int			m_iNumCols = {};

};

