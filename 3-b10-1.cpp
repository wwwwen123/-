/*2353126 ��03 ��¶��*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //ȡϵͳʱ��
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������

	/* �˴�����ĳ���ʼ */
	int total = 0;
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (j == i)
				continue;
			for (int k = 1; k < 10; k++) {
				if (k == j || k == i)
					continue;
				int a = i * 100 + j * 10 + k;
				//��һ����ijk

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
							//�ڶ�����mno

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
										//��������pqr

										if (a + b + c == 1953 && a < b && b < c) {
											total++;
											cout << "No." << setw(3) << setiosflags(ios::right) 
												 << total << " : " << a << "+" << b << "+" << c << "=1953" << endl;
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

	cout << "total=" << total << endl;
	
	/* �˴�����ĳ������ */

	QueryPerformanceCounter(&end);		//�����ֹӲ������������

	cout << "������Ƶ�� : " << tick.QuadPart << "Hz" << endl;
	cout << "���������� : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;

	return 0;
}