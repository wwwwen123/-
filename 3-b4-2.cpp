/*2353126 ��03 ��¶��*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	const double pi = 3.14159;
	int a, b, c;
	cout << "�����������ε����߼���нǣ��Ƕȣ�" << endl;
	cin >> a >> b >> c;
	cout << setiosflags(ios::fixed) << setprecision(3);
	cout << "���������Ϊ : " << static_cast<float>(0.5 * a * b * sin(c * pi / 180)) << endl;
	return 0;
}