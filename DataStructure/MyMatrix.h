#pragma once

class MyMatrix
{
public:
	MyMatrix();
	MyMatrix(int _iNumRow, int _iNumCol);
	MyMatrix(const MyMatrix& _Mat);
	~MyMatrix();

public:
	void		Set_Value(int _iRow, int _iCol, float _fValue);
	float		Get_Value(int _iRow, int _iCol) const;

public:
	MyMatrix	Add(const MyMatrix& _Mat); // 추가
	MyMatrix	Transpose(); // 전치

	void		Print();


private:
	float*		m_pMatrix = { nullptr };
	int			m_iNumRows = { 0 };
	int			m_iNumCols = { 0 };

};

