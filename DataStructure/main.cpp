#include "MyPolynomial.h"
#include <iostream>

using namespace std;

int main()
{
	MyPolynomial p1(2);
	MyPolynomial p2(2);

	//p1.NewTerm(3.f,2);
	p1.NewTerm(2.f, 1);
	p1.NewTerm(1.f, 0);

	p1.Print();

	//p2.NewTerm(2.f,2);
	p2.NewTerm(2.f,1);
	p2.NewTerm(1.f,0);

	p2.Print();

	MyPolynomial p3(p1.Mul(p2));
	
	p3.Print();
	cout << p3.Eval(1) << endl;





	return 0;
}