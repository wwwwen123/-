/*2353126 ��03 ��¶��*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define pi 3.14159
int main()
{
	int a, b, c;
	printf("�����������ε����߼���нǣ��Ƕȣ�\n");
	scanf("%d %d %d", &a, &b, &c);
	printf("���������Ϊ : %.3f",(float)(0.5 * a * b * sin(c * pi / 180)));
	return 0;
}
