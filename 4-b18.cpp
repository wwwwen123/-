/*2353126 信03 崔露文*/
#include <iostream>
using namespace std;
int max(int a, int b) 
{
	return (a > b ? a : b);
}

int max(int a, int b, int c) 
{
	int m = (a > b ? a : b);
	return (m > c ? m : c);
}

int max(int a, int b, int c, int d) 
{
	int m = (a > b ? a : b);
	int n = (m > c ? m : c);
	return (n > d ? n : d);
}

int main()
{
	int num, a, b, c, d;
	while (1) 
	{
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> num;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		if (num < 2 || num > 4) 
		{
			cout << "个数输入错误" << endl;
			break;
		}
		if (num == 2) 
		{
			cin >> a >> b;
			if (cin.fail() || a <= 0 || b <= 0) {
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			cout << "max=" << max(a, b) << endl;
			break;
		}//num==2
		if (num == 3) 
		{
			cin >> a >> b >> c;
			if (cin.fail() || a <= 0 || b <= 0 || c <= 0) {
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			cout << "max=" << max(a, b, c) << endl;
			break;
		}//num==3
		if (num == 4) 
		{
			cin >> a >> b >> c >> d;
			if (cin.fail() || a <= 0 || b <= 0 || c <= 0 || d <= 0) {
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			cout << "max=" << max(a, b, c, d) << endl;
			break;
		}
	}//while(1)
	return 0;

}