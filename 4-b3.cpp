/*2353126 ��03 ��¶��*/
#include <iostream>
#include<iomanip>
using namespace std;

int zeller(int a, int b, int c)//�ꡢ�¡���
{
	if (b == 1) {
		b = 13;
		a = a - 1;
	}
	if (b == 2) {
		b = 14;
		a = a - 1;
	}
	//C����д��=����-1
	int C = a / 100;
	//y=4λ��ݺ���λ
	int y = a - C * 100;
	int m = b;
	int d = c;
	int w = y + y / 4 + C / 4 - 2 * C + 13 * (m + 1) / 5 ;

	for (; w < 0; w > 0 || w == 0) {
		w = w + 7;
	}
	int xingqi = w % 7;
	return xingqi;
}

void calender(int day,int c,int a, int b)
{
	/* ������Ӵ��� */
	cout << endl;

	cout << a << "��" << b << "��" << endl;
	/* ͷ���ָ��ߣ������� */
	cout << "======================================================" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	cout << "======================================================" << endl;

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
	//��ӡ�ո�
	for (int x = 0; x < c; x++) {
		cout << setw(8) << " ";
	}
	//��ӡ����
	for (int y = 1; y <= day; y++) {
		cout << setw(4) << y << "    ";
		if ((y + c) % 7 == 0) {
				cout << endl;
		}
	}

	
	cout << endl;

	/* β���ָ��ߣ������� */
	cout << "======================================================" << endl;
}

int main() {
	int a, b;//����

	while (1) {
		cout << "��������[1900-2100]����" << endl;
		cin >> a >> b;
		if (cin.fail()) {
			cout << "�����������������" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else {
			if (a < 1900 || a>2100) {
				cout << "��ݲ���ȷ������������" << endl;
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			/*else
				break;*/
			if (b < 1 || b > 12) {
				cout << "�·ݲ���ȷ������������" << endl;
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			else
				break;
		}
		
	}
	int c = zeller(a, b, 0);
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
	calender(day,c, a, b);
	return 0;

	cout << endl;
}

