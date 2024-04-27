/*2353126 信03 崔露文*/
#include <iostream>
#include <cmath>
using namespace std;
double a, b, c;
int main()
{
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a >> b >> c;

	void sub1();
	void sub2();
	void sub3();
	void sub4();

	if (fabs(a) < 1e-6)
		a = 0;

	if (a == 0)
		sub1();
	else
	{
		if (b * b - 4 * a * c > 1e-6)
			sub2();
		else if (fabs(b * b - 4 * a * c) < 1e-6)
			sub3();
		else
			sub4();
	}
	return 0;
}