/*2353126 ��03 ��¶��*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	int x;
	int n = 1;
	double a,sum;//aΪĳһ���ֵ��sumΪ���Ҫ��Ľ���ֵ
	sum = 1.0;

	cout << "������x��ֵ[-10 ~ +65]" << endl;
	cin >> x;

	if (x < -10 || x > 65) {
		cout << "����Ƿ�������������" << endl;
		cout << "������x��ֵ[-10 ~ +65]" << endl;
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

