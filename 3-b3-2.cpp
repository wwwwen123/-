/*2353126 ��03 ��¶��*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double a;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> a;
	cout << setprecision(11) << endl;
	double b = a - static_cast<double>(static_cast<int>(a / 1000000000)) * 1000000000;
	double c = b - (static_cast<int>(a / 100000000)%10) * 100000000;
	double d = c - (static_cast<int>(a / 10000000)%10) * 10000000;
	double e = d - (static_cast<int>(a / 1000000)%10) * 1000000;
	double f = e - (static_cast<int>(a / 100000)%10) * 100000;
	double g = f - (static_cast<int>(a / 10000)%10) * 10000;
	double h = g - (static_cast<int>(a / 1000)%10) * 1000;
	double i = h - (static_cast<int>(a / 100)%10) * 100;
	double j = i - (static_cast<int>(a / 10)%10) * 10;
	cout << "ʮ��λ : " << static_cast<int>(a / 1000000000) % 10 << endl;
	cout << "��λ   : " << static_cast<int>(a / 100000000) % 10 << endl;
	cout << "ǧ��λ : " << static_cast<int>(a / 10000000) % 10 << endl;
	cout << "����λ : " << static_cast<int>(a / 1000000) % 10 << endl;
	cout << "ʮ��λ : " << static_cast<int>(a / 100000) % 10 << endl;
	cout << "��λ   : " << static_cast<int>(a / 10000) % 10 << endl;
	cout << "ǧλ   : " << static_cast<int>(a / 1000) % 10 << endl;
	cout << "��λ   : " << static_cast<int>(a / 100) % 10 << endl;
	cout << "ʮλ   : " << static_cast<int>(a / 10) % 10 << endl;
	cout << "Բ     : " << static_cast<int>(b) % 10 << endl;
	cout << "��     : " << static_cast<int>((j + 0.002) * 10) % 10 << endl;
	cout << "��     : " << static_cast<int>((j + 0.002) * 100) % 10 << endl;
	return 0;
}
