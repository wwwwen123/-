/*2353126 信03 崔露文*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	int x;
	int n = 1;
	double a,sum;//a为某一项的值，sum为最后要求的近似值
	sum = 1.0;

	cout << "请输入x的值[-10 ~ +65]" << endl;
	cin >> x;

	if (x < -10 || x > 65) {
		cout << "输入非法，请重新输入" << endl;
		cout << "请输入x的值[-10 ~ +65]" << endl;
		cin >> x;
	}

	a = x;
	while (fabs(a) >= 1e-6) 
	{
		sum += a;
		n++;
		a = a * x / n;
	}

	cout << "e^" << x << "=" << setprecision(10) << sum << endl;

    return 0;
}

