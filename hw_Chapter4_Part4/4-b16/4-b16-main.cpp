/*2353126 ��03 ��¶��*/
#include <iostream>
#include <cmath>
#include "4-b16.h"
using namespace std;
int main()
{
	double a, b, c;
	cout << "������һԪ���η��̵�����ϵ��a,b,c:" << endl;
	cin >> a >> b >> c;

	void sub1();
	void sub2(double, double, double);
	void sub3(double, double);
	void sub4(double, double, double);

	if (fabs(a) < 1e-6)
		a = 0;

	if (a == 0)
		sub1();
	else
	{
		if (b * b - 4 * a * c > 1e-6)
			sub2(a, b, c);
		else if (fabs(b * b - 4 * a * c) < 1e-6)
			sub3(a, b);
		else
			sub4(a, b, c);
	}
	return 0;
}