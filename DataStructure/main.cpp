#include <iostream>
#include "MyArray2D.h"

using namespace std;

int main()
{
	MyArray2D Mat(3,2);

	Mat.Set_Value(0,0,1);
	Mat.Set_Value(1,1,1);
	Mat.Set_Value(2,1,1);

	cout << Mat.Get_Value(0, 1) << endl;

	Mat.Print();

	MyArray2D Mat2(Mat.Transpose());

	Mat2.Print();

	return 0;
}