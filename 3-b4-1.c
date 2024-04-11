/*2353126 信03 崔露文*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define pi 3.14159
int main()
{
	int a, b, c;
	printf("请输入三角形的两边及其夹角（角度）\n");
	scanf("%d %d %d", &a, &b, &c);
	printf("三角形面积为 : %.3f",(float)(0.5 * a * b * sin(c * pi / 180)));
	return 0;
}
