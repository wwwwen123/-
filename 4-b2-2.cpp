/*2353126 ��03 ��¶��*/
#include <iostream>
using namespace std;

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
	//C����д��=����-1
	int C = a / 100;
	//y=4λ��ݺ���λ
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
	int a, b, c;//������

	while (1) {
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> a >> b >> c;
		if (cin.fail()) {
			cout << "�����������������" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		if (cin.good()) {
			if (a < 1900 || a>2100) {
				cout << "��ݲ���ȷ������������" << endl;
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			if (b < 1 || b>12) {
				cout << "�·ݲ���ȷ������������" << endl;
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			else if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) {
				if (c < 1 || c>31) {
					cout << "�ղ���ȷ������������" << endl;
					cin.clear();
					cin.ignore(65536, '\n');
					continue;
				}
				else
					break;
			}
			else if (b == 4 || b == 6 || b == 9 || b == 11) {
				if (c < 1 || c>30) {
					cout << "�ղ���ȷ������������" << endl;
					cin.clear();
					cin.ignore(65536, '\n');
					continue;
				}
				else
					break;
			}
			else if (b == 2) {
				if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {
					if (c < 1 || c>29) {
						cout << "�ղ���ȷ������������" << endl;
						cin.clear();
						cin.ignore(65536, '\n');
						continue;
					}
					else
						break;
				}
				else
				{
					if (c < 1 || c>28) {
						cout << "�ղ���ȷ������������" << endl;
						cin.clear();
						cin.ignore(65536, '\n');
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
			cout << "������" << endl;
			break;
		case 1:
			cout << "����һ" << endl;
			break;
		case 2:
			cout << "���ڶ�" << endl;
			break;
		case 3:
			cout << "������" << endl;
			break;
		case 4:
			cout << "������" << endl;
			break;
		case 5:
			cout << "������" << endl;
			break;
		case 6:
			cout << "������" << endl;
			break;
	}
	return 0;
}

