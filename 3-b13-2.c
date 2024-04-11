/*2353126 信03 崔露文*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int ret, a, b, c;//年月日

	while (1) {
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		ret = scanf("%d %d",&a,&b);
		if (ret!=2) {
			printf("输入非法，请重新输入\n");
			while (getchar() != '\n');
			continue;
		}
		else if (a < 2000 || a>2030 || b < 1 || b>12) {
			printf("输入非法，请重新输入\n");
		}
		else
			break;
	}

	while (1) {
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ", a, b);
		int ret2 = scanf("%d", &c);
		if (a >= 2000 && a <= 2030 && b >= 1 && b <= 12) {
			if (c >= 0 && c <= 6)
				break;
			if (c < 0 || c>6) {
				printf("输入非法，请重新输入\n");
				continue;
			}
			if (ret2!=1) {
				printf("输入非法，请重新输入\n");
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

	printf("%d年%d月的月历为:\n" ,a,b);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	//打印空格
	for (int x = 0; x < c; x++) {
		printf("%8s", " ");
	}
	//打印日期
	for (int y = 1; y <= day; y++) {
		printf("%4d    ", y);
		if ((y + c) % 7 == 0)
			printf("\n");
	}
	printf("\n");

	return 0;

}
