/*2353126 ��03 ��¶��*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int m, n;//mΪ�У�nΪ��
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
