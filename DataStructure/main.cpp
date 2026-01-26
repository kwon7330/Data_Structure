#include <iostream>
#include "MyMatrix.h"

using namespace std;

int main()
{
	MyMatrix Mat(3,2);

	Mat.Set_Value(0,0,1);
	Mat.Set_Value(1,1,1);
	Mat.Set_Value(0,2,1);

	cout << Mat.Get_Value(0, 1) << endl;

	Mat.Print();

	MyMatrix Mat2(Mat.Transpose());

	Mat2.Print();

	return 0;
}