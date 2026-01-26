#include <iostream>
#include "MySparsePolynomial.h"
#include <algorithm>

using namespace std;

int main()
{
	CMySparsePolynomial P1;
	CMySparsePolynomial P2;

	P1.NewTerm(2,2);
	P1.NewTerm(1,1);
	P1.NewTerm(2,1);

	P1.Print();

	//cout << P1.Eval(1) << endl;

	P2.NewTerm(1,2);
	P2.NewTerm(1,1);

	P2.Print();

	P1.Add(P2);

	P1.Print();

	return 0;
}