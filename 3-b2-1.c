/*2353126 ��03 ��¶��*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a;
	printf("������һ��[1..30000]�������:\n");
	scanf("%d", &a);
	printf("��λ : %d\n", a / 10000 % 10);
	printf("ǧλ : %d\n", a / 1000 % 10);
	printf("��λ : %d\n", a / 100 % 10);
	printf("ʮλ : %d\n", a / 10 % 10);
	printf("��λ : %d\n", a % 10);
	return 0;
}
