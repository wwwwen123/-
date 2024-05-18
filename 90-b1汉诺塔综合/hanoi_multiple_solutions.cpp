/*2353126 信03 崔露文*/

/* ----------------------------------------------------------------------------------

	 本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

	 本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include"cmd_console_tools.h"
#include"hanoi.h"
using namespace std;

int step = 0;
int stackA[10] = { 0 }, stackB[10] = { 0 }, stackC[10] = { 0 };//圆柱上现有圆盘编号
int topA = 0, topB = 0, topC = 0;//圆柱上现有圆盘数量
static int yanshi = 0;//移动延时

const int A_X = 10, A_Y = 15;//纵向输出是字母A的位置设为基准

const int zhuA_X = 1, zhuA_Y = 15;//画三根柱子时A柱的左下角位置设为基准（A基座最左边的点）
const int length = 23; // 每个基座长为23
const int space = 9; // 两个基座之间空9位
const int height = 12; // 每个柱子高度为12
const int midA = 12, midB = 44, midC = 76;//三个基座的中间点横坐标


/***************************************************************************
     函数名称：delay
     功    能：控制延时
   ***************************************************************************/
void delay()
{
    switch (yanshi)
    {
        case 0://按回车单步演示
            int ch;
            while (1) {
                ch = _getch();
                if (ch == 13) {
                    break;
                }
            }
            break;
        case 1://延时最长
            Sleep(2000);
            break;
        case 2:
            Sleep(1500);
            break;
        case 3:
            Sleep(1000);
            break;
        case 4:
            Sleep(500);
            break;
        case 5://延时最短
            Sleep(100);//延时0.1秒
            break;
    }
}

/***************************************************************************
     函数名称：move
     功    能：进行移动操作
   ***************************************************************************/
void move(int n, char src, char dst)
{
    //从源柱移开盘子
    switch (src)
    {
        case 'A':
            stackA[--topA] = 0;
            break;
        case 'B':
            stackB[--topB] = 0;
            break;
        case 'C':
            stackC[--topC] = 0;
            break;
        default:
            break;
    }

    //将盘子添加到目标柱
    switch (dst)
    {
        case 'A':
            stackA[topA++] = n;
            break;
        case 'B':
            stackB[topB++] = n;
            break;
        case 'C':
            stackC[topC++] = n;
            break;
        default:
            break;
    }

}

   /***************************************************************************
	 函数名称：print
	 功    能：文字打印每个柱子盘子编号
   ***************************************************************************/
void print()
{
    cout << "A:";
    //遍历stackA数组，打印柱子A上的盘子
    for (int i = 0; i < 10; i++) {
        //如果遇到值为0的元素，就打印两个空格（表示这个位置没有盘子）
        if (stackA[i] == 0) {
            cout << "  ";
        }
        else {
            cout << setiosflags(ios::right) << setw(2) << stackA[i];
        }
    }

    cout << " B:";
    for (int i = 0; i < 10; i++) {
        if (stackB[i] == 0) {
            cout << "  ";
        }
        else {
            cout << setiosflags(ios::right) << setw(2) << stackB[i];
        }
    }

    cout << " C:";
    for (int i = 0; i < 10; i++) {
        if (stackC[i] == 0) {
            cout << "  ";
        }
        else {
            cout << setiosflags(ios::right) << setw(2) << stackC[i];
        }
    }

    cout << endl;
}


/***************************************************************************
  函数名称：print_heng
  功    能：菜单3、4、8中的横向输出
***************************************************************************/
void print_heng(int n, char src, char tmp, char dst, char choice)
{
    //switch-case别忘了加break啊啊啊！！！！
    switch (choice) 
    {
        case '1'://基本解
            cout << setiosflags(ios::right) << setw(2) << n << "# " << src << "-->" << dst << endl;
            break;
        case '2'://基本解（步数记录）
            step++;
            cout << "第" << setiosflags(ios::right) << setw(4) << step << " 步("
                << setw(2) << n << "#: " << src << "-->" << dst << ")" << endl;
            break;
        case '3'://内部数组显示（横向）
            step++;
            cout << "第" << setiosflags(ios::right) << setw(4) << step << " 步("
                << setw(2) << n << "#: " << src << "-->" << dst << ") ";
            move(n, src, dst);
            print();
            break;
        case '4'://内部数组显示（横向+纵向）
            delay();
            cct_gotoxy(0, A_Y + 4);
            step++;
            cout << "第" << setiosflags(ios::right) << setw(4) << step << " 步("
                << setw(2) << n << "#: " << src << "-->" << dst << ") ";
            
            move(n, src, dst);
            print();
            delay();
            print_zong(choice);
            break;
        case '8'://图形解-自动移动版本
            delay();
            cct_gotoxy(0, A_Y * 2 + 4);
            step++;
            cout << "第" << setiosflags(ios::right) << setw(4) << step << " 步("
                << setw(2) << n << "#: " << src << "-->" << dst << ") ";
            move(n, src, dst);
            print();
            //虽然命名是横向打印，但最后综合考量还是把菜单8的纵向打印和盘子移动的调用加在了这里
            //加在这里最高效，冗余少，而且能减少递归函数部分的行数！这是最大的好处
            print_zong(choice);
            move(n, dst, src);
            plate_move(n, src, tmp, dst, choice);
            move(n, src, dst);
            break;
    }
    
}

