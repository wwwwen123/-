/*2353126 ��03 ��¶��*/
#include <iostream>
#include <cmath>
using namespace std;

void sub1()
{
	cout << "����һԪ���η���" << endl;
}

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

void sub3(double a, double b)
{
	double x = -b / (2 * a);
	cout << "���������ʵ����" << endl;
	cout << "x1=x2=" << x << endl;
}

void sub4(double a, double b, double c)
{
	double shibu = -b / (2 * a);
	cout << "�����������" << endl;
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