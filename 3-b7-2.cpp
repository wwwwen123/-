/*2353126 ��03 ��¶�� */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double a;
	cout << "����������ֵ��" << endl;
	cin >> a;

	cout << setiosflags(ios::fixed) << setprecision(2);

	int A = static_cast<int>(a / 50);//50Ԫ
	a -= 50 * A;

	int B = static_cast<int>(a / 20);//20Ԫ
	a -= 20 * B;

	int C = static_cast<int>(a / 10);//10Ԫ
	a -= 10 * C;

	int D = static_cast<int>(a / 5);//5Ԫ
	a -= 5 * D;

	int E = static_cast<int>(a);//1Ԫ
	a -= E;

	int b = static_cast<int>(a * 100+0.002);

	int F = b / 50;//5��
	b -= 50 * F;

	int G = b / 10;//1��
	b -= 10 * G;

	int H = b / 5;//5��
	b -= 5 * H;

	int I = b / 2;//2��
	b -= 2 * I;

	int J = b;//1��
	b -= J;

	int c = A + B + C + D + E + F + G + H + I + J;
	cout << "��" << c << "�����㣬�������£�" << endl;

	if (A > 0) 
		cout << "50Ԫ : " << A << "��" << endl;
	if (B > 0)
		cout << "20Ԫ : " << B << "��" << endl;
	if (C > 0)
		cout << "10Ԫ : " << C << "��" << endl;
	if (D > 0)
		cout << "5Ԫ  : " << D << "��" << endl;
	if (E > 0)
		cout << "1Ԫ  : " << E << "��" << endl;
	if (F > 0)
		cout << "5��  : " << F << "��" << endl;
	if (G > 0)
		cout << "1��  : " << G << "��" << endl;
	if (H > 0)
		cout << "5��  : " << H << "��" << endl;
	if (I > 0)
		cout << "2��  : " << I << "��" << endl;
	if (J > 0)
		cout << "1��  : " << J << "��" << endl;

	return 0;

}