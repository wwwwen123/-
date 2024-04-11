/*2353126 信03 崔露文*/
#include <stdio.h>
#include <windows.h> //取系统时间

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int total = 0;
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (j == i)
				continue;
			for (int k = 1; k < 10; k++) {
				if (k == j || k == i)
					continue;
				int a = i * 100 + j * 10 + k;
				//第一个数ijk

				for (int m = 1; m < 10; m++) {
					if (m == k || m == j || m == i)
						continue;
					for (int n = 1; n < 10; n++) {
						if (n == m || n == k || m == j || m == i)
							continue;
						for (int o = 1; o < 10; o++) {
							if (o == n || o == m || o == k || o == j || o == i)
								continue;
							int b = m * 100 + n * 10 + o;
							//第二个数mno

							for (int p = 1; p < 10; p++) {
								if (p == o || p == n || p == m
									|| p == k || p == j || p == i)
									continue;
								for (int q = 1; q < 10; q++) {
									if (q == p || q == o || q == n
										|| q == m || q == k || q == j || q == i)
										continue;
									for (int r = 1; r < 10; r++) {
										if (r == q || r == p || r == o || r == n
											|| r == m || r == k || r == j || r == i)
											continue;
										int c = p * 100 + q * 10 + r;
										//第三个数pqr

										if (a + b + c == 1953 && a < b && b < c) {
											total++;
											printf("No.%3d : %d+%d+%d=1953\n", total, a, b, c);
										}
									}
								}
							}

						}
					}
				}

			}
		}
	}

	printf("total=%d\n", total);

	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n", tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}