/***************************************************************************
  函数名称：print_zong
  功    能：菜单4、8中的纵向输出
***************************************************************************/
void print_zong(char choice)
{
    switch (choice) 
    {
        case '4'://内部数组显示（横向+纵向）

            //准备好显示三个柱子移动的框架
            cct_gotoxy(A_X - 2, A_Y - 1);
            cout << "=========================" << endl;
            cct_gotoxy(A_X, A_Y);
            cout << "A         B         C";

            //在对应位置打印盘子号
            for (int i = 0; i < 10; i++) {
                cct_gotoxy(A_X - 1, A_Y - 2 - i);
                //如果遇到值为0的元素，就打印两个空格（表示这个位置没有盘子）
                if (stackA[i] == 0) {
                    cout << "  ";
                }
                else {
                    cout << setiosflags(ios::right) << setw(2) << stackA[i];
                }
            }

            for (int i = 0; i < 10; i++) {
                cct_gotoxy(A_X - 1 + 10, A_Y - 2 - i);
                if (stackB[i] == 0) {
                    cout << "  ";
                }
                else {
                    cout << setiosflags(ios::right) << setw(2) << stackB[i];
                }
            }

            for (int i = 0; i < 10; i++) {
                cct_gotoxy(A_X - 1 + 20, A_Y - 2 - i);
                if (stackC[i] == 0) {
                    cout << "  ";
                }
                else {
                    cout << setiosflags(ios::right) << setw(2) << stackC[i];
                }
            }
            break;

        case '8':
            //基准纵坐标变为原来的2倍，给柱子图形部分让出位置
            //准备好显示三个柱子移动的框架
            cct_gotoxy(A_X - 2, A_Y * 2 - 1);
            cout << "=========================" << endl;
            cct_gotoxy(A_X, A_Y * 2);
            cout << "A         B         C";

            //在对应位置打印盘子号
            for (int i = 0; i < 10; i++) {
                cct_gotoxy(A_X - 1, A_Y * 2 - 2 - i);
                //如果遇到值为0的元素，就打印两个空格（表示这个位置没有盘子）
                if (stackA[i] == 0) {
                    cout << "  ";
                }
                else {
                    cout << setiosflags(ios::right) << setw(2) << stackA[i];
                }
            }

            for (int i = 0; i < 10; i++) {
                cct_gotoxy(A_X - 1 + 10, A_Y * 2 - 2 - i);
                if (stackB[i] == 0) {
                    cout << "  ";
                }
                else {
                    cout << setiosflags(ios::right) << setw(2) << stackB[i];
                }
            }

            for (int i = 0; i < 10; i++) {
                cct_gotoxy(A_X - 1 + 20, A_Y * 2 - 2 - i);
                if (stackC[i] == 0) {
                    cout << "  ";
                }
                else {
                    cout << setiosflags(ios::right) << setw(2) << stackC[i];
                }
            }
            break;
    }//switch
}


/***************************************************************************
  函数名称：print_cylinder
  功    能：在屏幕上画出三根柱子（菜单5）
***************************************************************************/
void print_cylinder()
{
    //柱子的基座部分
    for (int i = 0; i < 3; i++)
    {
        cct_showch(zhuA_X + i * (length + space), zhuA_Y, ' ', 14, 14, length);
    }

    //柱子的柱部分
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < 3; i++) {
            cct_showch(zhuA_X + i * (length + space) + length / 2, zhuA_Y - j - 1, ' ', 14, 14, 1);
            Sleep(50);//设置一个小延时
        }
    }

    cct_gotoxy(0, 40);
    cct_setcolor(0, 7);//恢复默认颜色
}


