#pragma once

class CMyString
{
public:
	CMyString();
	CMyString(const char* Init);
	CMyString(const CMyString& str);
	~CMyString();

public:
	bool		isEmpty();
	bool		isEqual(const CMyString& _str);
	int			Length();
	int			Find(CMyString Pat);
	void		Resize(int _iNewSize);
	void		Print();

	CMyString	Substr(int _iStart, int _iNum);		//인덱스 Start위치의 글자부터 Num개의 글자로 새로운 문자열 만들기
	CMyString	Concat(CMyString App_Str);		// 뒤에 덧붙인 새로운 문자열 반환
	CMyString	Insert(CMyString _t, int _iStart);	// 중간에 삽입

private:
	char*		m_szStr = { nullptr };
	int			m_iSize = { 0 };

};

