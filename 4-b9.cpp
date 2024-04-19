/*2353126 ��03 ��¶��*/
#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

/***************************************************************************
  �������ƣ�fibonacci
  ��    �ܣ�����fibonacci���еĵ�n���ֵ
  ���������
  �� �� ֵ��
  ˵    �����������κ���ʽ��ѭ������
***************************************************************************/
int fibonacci(int n)
{
	return (n > 2) ? fibonacci(n - 1) + fibonacci(n - 2) : 1;
	/* ��Ҫ����ɱ����� */
}

/***************************************************************************
  �������ƣ�main
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����������޸�
***************************************************************************/
int main()
{
	int n, f;
	cout << "������Fibonacci���е�����[1-46]" << endl;
	cin >> n;

	LARGE_INTEGER tick, begin, end;
	QueryPerformanceFrequency(&tick);	//���ʱ��Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ����ʱ������
	f = fibonacci(n);
	cout << "Fibonacci���е�" << n << "���ֵ : " << f << endl;

	QueryPerformanceCounter(&end);//�����ֹӲ����ʱ������
	cout << "������Ƶ�� : " << tick.QuadPart << "Hz" << endl;
	cout << "���������� : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;

	return 0;
}

