/*2353126 ��03 ��¶��*/
#include <iostream>
using namespace std;
int main()
{
	int a;
	cout << "������һ��[1..30000]�������:" << endl;
	cin >> a;
	cout << "��λ : " << a / 10000 % 10 << endl;
	cout << "ǧλ : " << a / 1000 % 10 << endl;
	cout << "��λ : " << a / 100 % 10 << endl;
	cout << "ʮλ : " << a / 10 % 10 << endl;
	cout << "��λ : " << a % 10 << endl;
	return 0;
}