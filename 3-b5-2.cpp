/*2353126 信03 崔露文*/
#include <iostream>
using namespace std;
int main()
{
	cout << "请输入年，月，日" << endl;
	int a, b, c;
	cin >> a >> b >> c;
    if (b < 1 || b > 12)
    {
        cout << "输入错误-月份不正确" << endl;
        return 0;
    }    
    if (c < 1 || c > 31)
    {
        cout << "输入错误-日与月的关系非法" << endl;
        return 0;
    }
    if (((a%4!=0)||(a%100==0)&&(a%400!=0))&&c>28)
    {
        cout << "输入错误-日与月的关系非法" << endl;
        return 0;
    }
    if (((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0))&&c>29)
    {
        cout << "输入错误-日与月的关系非法" << endl;
        return 0;
    }
    bool yeah;
    if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0))
        yeah = true;
    else
        yeah = false;    
    int e = 0;
    switch (b) {       
        case 1:
            e = c;
            break;
        case 2:
            e = c + 31;
            break;
        case 3:
            e = c + 31 + 28 + yeah;
            break;
        case 4:
            e = c + 31 + 28 + yeah + 31;
            break;
        case 5:
            e = c + 31 + 28 + yeah + 31 + 30;
            break;
        case 6:
            e = c + 31 + 28 + yeah + 31 + 30 + 31;
            break;
        case 7:
            e = c + 31 + 28 + yeah + 31 + 30 + 31 + 30;
            break;
        case 8:
            e = c + 31 + 28 + yeah + 31 + 30 + 31 + 30 + 31;
            break;
        case 9:
            e = c + 31 + 28 + yeah + 31 + 30 + 31 + 30 + 31 + 31;
            break;
        case 10:
            e = c + 31 + 28 + yeah + 31 + 30 + 31 + 30 + 31 + 31 + 30;
            break;
        case 11:
            e = c + 31 + 28 + yeah + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
            break;
        case 12:
            e = c + 31 + 28 + yeah + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
            break;
    }
        cout << a << '-' << b << '-' << c << "是" << a << "年的第" << e << "天" << endl;
    
    return 0;
}