/***************************************************************************
  函数名称：print_plate
  功    能：在起始柱上画n个盘子（初始状态）（菜单6）
***************************************************************************/
void print_plate(char src, int n)
{
    int num = n;//用来递减同步修改盘子颜色
    int start_X = zhuA_X + (src - 'A') * (length + space); // 当前柱子的起始X坐标

    // 在指定柱子上绘制n个盘子，从底部开始
    for (int i = 0; i < n; i++) {
        int width = n * 2 + 1 - i * 2; // 计算盘子的宽度
        cct_showch(start_X + (length / 2 - width / 2), zhuA_Y - 1 - i, ' ', num, num, width);
        num--;
        Sleep(50);//设置一个小延时
    }

    cct_gotoxy(0, 40);
    cct_setcolor(0, 7);//恢复默认颜色
}


/***************************************************************************
  函数名称：plate_move
  功    能：在柱子间移动盘子（菜单7~9）
***************************************************************************/
//下面是第一次写的时候脑子有点浆糊了用的穷举法，最后保留的部分是结合宏定义、整合重复代码之后重新写的

//void plate_move(int n, char src, char tmp, char dst, char choice)
//{
//    //如果n是奇数，第一步是从起始柱移到目标柱
//    //如果n是偶数，第一步是从起始柱移到中间柱
//    //但是写的时候想不明白了，只能使用穷举法了
//    
//    Sleep(1000);
//    if (src == 'A')
//    {
//        //向上移动
//        for (int i = 0; i + topA < height; i++)
//        {
//            cct_showch(12, zhuA_Y - topA - i, ' ', 0, 0, 1); // 清除柱子顶部标记
//            //清除旧位置
//            cct_showch(12 - stackA[topA - 1], zhuA_Y - topA-i, ' ', 0, 0, stackA[topA - 1] * 2 + 1);
//            
//            //绘制新位置
//            cct_showch(12, zhuA_Y - topA - i, 0, 14, 14, 1);// 绘制柱子顶部标记
//            cct_showch(12 - stackA[topA - 1], zhuA_Y - topA - i-1, 0, stackA[topA - 1], stackA[topA - 1], stackA[topA - 1] * 2 + 1);
//            cct_showch(2, 3, ' ', 0, 0, 21);//消掉最上面剩余的
//            Sleep(50);                        
//        }       
//        if (dst == 'B')
//        {
//            //横向移动
//            for (int i = 0; i < length + space; i++)
//            {                     
//                // 清除旧位置的盘子图像
//                cct_showch(12 - stackA[topA - 1] + i, 1, ' ', 0, 0, stackA[topA - 1] * 2 + 1);
//                // 绘制新位置的盘子图像
//                if (i < length + space) // 在最后一次迭代时不再绘制新位置
//                {
//                    cct_showch(12 - stackA[topA - 1] + i + 1, 1, 0, stackA[topA - 1], stackA[topA - 1], stackA[topA - 1] * 2 + 1);
//                }
//                Sleep(50);
//            }
//
//            cct_showch(12 + length + space - stackA[topA - 1], 1, ' ', 0, 0, stackA[topA - 1] * 2 + 1);
//            
//            //向下移动
//            for (int i = 0; i < height-1 - topB; i++)
//            {
//                cct_showch(44, 3, ' ', 14, 14, 1);//new!
//                //清除旧位置
//                cct_showch(44 - stackA[topA - 1], 1 + i+2, ' ', 0, 0, stackA[topA - 1] * 2 + 1);
//                //如果不是第一步，也清除柱子顶部的标记
//                if (i != 0)
//                    cct_showch(44, 1 + i + 2, ' ', 14, 14, 1);
//                //绘制新位置
//                cct_showch(44 - stackA[topA - 1], 1 + i + 1+2, ' ', stackA[topA - 1], stackA[topA - 1], stackA[topA - 1] * 2 + 1);               
//                Sleep(50);               
//            }
//            
//            
//        }
//        else if (dst == 'C')
//        {
//            // 横向移动
//            for (int i = 0; i < 2 * (length + space); i++)
//            {
//                // 清除旧位置的盘子图像
//                cct_showch(12 - stackA[topA - 1] + i, 1, ' ', 0, 0, stackA[topA - 1] * 2 + 1);
//                // 绘制新位置的盘子图像
//                if (i < 2 * (length + space)) // 在最后一次迭代时不再绘制新位置
//                {
//                    cct_showch(12 - stackA[topA - 1] + i + 1, 1, 0, stackA[topA - 1], stackA[topA - 1], stackA[topA - 1] * 2 + 1);
//                }
//                Sleep(50);
//            }
//
//            // 清除最后一个盘子图像
//            cct_showch(12 + 2 * (length + space) - stackA[topA - 1], 1, ' ', 0, 0, stackA[topA - 1] * 2 + 1);
//
//            // 向下移动
//            for (int i = 0; i < height - 1 - topC; i++)
//            {
//                cct_showch(76, 3, ' ', 14, 14, 1);//new!
//                // 清除旧位置
//                cct_showch(76 - stackA[topA - 1], 1 + i + 2, ' ', 0, 0, stackA[topA - 1] * 2 + 1);
//                // 如果不是第一步，也清除柱子顶部的标记
//                if (i != 0)
//                {
//                    cct_showch(76, 1 + i + 2, ' ', 14, 14, 1);
//                }
//                // 绘制新位置
//                cct_showch(76 - stackA[topA - 1], 1 + i + 3, ' ', stackA[topA - 1], stackA[topA - 1], stackA[topA - 1] * 2 + 1);
//                Sleep(50);
//            }
//           
//        }
//
//    }//src=='A'
//    
//    if (src == 'B')
//    {
//        //向上移动
//        for (int i = 0; i + topB < height; i++)
//        {
//            cct_showch(44, zhuA_Y - topB - i, ' ', 0, 0, 1); // 清除柱子顶部标记
//            //清除旧位置
//            cct_showch(44 - stackB[topB - 1], zhuA_Y - topB - i, ' ', 0, 0, stackB[topB - 1] * 2 + 1);
//
//            //绘制新位置
//            cct_showch(44, zhuA_Y - topB - i, 0, 14, 14, 1);// 绘制柱子顶部标记
//            cct_showch(44 - stackB[topB - 1], zhuA_Y - topB - i - 1, 0, stackB[topB - 1], stackB[topB - 1], stackB[topB - 1] * 2 + 1);
//            cct_showch(34, 3, ' ', 0, 0, 21);//消掉最上面剩余的
//            Sleep(50);
//        }
//
//        if (dst == 'A')
//        {
//            //横向移动
//            for (int i = 0; i < length + space; i++)
//            {
//                // 清除旧位置的盘子图像
//                cct_showch(44 - stackB[topB - 1] - i, 1, ' ', 0, 0, stackB[topB - 1] * 2 + 1);
//                // 绘制新位置的盘子图像
//                if (i < length + space) // 在最后一次迭代时不再绘制新位置
//                {
//                    cct_showch(44 - stackB[topB - 1] - i - 1, 1, ' ', stackB[topB - 1], stackB[topB - 1], stackB[topB - 1] * 2 + 1);
//                }
//                Sleep(50);
//            }
//
//            cct_showch(44 - length - space - stackB[topB - 1], 1, ' ', 0, 0, stackB[topB - 1] * 2 + 1);
//
//            //向下移动
//            for (int i = 0; i < height - 1 - topA; i++)
//            {
//                cct_showch(12, 3, ' ', 14, 14, 1);//new!
//                //清除旧位置
//                cct_showch(12 - stackB[topB - 1], 1 + i + 2, ' ', 0, 0, stackB[topB - 1] * 2 + 1);
//                //如果不是第一步，也清除柱子顶部的标记
//                if (i != 0)
//                    cct_showch(12, 1 + i + 2, ' ', 14, 14, 1);
//                //绘制新位置
//                cct_showch(12 - stackB[topB - 1], 1 + i + 1 + 2, ' ', stackB[topB - 1], stackB[topB - 1], stackB[topB - 1] * 2 + 1);
//                Sleep(50);
//            }
//        }
//        else if (dst == 'C')
//        {
//            //横向移动
//            for (int i = 0; i < length + space; i++)
//            {
//                // 清除旧位置的盘子图像
//                cct_showch(44 - stackB[topB - 1] + i, 1, ' ', 0, 0, stackB[topB - 1] * 2 + 1);
//                // 绘制新位置的盘子图像
//                if (i < length + space) // 在最后一次迭代时不再绘制新位置
//                {
//                    cct_showch(44 - stackB[topB - 1] + i + 1, 1, ' ', stackB[topB - 1], stackB[topB - 1], stackB[topB - 1] * 2 + 1);
//                }
//                Sleep(50);
//            }
//
//            cct_showch(44 + length + space - stackB[topB - 1], 1, ' ', 0, 0, stackB[topB - 1] * 2 + 1);
//
//            //向下移动
//            for (int i = 0; i < height - 1 - topC; i++)
//            {
//                cct_showch(76, 3, ' ', 14, 14, 1);//new!
//                //清除旧位置
//                cct_showch(76 - stackB[topB - 1], 1 + i + 2, ' ', 0, 0, stackB[topB - 1] * 2 + 1);
//                //如果不是第一步，也清除柱子顶部的标记
//                if (i != 0)
//                    cct_showch(76, 1 + i + 2, ' ', 14, 14, 1);
//                //绘制新位置
//                cct_showch(76 - stackB[topB - 1], 1 + i + 1 + 2, ' ', stackB[topB - 1], stackB[topB - 1], stackB[topB - 1] * 2 + 1);
//                Sleep(50);
//            }
//        }
//
//    }//src=='B'
//
//    if (src == 'C')
//    {
//        //向上移动
//        for (int i = 0; i + topC < height; i++)
//        {
//            cct_showch(76, zhuA_Y - topC - i, ' ', 0, 0, 1); // 清除柱子顶部标记
//            //清除旧位置
//            cct_showch(76 - stackC[topC - 1], zhuA_Y - topC - i, ' ', 0, 0, stackC[topC - 1] * 2 + 1);
//
//            //绘制新位置
//            cct_showch(76, zhuA_Y - topC - i, ' ', 14, 14, 1);// 绘制柱子顶部标记
//            cct_showch(76 - stackC[topC - 1], zhuA_Y - topC - i - 1, 0, stackC[topC - 1], stackC[topC - 1], stackC[topC - 1] * 2 + 1);
//            cct_showch(66, 3, ' ', 0, 0, 21);//消掉最上面剩余的
//            Sleep(50);
//        }
//
//        if (dst == 'A')
//        {
//            //横向移动
//            for (int i = 0; i < (length + space)*2; i++)
//            {
//                // 清除旧位置的盘子图像
//                cct_showch(76 - stackC[topC - 1] - i, 1, ' ', 0, 0, stackC[topC - 1] * 2 + 1);
//                // 绘制新位置的盘子图像
//                if (i < (length + space)*2) // 在最后一次迭代时不再绘制新位置
//                {
//                    cct_showch(76 - stackC[topC - 1] - i - 1, 1, ' ', stackC[topC - 1], stackC[topC - 1], stackC[topC - 1] * 2 + 1);
//                }
//                Sleep(50);
//            }
//
//            cct_showch(76 - (length - space)*2 - stackC[topC - 1], 1, ' ', 0, 0, stackC[topC - 1] * 2 + 1);
//
//            //向下移动
//            for (int i = 0; i < height - 1 - topA; i++)
//            {
//                cct_showch(12, 3, ' ', 14, 14, 1);//new!
//                //清除旧位置
//                cct_showch(12 - stackC[topC - 1], 1 + i + 2, ' ', 0, 0, stackC[topC - 1] * 2 + 1);
//                //如果不是第一步，也清除柱子顶部的标记
//                if (i != 0)
//                    cct_showch(12, 1 + i + 2, ' ', 14, 14, 1);
//                //绘制新位置
//                cct_showch(12 - stackC[topC - 1], 1 + i + 1 + 2, ' ', stackC[topC - 1], stackC[topC - 1], stackC[topC - 1] * 2 + 1);
//                Sleep(50);
//            }
//        }
//        else if (dst == 'B')
//        {
//            //横向移动
//            for (int i = 0; i < length + space; i++)
//            {
//                // 清除旧位置的盘子图像
//                cct_showch(76 - stackC[topC - 1] - i, 1, ' ', 0, 0, stackC[topC - 1] * 2 + 1);
//                // 绘制新位置的盘子图像
//                if (i < length + space) // 在最后一次迭代时不再绘制新位置
//                {
//                    cct_showch(76 - stackC[topC - 1] - i - 1, 1, ' ', stackC[topC - 1], stackC[topC - 1], stackC[topC - 1] * 2 + 1);
//                }
//                Sleep(50);
//            }
//
//            cct_showch(76 - length - space - stackC[topC - 1], 1, ' ', 0, 0, stackC[topC - 1] * 2 + 1);
//
//            //向下移动
//            for (int i = 0; i < height - 1 - topB; i++)
//            {
//                cct_showch(44, 3, ' ', 14, 14, 1);//new!
//                //清除旧位置
//                cct_showch(44 - stackC[topC - 1], 1 + i + 2, ' ', 0, 0, stackC[topC - 1] * 2 + 1);
//                //如果不是第一步，也清除柱子顶部的标记
//                if (i != 0)
//                    cct_showch(44, 1 + i + 2, ' ', 14, 14, 1);
//                //绘制新位置
//                cct_showch(44 - stackC[topC - 1], 1 + i + 1 + 2, ' ', stackC[topC - 1], stackC[topC - 1], stackC[topC - 1] * 2 + 1);
//                Sleep(50);
//            }
//        }
//
//    }//src=='C'
//    
//
//    cct_gotoxy(0, 35);
//    cct_setcolor(0, 7); // 恢复默认颜色
//}

