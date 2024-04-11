/*2353126 信03 崔露文*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a, b, c;//年月日

	while (1) {
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> a >> b;
		if (cin.fail()) {
			cout << "输入非法，请重新输入" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else if (a < 2000 || a>2030 || b < 1 || b>12) {
			cout << "输入非法，请重新输入" << endl;
			/*continue;*/
		}
		else
			break;
	}

	while (1) {
		cout << "请输入" << a << "年" << b << "月1日的星期(0-6表示星期日-星期六) : ";
		cin >> c;
		if (a >= 2000 && a <= 2030 && b >= 1 && b <= 12) {
			if (c >= 0 && c <= 6)
				break;
			if (c < 0 || c>6) {
				cout << "输入非法，请重新输入" << endl;
				continue;
			}
			if (cin.fail()) {
				cout << "输入非法，请重新输入" << endl;
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

		cout << endl << a << "年" << b << "月的月历为:" << endl;
		cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
		//打印空格
		for (int x = 0; x < c; x++) {
			cout << setw(8) << " ";
		}
		//打印日期
		for (int y = 1; y <= day; y++) {
			cout << setw(4) << y << "    ";
			if ((y + c) % 7 == 0)
				cout << endl;
		}
		cout << endl;
	
	return 0;
	
}

