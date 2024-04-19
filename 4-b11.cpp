/*2353126 信03 崔露文*/
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数（包括递归函数），但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
				 2、除print_tower之外的其他函数中不允许定义静态局部变量
   ----------------------------------------------------------------------------------- */

   /***************************************************************************
		函数名称：print_left
		功    能：打印最大字符到小字符
		说    明：例如print_left('D','A'),输出DCBA
	  ***************************************************************************/
void print_left(char start_ch, char end_ch)
{
	cout << start_ch;
	if (start_ch == end_ch)
	{
		return;
	}
	else
		print_left(start_ch - 1, end_ch);
}

/***************************************************************************
		函数名称：print_right
		功    能：打印小字符到大字符
		说    明：例print_right('B','D')，输出BCD
	  ***************************************************************************/
void print_right(char start_ch, char end_ch)
{
	cout << start_ch;
	if (end_ch == start_ch)
	{
		return;
	}
	else
		print_right(start_ch + 1, end_ch);
}


   /***************************************************************************
	 函数名称：print_tower
	 功    能：打印字母塔
	 输入参数：
	 返 回 值：
	 说    明：形参按需设置
			   提示：有一个参数order，指定正序/倒序
			   order为1：正三角；order为-1：倒三角

			   depth是因为倒三角实在想不出怎么打印空格才加的QAQ
   ***************************************************************************/
void print_tower(char start_ch, char end_ch, int order, int depth = 0)
{
	/* 按需实现，函数中不允许任何形式的循环，不允许定义静态局部变量 */
	if (order == 1)
	{
		cout << setw((end_ch - start_ch) + 1) << setfill(' ') << start_ch;
		if (start_ch != 'A')
		{
			print_left(start_ch - 1, 'A');
			print_right('B', start_ch);
		}
		cout << endl;
		if (start_ch != end_ch)
		{
			print_tower(start_ch + 1, end_ch, order, depth + 1);
		}
	}//order==1

	if (order == -1)
	{
		if (depth > 0) 
			cout << " ";
		cout << setw(depth) << setfill(' ') << start_ch;

		if (start_ch == 'A') {
			cout << endl;
			if (end_ch != 'A')
				print_tower(start_ch - 1, end_ch, order, depth + 1);
			else
				return;
		}
		
		if (start_ch != 'A')
		{
			print_left(start_ch - 1, 'A');
			print_right('B', start_ch);
			cout << endl;
			if (start_ch == end_ch)
				return;
			else
				print_tower(start_ch - 1, end_ch, order, depth + 1);
		}
		
	}//order==-1
}




/***************************************************************************
  函数名称：main
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效，为避免循环出现，不处理输入错误) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(中间为A) */
	cout << setw((end_ch - 'A') * 2 + 1) << setfill('=') << '=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔(" << end_ch << "->A)" << endl;
	cout << setw((end_ch - 'A') * 2 + 1) << setfill('=') << '=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower('A', end_ch, 1, 0); //正序打印 A~结束字符 
	cout << endl;

	/* 倒三角字母塔(中间为A) */
	cout << setw((end_ch - 'A') * 2 + 1) << setfill('=') << '=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔(" << end_ch << "->A)" << endl;
	cout << setw((end_ch - 'A') * 2 + 1) << setfill('=') << '=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch, 'A', -1, 0); //逆序打印 A~结束字符 
	cout << endl;

	/* 合起来就是漂亮的菱形（中间为A） */
	cout << setw((end_ch - 'A') * 2 + 1) << setfill('=') << '=' << endl;/* 按字母塔最大宽度输出= */
	cout << "菱形(" << end_ch << "->A)" << endl;
	cout << setw((end_ch - 'A') * 2 + 1) << setfill('=') << '=' << endl;/* 按字母塔最大宽度输出= */
	print_tower('A', end_ch, 1, 0);   //打印 A~结束字符的正三角 
	print_tower(end_ch-1, 'A', -1, 1);   //打印 A~结束字符-1的倒三角
	//注意这里depth是1，否则倒三角每一行前少一个空格

	cout << endl;

	return 0;
}


