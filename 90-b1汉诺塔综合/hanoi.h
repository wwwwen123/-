/*2353126 信03 崔露文*/
#pragma once

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */

char menu(void);//菜单
void delay(void);//控制延时
void move(int n, char src, char dst);
void print(void);
void print_heng(int n, char src, char tmp, char dst, char choice);//横向输出
void print_zong(char choice);//纵向输出
void print_cylinder(void);//在屏幕上画出三根柱子
void print_plate(char src, int n);//在起始柱上画n个盘子
void plate_move(int n, char src, char tmp, char dst, char choice);//盘子移动
void hanoi(int n, char src, char tmp, char dst, char choice);//递归函数
void initialization(char choice);//初始化+准备工作


