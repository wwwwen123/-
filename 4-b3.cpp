/*2353126 信03 崔露文*/
#include <iostream>
#include<iomanip>
using namespace std;

int zeller(int a, int b, int c)//年、月、日
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
	int w = y + y / 4 + C / 4 - 2 * C + 13 * (m + 1) / 5 ;

	for (; w < 0; w > 0 || w == 0) {
		w = w + 7;
	}
	int xingqi = w % 7;
	return xingqi;
}

void calender(int day,int c,int a, int b)
{
	/* 按需添加代码 */
	cout << endl;

	cout << a << "年" << b << "月" << endl;
	/* 头部分隔线，不算打表 */
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
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
	//打印空格
	for (int x = 0; x < c; x++) {
		cout << setw(8) << " ";
	}
	//打印日期
	for (int y = 1; y <= day; y++) {
		cout << setw(4) << y << "    ";
		if ((y + c) % 7 == 0) {
				cout << endl;
		}
	}

	
	cout << endl;

	/* 尾部分隔线，不算打表 */
	cout << "======================================================" << endl;
}

int main() {
	int a, b;//年月

	while (1) {
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> a >> b;
		if (cin.fail()) {
			cout << "输入错误，请重新输入" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else {
			if (a < 1900 || a>2100) {
				cout << "年份不正确，请重新输入" << endl;
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			/*else
				break;*/
			if (b < 1 || b > 12) {
				cout << "月份不正确，请重新输入" << endl;
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

