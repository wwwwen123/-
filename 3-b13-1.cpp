/*2353126 ��03 ��¶��*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a, b, c;//������

	while (1) {
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> a >> b;
		if (cin.fail()) {
			cout << "����Ƿ�������������" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else if (a < 2000 || a>2030 || b < 1 || b>12) {
			cout << "����Ƿ�������������" << endl;
			/*continue;*/
		}
		else
			break;
	}

	while (1) {
		cout << "������" << a << "��" << b << "��1�յ�����(0-6��ʾ������-������) : ";
		cin >> c;
		if (a >= 2000 && a <= 2030 && b >= 1 && b <= 12) {
			if (c >= 0 && c <= 6)
				break;
			if (c < 0 || c>6) {
				cout << "����Ƿ�������������" << endl;
				continue;
			}
			if (cin.fail()) {
				cout << "����Ƿ�������������" << endl;
				cin.clear();
				cin.ignore(65536, '\n');
				/*continue;*/
			}
		}
	}
		

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

		cout << endl << a << "��" << b << "�µ�����Ϊ:" << endl;
		cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
		//��ӡ�ո�
		for (int x = 0; x < c; x++) {
			cout << setw(8) << " ";
		}
		//��ӡ����
		for (int y = 1; y <= day; y++) {
			cout << setw(4) << y << "    ";
			if ((y + c) % 7 == 0)
				cout << endl;
		}
		cout << endl;
	
	return 0;
	
}

