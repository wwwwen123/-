/*2353126 ��03 ��¶��*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int ret, a, b, c;//������

	while (1) {
		printf("���������(2000-2030)���·�(1-12) : ");
		ret = scanf("%d %d",&a,&b);
		if (ret!=2) {
			printf("����Ƿ�������������\n");
			while (getchar() != '\n');
			continue;
		}
		else if (a < 2000 || a>2030 || b < 1 || b>12) {
			printf("����Ƿ�������������\n");
		}
		else
			break;
	}

	while (1) {
		printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : ", a, b);
		int ret2 = scanf("%d", &c);
		if (a >= 2000 && a <= 2030 && b >= 1 && b <= 12) {
			if (c >= 0 && c <= 6)
				break;
			if (c < 0 || c>6) {
				printf("����Ƿ�������������\n");
				continue;
			}
			if (ret2!=1) {
				printf("����Ƿ�������������\n");
				while (getchar() != '\n');
			}
		}
	}
	printf("\n");

	int day = 0;
	if (b == 4 || b == 6 || b == 9 || b == 11)
		day = 30;
	else if (b == 2) {
		if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0))
			day = 29;
		else
			day = 28;
	}
	else
		day = 31;

	printf("%d��%d�µ�����Ϊ:\n" ,a,b);
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");
	//��ӡ�ո�
	for (int x = 0; x < c; x++) {
		printf("%8s", " ");
	}
	//��ӡ����
	for (int y = 1; y <= day; y++) {
		printf("%4d    ", y);
		if ((y + c) % 7 == 0)
			printf("\n");
	}
	printf("\n");

	return 0;

}