void plate_move(int n, char src, char tmp, char dst, char choice)
{
    Sleep(1000);//初始化完成后多停留一会
    int top = 0, top_dst = 0, mid = 0, mid_dst = 0;
    int* stack = NULL;//后续用来指向数组stackA、B、C
    switch (src)
    {
        case 'A':
            top = topA;
            mid = midA;
            stack = stackA;
            break;
        case 'B':
            top = topB;
            mid = midB;
            stack = stackB;
            break;
        case 'C':
            top = topC;
            mid = midC;
            stack = stackC;
            break;
    }
    switch(dst)
    {
        case 'A':
            mid_dst = midA;
            top_dst = topA;
            break;
        case 'B':
            mid_dst = midB;
            top_dst = topB;
            break;
        case 'C':
            mid_dst = midC;
            top_dst = topC;
            break;
    }

    //向上移动
    for (int i = 0; i + top < height; i++)
    {
        cct_showch(mid, zhuA_Y - top - i, ' ', 0, 0, 1);// 清除柱子顶部标记
        //清除旧位置
        cct_showch(mid - stack[top - 1], zhuA_Y - top - i, ' ', 0, 0, stack[top - 1] * 2 + 1);
        //绘制新位置
        cct_showch(mid, zhuA_Y - top - i, ' ', 14, 14, 1);// 绘制柱子顶部标记
        cct_showch(mid - stack[top - 1], zhuA_Y - top - i - 1, ' ', stack[top - 1], stack[top - 1], stack[top - 1] * 2 + 1);
        cct_showch(mid - length / 2 + 1, 3, ' ', 0, 0, 21);//消掉最上面剩余的
        Sleep(50);
    }

    //横向移动
    int distance = abs(dst - src) * (length + space);//横向移动距离
    for (int i = 0; i < distance; i++)
    {
        //清除旧位置的盘子图像
        cct_showch(mid - stack[top - 1] + (dst - src > 0 ? 1 : -1) * i, 1, ' ', 0, 0, stack[top - 1] * 2 + 1);
        //绘制新位置的盘子图像
        if (i < distance)  //在最后一次迭代时不再绘制新位置
        {
            cct_showch(mid - stack[top - 1] +(dst-src>0?1:-1)*(i+1), 1, ' ', stack[top - 1], stack[top - 1], stack[top - 1] * 2 + 1);
        }
        Sleep(50);
    }
    cct_showch(mid + (dst - src > 0 ? 1 : -1) * distance - stack[top - 1], 1, ' ', 0, 0, stack[top - 1] * 2 + 1);

    //向下移动
    for (int i = 0; i < height - 1 - top_dst; i++)
    {
        cct_showch(mid_dst, 3, ' ', 14, 14, 1);
        //清除旧位置
        cct_showch(mid_dst - stack[top - 1], 1 + i + 2, ' ', 0, 0, stack[top - 1] * 2 + 1);
        //如果不是第一步，也清除柱子顶部的标记
        if (i != 0)
        {
            cct_showch(mid_dst, 1 + i + 2, ' ', 14, 14, 1);
        }
        //绘制新位置
        cct_showch(mid_dst - stack[top - 1], 1 + i + 3, ' ', stack[top - 1], stack[top - 1], stack[top - 1] * 2 + 1);
        Sleep(50);
    }

    cct_gotoxy(0, 35);
    cct_setcolor(0, 7); // 恢复默认颜色
}





