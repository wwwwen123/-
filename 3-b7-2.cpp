/*2353126 信03 崔露文 */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double a;
	cout << "请输入找零值：" << endl;
	cin >> a;

	cout << setiosflags(ios::fixed) << setprecision(2);

	int A = static_cast<int>(a / 50);//50元
	a -= 50 * A;

	int B = static_cast<int>(a / 20);//20元
	a -= 20 * B;

	int C = static_cast<int>(a / 10);//10元
	a -= 10 * C;

	int D = static_cast<int>(a / 5);//5元
	a -= 5 * D;

	int E = static_cast<int>(a);//1元
	a -= E;

	int b = static_cast<int>(a * 100+0.002);

	int F = b / 50;//5角
	b -= 50 * F;

	int G = b / 10;//1角
	b -= 10 * G;

	int H = b / 5;//5分
	b -= 5 * H;

	int I = b / 2;//2分
	b -= 2 * I;

	int J = b;//1分
	b -= J;

	int c = A + B + C + D + E + F + G + H + I + J;
	cout << "共" << c << "张找零，具体如下：" << endl;

	if (A > 0) 
		cout << "50元 : " << A << "张" << endl;
	if (B > 0)
		cout << "20元 : " << B << "张" << endl;
	if (C > 0)
		cout << "10元 : " << C << "张" << endl;
	if (D > 0)
		cout << "5元  : " << D << "张" << endl;
	if (E > 0)
		cout << "1元  : " << E << "张" << endl;
	if (F > 0)
		cout << "5角  : " << F << "张" << endl;
	if (G > 0)
		cout << "1角  : " << G << "张" << endl;
	if (H > 0)
		cout << "5分  : " << H << "张" << endl;
	if (I > 0)
		cout << "2分  : " << I << "张" << endl;
	if (J > 0)
		cout << "1分  : " << J << "张" << endl;

	return 0;

}