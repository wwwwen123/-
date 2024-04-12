/*2353126 信03 崔露文*/
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
	//C（大写）=世纪-1
	int C = a / 100;
	//y=4位年份后两位
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
	int a, b, c;//年月日

	while (1) {
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> a >> b >> c;
		if (cin.fail()) {
			cout << "输入错误，请重新输入" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		if (cin.good()) {
			if (a < 1900 || a>2100) {
				cout << "年份不正确，请重新输入" << endl;
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			if (b < 1 || b>12) {
				cout << "月份不正确，请重新输入" << endl;
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			else if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) {
				if (c < 1 || c>31) {
					cout << "日不正确，请重新输入" << endl;
					cin.clear();
					cin.ignore(65536, '\n');
					continue;
				}
				else
					break;
			}
			else if (b == 4 || b == 6 || b == 9 || b == 11) {
				if (c < 1 || c>30) {
					cout << "日不正确，请重新输入" << endl;
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
						cout << "日不正确，请重新输入" << endl;
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
						cout << "日不正确，请重新输入" << endl;
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
			cout << "星期日" << endl;
			break;
		case 1:
			cout << "星期一" << endl;
			break;
		case 2:
			cout << "星期二" << endl;
			break;
		case 3:
			cout << "星期三" << endl;
			break;
		case 4:
			cout << "星期四" << endl;
			break;
		case 5:
			cout << "星期五" << endl;
			break;
		case 6:
			cout << "星期六" << endl;
			break;
	}
	return 0;
}