/***************************************************************************
  函数名称：hanoi
  功    能：递归函数
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst, char choice)
{
    if (n == 1)
        print_heng(n, src, tmp, dst, choice);
    else
    {
        hanoi(n - 1, src, dst, tmp, choice);
        print_heng(n, src, tmp, dst, choice);
        hanoi(n - 1, tmp, src, dst, choice);
    }
}

/***************************************************************************
  函数名称：initialization
  功    能：初始化以及各种准备工作
***************************************************************************/
void initialization(char choice)
{
    //全部置0重新开始，否则上一次的数据会留下！！！
    step = 0;
    for (int i = 0; i < 10; ++i) {
        stackA[i] = 0;
        stackB[i] = 0;
        stackC[i] = 0;
    }
    topA = 0, topB = 0, topC = 0;


    int n;
    char src, tmp, dst;
    cout << endl;

    if (choice == '5')
    {
        return;
    }


    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        if (n < 1 || n>10) {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        else {
            cin.clear();
            cin.ignore(65536, '\n');
            break;
        }
    }

    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        cin.ignore(65536, '\n');
        if (src >= 'a' && src <= 'c')
            src -= 32;//小写转大写
        if (src >= 'A' && src <= 'C')
            break;
    }

    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        cin.ignore(65536, '\n');
        if (dst >= 'a' && dst <= 'c')
            dst -= 32;//小写转大写
        if (dst == src) {
            cout << "目标柱(" << src << ")不能与起始柱(" << dst << ")相同" << endl;
            continue;
        }
        if (dst >= 'A' && dst <= 'C')
            break;
    }

    tmp = 'A' + 'B' + 'C' - src - dst;

    //对柱子进行初始化，确保最大的盘子在底部，最小的盘子在顶部
    for (int i = 0; i < n; i++)
    {
        switch (src)
        {
            case 'A':
                stackA[i] = n - i;
                topA = n;
                break;
            case 'B':
                stackB[i] = n - i;
                topB = n;
                break;
            case 'C':
                stackC[i] = n - i;
                topC = n;
                break;
        }
    }


    if (choice == '4' || choice == '8')
    {
        while (1)
        {
            cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
            cin >> yanshi;
            if (cin.fail() || yanshi < 0 || yanshi > 5)
            {
                cin.clear();
                cin.ignore(65536, '\n');
                continue;
            }
            else
            {
                //break;
                cin.clear();
                cin.ignore(65536, '\n');
            }

            cct_cls();

            cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << yanshi << endl;

            if (choice == '4') 
            {
                print_zong(choice);
                cct_gotoxy(0, A_Y + 4);
                cout << "初始:  ";
                print();
                hanoi(n, src, tmp, dst, choice);
                cct_gotoxy(0, 40);
                break;
                
            }

            if (choice == '8')
            {
                print_zong(choice);
                cct_gotoxy(0, A_Y * 2 + 4);
                cout << "初始:                ";
                print();
                print_cylinder();//在屏幕上画出三根柱子
                print_plate(src, n);//在起始柱上画n个盘子
                hanoi(n, src, tmp, dst, choice);
                cct_gotoxy(0, 40);
                break;
            }

        }
        return;
    }
    
    else if (choice == '6')//图形解-预备-在起始柱上画n个盘子
    {
        cct_cls();
        cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层" << endl;
        print_cylinder();//在屏幕上画出三根柱子
        print_plate(src, n);//在起始柱上画n个盘子
    }
   
    else if (choice == '7')//图形解-预备-第一次移动
    {
        cct_cls();
        cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层" << endl;
        print_cylinder();//在屏幕上画出三根柱子
        print_plate(src, n);//在起始柱上画n个盘子

        //如果n是奇数，第一步是从起始柱移到目标柱
        //如果n是偶数，第一步是从起始柱移到中间柱
        if (n % 2 == 1) 
            plate_move(n, src, tmp, dst, choice);
        else
            plate_move(n, src, dst, tmp, choice);
    }

    else if (choice == '9')
    {


    }

    else
        hanoi(n, src, tmp, dst, choice);

}