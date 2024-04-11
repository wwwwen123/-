/*2353126 信03 崔露文*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	const double pi = 3.14159;
	int a, b, c;
	cout << "请输入三角形的两边及其夹角（角度）" << endl;
	cin >> a >> b >> c;
	cout << setiosflags(ios::fixed) << setprecision(3);
	cout << "三角形面积为 : " << static_cast<float>(0.5 * a * b * sin(c * pi / 180)) << endl;
	return 0;
}