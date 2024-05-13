/*2353126 信03 崔露文*/
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include "5-b7.h"
using namespace std;

int step = 0;
int stackA[10] = { 0 }, stackB[10] = { 0 }, stackC[10] = { 0 };
int topA = 0, topB = 0, topC = 0;
static int yanshi = 0;//移动延时
static int xianshishuzu = 0;

const int A_X = 10, A_Y = 15;//设置竖式中字母'A'的基准位置

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

void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        delay();
        cct_gotoxy(A_X + 9, A_Y + 4);
        step++;
        cout << "第" << setiosflags(ios::right) << setw(4) << step << " 步("
            << 1 << "# " << src << "-->" << dst << "): " << " ";
        move(n, src, dst);
        if (xianshishuzu == 1) {
            print();
            delay();
        }

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
    }

    //这个else是指当n>1时
    else {
        hanoi(n - 1, src, dst, tmp);
        delay();
        cct_gotoxy(A_X + 9, A_Y + 4);
        step++;
        cout << "第" << setiosflags(ios::right) << setw(4) << step << " 步("
            << n << "# " << src << "-->" << dst << "): " << " ";
        move(n, src, dst);
        if (xianshishuzu == 1) {
            print();
            delay();
        }

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
        hanoi(n - 1, tmp, src, dst);
    }
}


int main()
{
    int n;
    char src, tmp, dst;

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
            break;
        }
    }

    while (1) 
    {
        cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
        cin >> xianshishuzu;
        if (cin.fail() || xianshishuzu < 0 || xianshishuzu > 1)
        {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        else
        {
            break;
        }
    }

    cct_cls();//设置完各种选项后，清屏

    if (xianshishuzu == 0) {
        cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << yanshi << "，不显示内部数组值" << endl;
        /*cct_gotoxy(22, 25);
        cout << "初始:                ";
        print();*/   //写在这里不对，但还没想好为什么？
    }
    if (xianshishuzu == 1) {
        cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << yanshi << "，显示内部数组值" << endl;
    }

    if (xianshishuzu == 1)
    {
        cct_gotoxy(A_X + 9, A_Y + 4);
        cout << "初始:" << setw(16) << " ";
        print();
    }
    
    cct_gotoxy(A_X - 2, A_Y - 1);
    cout << "=========================" << endl;
    cct_gotoxy(A_X, A_Y);
    cout << "A         B         C";

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

    hanoi(n, src, tmp, dst);

    cct_gotoxy(0, 37);
    return 0;
}