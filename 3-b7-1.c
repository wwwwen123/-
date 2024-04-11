/*2353126 信03 崔露文 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double a;
	printf("请输入找零值：\n");
	scanf("%lf", &a);
	printf("%.2f", a);

	int A = (int)(a / 50);//50元
	a -= 50 * A;

	int B = (int)(a / 20);//20元
	a -= 20 * B;

	int C = (int)(a / 10);//10元
	a -= 10 * C;

	int D = (int)(a / 5);//5元
	a -= 5 * D;

	int E = (int)(a);//1元
	a -= E;

	int b = (int)(a * 100 + 0.002);

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
	printf("共%d张找零，具体如下：\n", c);

	if (A > 0)
		printf("50元 : %d张\n", A);
	if (B > 0)
		printf("20元 : %d张\n", B);
	if (C > 0)
		printf("10元 : %d张\n", C);
	if (D > 0)
		printf("5元  : %d张\n", D);
	if (E > 0)
		printf("1元  : %d张\n", E);
	if (F > 0)
		printf("5角  : %d张\n", F);
	if (G > 0)
		printf("1角  : %d张\n", G);
	if (H > 0)
		printf("5分  : %d张\n", H);
	if (I > 0)
		printf("2分  : %d张\n", I);
	if (J > 0)
		printf("1分  : %d张\n", J);

	return 0;
}

