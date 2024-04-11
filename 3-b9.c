/*2353126 信03 崔露文*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int m, n;//m为行，n为列
	for (m = 1; m <= 9; m++)
	{
		for (n = 1; n <= m; n++) 
		{
			int a = m * n;
			printf("%dx%d=%d%s", n, m, a, (a<10?"   ":"  "));
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}
