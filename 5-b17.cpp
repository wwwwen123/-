/*2353126 信03 崔露文*/
#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?"; //共 15 个英文符号


//用来生成在指定ASCII范围内的随机字符的函数
char generate_char(int minAscii, int maxAscii)
{
	return static_cast<char>(minAscii + rand() % (maxAscii - minAscii + 1));
	//用rand()取随机整数后取模，使其落在0~(maxAscii - minAscii)
	//然后加上minAscii，使随机数落在minAscii~maxAscii
}


//用来生成密码的函数
void generate_password(int len, int daxie, int xiaoxie, int shuzi, int qita)
{	
	char password[17];//密码最长为16位，留1位给尾0
	int num = 0;
	//添加大写
	for (int i = 0; i < daxie; i++, num++)
	{
		password[num] = generate_char('A', 'Z');
	}
	//添加小写
	for (int i = 0; i < xiaoxie; i++, num++)
	{
		password[num] = generate_char('a', 'z');
	}
	//添加数字
	for (int i = 0; i < shuzi; i++, num++)
	{
		password[num] = generate_char('0', '9');
	}
	//添加其它字符
	for (int i = 0; i < qita; i++, num++) {
		password[num] = other[rand() % (sizeof(other) - 1)];
	}
	//如果总数没达到len，则随机添加以上四类以达到指定长度
	while (num < len)
	{
		int type = rand() % 4;
		switch (type)
		{
			case 0://加大写字母
				password[num++] = generate_char('A', 'Z');
				break;
			case 1://加小写字母
				password[num++] = generate_char('a', 'z');
				break;
			case 2://加数字
				password[num++] = generate_char('0', '9');
				break;
			case 3://加其它字符
				password[num++] = other[rand() % (sizeof(other) - 1)];
				break;
		}
	}

	//打乱数组中元素顺序
	//如果没有这一步，那么每个密码都是大写字母-小写字母-数字-其它字符这样的固定顺序
	for (int i = 0; i < len; i++) 
	{
		int suiji = rand() % len;//选择数组中的随机位置
		char tmp = password[i];
		password[i] = password[suiji];
		password[suiji] = tmp;
	}

	password[num] = '\0';//最后结束要有尾0

	cout << password << endl;
}


int main()
{
	int len = 0, daxie = 0, xiaoxie = 0, shuzi = 0, qita = 0;
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	cin >> len >> daxie >> xiaoxie >> shuzi >> qita;

	//输入错误处理
	if (cin.fail())
	{
		cout << "输入非法" << endl;
		return 0;
	}
	if (len < 12 || len>16)
	{
		cout << "密码长度[" << len << "]不正确" << endl;
		return 0;
	}
	if (daxie < 2)
	{
		cout << "大写字母个数[" << daxie << "]不正确" << endl;
		return 0;
	}
	if (xiaoxie < 2)
	{
		cout << "小写字母个数[" << xiaoxie << "]不正确" << endl;
		return 0;
	}
	if (shuzi < 2)
	{
		cout << "数字个数[" << shuzi << "]不正确" << endl;
		return 0;
	}
	if (qita < 2)
	{
		cout << "其它符号个数[" << qita << "]不正确" << endl;
		return 0;
	}
	if (daxie + xiaoxie + shuzi + qita > len)
	{
		cout << "所有字符类型之和[" << daxie << "+" << xiaoxie << "+" << shuzi << "+" << qita << "]大于总密码长度[" << len << "]" << endl;
		return 0;
	}

	//输出输入内容
	cout << len << " " << daxie << " " << xiaoxie << " " << shuzi << " " << qita << endl;

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; i++)//生成10组密码
	{
		generate_password(len, daxie, xiaoxie, shuzi, qita);
	}

	return 0;
}