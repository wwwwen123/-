/*2353126 ��03 ��¶��*/
#include <iostream>
#include <cmath>
using namespace std;
void sub2(double a, double b, double c)
{
	double x1, x2;
	//ȷ�����˳��Ϊx1>x2
	if (a > 0)
	{
		x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	}
	if (a < 0)
	{
		x1 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		x2 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	}

	cout << "����������ʵ����" << endl;
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
}