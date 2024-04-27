/*2353126 信03 崔露文*/
#include <iostream>
#include <cmath>
using namespace std;
void sub4(double a, double b, double c)
{
	double shibu = -b / (2 * a);
	cout << "有两个虚根：" << endl;
	if (fabs(sqrt(4 * a * c - b * b) / (2 * a)) == 1)
	{
		if (shibu == 0)
		{
			cout << "x1=" << "i" << endl;
			cout << "x2=" << "-i" << endl;
		}
		else
		{
			cout << "x1=" << shibu << "+" << "i" << endl;
			cout << "x2=" << shibu << "-" << "i" << endl;
		}
	}
	else if (shibu == 0)
	{
		cout << "x1=" << fabs(sqrt(-b * b + 4 * a * c) / (2 * a)) << "i" << endl;
		cout << "x2=" << "-" << fabs(sqrt(-b * b + 4 * a * c) / (2 * a)) << "i" << endl;
	}
	else
	{
		cout << "x1=" << shibu << "+" << fabs(sqrt(-b * b + 4 * a * c) / (2 * a)) << "i" << endl;
		cout << "x2=" << shibu << "-" << fabs(sqrt(-b * b + 4 * a * c) / (2 * a)) << "i" << endl;
	}
}