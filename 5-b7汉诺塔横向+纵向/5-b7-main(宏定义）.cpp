/*2353126 ��03 ��¶��*/
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include "5-b7.h"
using namespace std;

int step = 0;
int stackA[10] = { 0 }, stackB[10] = { 0 }, stackC[10] = { 0 };
int topA = 0, topB = 0, topC = 0;
static int yanshi = 0;//�ƶ���ʱ
static int xianshishuzu = 0;

const int A_X = 10, A_Y = 15;//������ʽ����ĸ'A'�Ļ�׼λ��

void delay() 
{
    switch (yanshi) 
    {
        case 0://���س�������ʾ
            int ch;
            while (1) {
                ch = _getch();
                if (ch == 13) {
                    break;
                }
            }
            break;
        case 1://��ʱ�
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
        case 5://��ʱ���
            Sleep(100);//��ʱ0.1��
            break;
    }
}

void move(int n, char src, char dst)
{
    //��Դ���ƿ�����
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

    //��������ӵ�Ŀ����
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
    //����stackA���飬��ӡ����A�ϵ�����
    for (int i = 0; i < 10; i++) {
        //�������ֵΪ0��Ԫ�أ��ʹ�ӡ�����ո񣨱�ʾ���λ��û�����ӣ�
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
        cout << "��" << setiosflags(ios::right) << setw(4) << step << " ��("
            << 1 << "# " << src << "-->" << dst << "): " << " ";
        move(n, src, dst);
        if (xianshishuzu == 1) {
            print();
            delay();
        }

        //׼������ʾ���������ƶ��Ŀ��
        cct_gotoxy(A_X - 2, A_Y - 1);
        cout << "=========================" << endl;
        cct_gotoxy(A_X, A_Y);
        cout << "A         B         C";


        //�ڶ�Ӧλ�ô�ӡ���Ӻ�

        for (int i = 0; i < 10; i++) {
            cct_gotoxy(A_X - 1, A_Y - 2 - i);
            //�������ֵΪ0��Ԫ�أ��ʹ�ӡ�����ո񣨱�ʾ���λ��û�����ӣ�
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

    //���else��ָ��n>1ʱ
    else {
        hanoi(n - 1, src, dst, tmp);
        delay();
        cct_gotoxy(A_X + 9, A_Y + 4);
        step++;
        cout << "��" << setiosflags(ios::right) << setw(4) << step << " ��("
            << n << "# " << src << "-->" << dst << "): " << " ";
        move(n, src, dst);
        if (xianshishuzu == 1) {
            print();
            delay();
        }

        //׼������ʾ���������ƶ��Ŀ��
        cct_gotoxy(A_X - 2, A_Y - 1);
        cout << "=========================" << endl;
        cct_gotoxy(A_X, A_Y);
        cout << "A         B         C";


        //�ڶ�Ӧλ�ô�ӡ���Ӻ�

        for (int i = 0; i < 10; i++) {
            cct_gotoxy(A_X - 1, A_Y - 2 - i);
            //�������ֵΪ0��Ԫ�أ��ʹ�ӡ�����ո񣨱�ʾ���λ��û�����ӣ�
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
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
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
        cout << "��������ʼ��(A-C)" << endl;
        cin >> src;
        cin.ignore(65536, '\n');
        if (src >= 'a' && src <= 'c')
            src -= 32;//Сдת��д
        if (src >= 'A' && src <= 'C')
            break;
    }

    while (1)
    {
        cout << "������Ŀ����(A-C)" << endl;
        cin >> dst;
        cin.ignore(65536, '\n');
        if (dst >= 'a' && dst <= 'c')
            dst -= 32;//Сдת��д
        if (dst == src) {
            cout << "Ŀ����(" << src << ")��������ʼ��(" << dst << ")��ͬ" << endl;
            continue;
        }
        if (dst >= 'A' && dst <= 'C')
            break;
    }

    tmp = 'A' + 'B' + 'C' - src - dst;

    //�����ӽ��г�ʼ����ȷ�����������ڵײ�����С�������ڶ���
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
        cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
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
        cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
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

    cct_cls();//���������ѡ�������

    if (xianshishuzu == 0) {
        cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << yanshi << "������ʾ�ڲ�����ֵ" << endl;
        /*cct_gotoxy(22, 25);
        cout << "��ʼ:                ";
        print();*/   //д�����ﲻ�ԣ�����û���Ϊʲô��
    }
    if (xianshishuzu == 1) {
        cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << yanshi << "����ʾ�ڲ�����ֵ" << endl;
    }

    if (xianshishuzu == 1)
    {
        cct_gotoxy(A_X + 9, A_Y + 4);
        cout << "��ʼ:" << setw(16) << " ";
        print();
    }
    
    cct_gotoxy(A_X - 2, A_Y - 1);
    cout << "=========================" << endl;
    cct_gotoxy(A_X, A_Y);
    cout << "A         B         C";

    for (int i = 0; i < 10; i++) {
        cct_gotoxy(A_X - 1, A_Y - 2 - i);
        //�������ֵΪ0��Ԫ�أ��ʹ�ӡ�����ո񣨱�ʾ���λ��û�����ӣ�
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