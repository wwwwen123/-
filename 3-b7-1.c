/*2353126 ��03 ��¶�� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double a;
	printf("����������ֵ��\n");
	scanf("%lf", &a);
	printf("%.2f", a);

	int A = (int)(a / 50);//50Ԫ
	a -= 50 * A;

	int B = (int)(a / 20);//20Ԫ
	a -= 20 * B;

	int C = (int)(a / 10);//10Ԫ
	a -= 10 * C;

	int D = (int)(a / 5);//5Ԫ
	a -= 5 * D;

	int E = (int)(a);//1Ԫ
	a -= E;

	int b = (int)(a * 100 + 0.002);

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
	printf("��%d�����㣬�������£�\n", c);

	if (A > 0)
		printf("50Ԫ : %d��\n", A);
	if (B > 0)
		printf("20Ԫ : %d��\n", B);
	if (C > 0)
		printf("10Ԫ : %d��\n", C);
	if (D > 0)
		printf("5Ԫ  : %d��\n", D);
	if (E > 0)
		printf("1Ԫ  : %d��\n", E);
	if (F > 0)
		printf("5��  : %d��\n", F);
	if (G > 0)
		printf("1��  : %d��\n", G);
	if (H > 0)
		printf("5��  : %d��\n", H);
	if (I > 0)
		printf("2��  : %d��\n", I);
	if (J > 0)
		printf("1��  : %d��\n", J);

	return 0;
}

