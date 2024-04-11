/*2353126 信03 崔露文*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double a;
	cout << "请输入[0-100亿)之间的数字:" << endl;
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
	cout << "十亿位 : " << static_cast<int>(a / 1000000000) % 10 << endl;
	cout << "亿位   : " << static_cast<int>(a / 100000000) % 10 << endl;
	cout << "千万位 : " << static_cast<int>(a / 10000000) % 10 << endl;
	cout << "百万位 : " << static_cast<int>(a / 1000000) % 10 << endl;
	cout << "十万位 : " << static_cast<int>(a / 100000) % 10 << endl;
	cout << "万位   : " << static_cast<int>(a / 10000) % 10 << endl;
	cout << "千位   : " << static_cast<int>(a / 1000) % 10 << endl;
	cout << "百位   : " << static_cast<int>(a / 100) % 10 << endl;
	cout << "十位   : " << static_cast<int>(a / 10) % 10 << endl;
	cout << "圆     : " << static_cast<int>(b) % 10 << endl;
	cout << "角     : " << static_cast<int>((j + 0.002) * 10) % 10 << endl;
	cout << "分     : " << static_cast<int>((j + 0.002) * 100) % 10 << endl;
	return 0;
}
