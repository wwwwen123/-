/*2353126 信03 崔露文*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int zeller(int a, int b, int c)
{
	if (b == 1) {
		b = 13;
		a = a - 1;
	}
	if (b == 2) {
		b = 14;
		a = a - 1;
	}
	//C（大写）=世纪-1
	int C = a / 100;
	//y=4位年份后两位
	int y = a - C * 100;
	int m = b;
	int d = c;
	int w = y + y / 4 + C / 4 - 2 * C + 13 * (m + 1) / 5 + d - 1;

	for (; w < 0; w > 0 || w == 0) {
		w = w + 7;
	}
	int xingqi = w % 7;
	return xingqi;
}

int main() {
	int ret, a, b, c;//年月日

	while (1) {
		printf("请输入年[1900-2100]、月、日：\n");
		ret = scanf("%d %d %d", &a, &b, &c);
		if (ret!=3) {
			printf("输入错误，请重新输入\n");
			while (getchar() != '\n');
			continue;
		}
		else {
			if (a < 1900 || a>2100) {
				printf("年份不正确，请重新输入\n");
				while (getchar() != '\n');
				continue;
			}
			if (b < 1 || b>12) {
				printf("月份不正确，请重新输入\n");
				while (getchar() != '\n');
				continue;
			}
			else if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) {
				if (c < 1 || c>31) {
					printf("日不正确，请重新输入\n");
					while (getchar() != '\n');
					continue;
				}
				else
					break;
			}
			else if (b == 4 || b == 6 || b == 9 || b == 11) {
				if (c < 1 || c>30) {
					printf("日不正确，请重新输入\n");
					while (getchar() != '\n');
					continue;
				}
				else
					break;
			}
			else if (b == 2) {
				if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {
					if (c < 1 || c>29) {
						printf("日不正确，请重新输入\n");
						while (getchar() != '\n');
						continue;
					}
					else
						break;
				}
				else
				{
					if (c < 1 || c>28) {
						printf("日不正确，请重新输入\n");
						while (getchar() != '\n');
						continue;
					}
					else
						break;
				}

			}
		}

	}
	int xingqi = zeller(a, b, c);

	switch (xingqi) {
		case 0:
			printf("星期日\n");
			break;
		case 1:
			printf("星期一\n");
			break;
		case 2:
			printf("星期二\n");
			break;
		case 3:
			printf("星期三\n");
			break;
		case 4:
			printf("星期四\n");
			break;
		case 5:
			printf("星期五\n");
			break;
		case 6:
			printf("星期六\n");
			break;
	}
	return 0;
}

