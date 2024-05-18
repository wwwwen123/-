/*2353126 ��03 ��¶��*/

/* ----------------------------------------------------------------------------------

	 ���ļ����ܣ�
	1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

	 ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include"cmd_console_tools.h"
#include"hanoi.h"
using namespace std;

int step = 0;
int stackA[10] = { 0 }, stackB[10] = { 0 }, stackC[10] = { 0 };//Բ��������Բ�̱��
int topA = 0, topB = 0, topC = 0;//Բ��������Բ������
static int yanshi = 0;//�ƶ���ʱ

const int A_X = 10, A_Y = 15;//�����������ĸA��λ����Ϊ��׼

const int zhuA_X = 1, zhuA_Y = 15;//����������ʱA�������½�λ����Ϊ��׼��A��������ߵĵ㣩
const int length = 23; // ÿ��������Ϊ23
const int space = 9; // ��������֮���9λ
const int height = 12; // ÿ�����Ӹ߶�Ϊ12
const int midA = 12, midB = 44, midC = 76;//�����������м�������


/***************************************************************************
     �������ƣ�delay
     ��    �ܣ�������ʱ
   ***************************************************************************/
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

/***************************************************************************
     �������ƣ�move
     ��    �ܣ������ƶ�����
   ***************************************************************************/
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

   /***************************************************************************
	 �������ƣ�print
	 ��    �ܣ����ִ�ӡÿ���������ӱ��
   ***************************************************************************/
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


/***************************************************************************
  �������ƣ�print_heng
  ��    �ܣ��˵�3��4��8�еĺ������
***************************************************************************/
void print_heng(int n, char src, char tmp, char dst, char choice)
{
    //switch-case�����˼�break��������������
    switch (choice) 
    {
        case '1'://������
            cout << setiosflags(ios::right) << setw(2) << n << "# " << src << "-->" << dst << endl;
            break;
        case '2'://�����⣨������¼��
            step++;
            cout << "��" << setiosflags(ios::right) << setw(4) << step << " ��("
                << setw(2) << n << "#: " << src << "-->" << dst << ")" << endl;
            break;
        case '3'://�ڲ�������ʾ������
            step++;
            cout << "��" << setiosflags(ios::right) << setw(4) << step << " ��("
                << setw(2) << n << "#: " << src << "-->" << dst << ") ";
            move(n, src, dst);
            print();
            break;
        case '4'://�ڲ�������ʾ������+����
            delay();
            cct_gotoxy(0, A_Y + 4);
            step++;
            cout << "��" << setiosflags(ios::right) << setw(4) << step << " ��("
                << setw(2) << n << "#: " << src << "-->" << dst << ") ";
            
            move(n, src, dst);
            print();
            delay();
            print_zong(choice);
            break;
        case '8'://ͼ�ν�-�Զ��ƶ��汾
            delay();
            cct_gotoxy(0, A_Y * 2 + 4);
            step++;
            cout << "��" << setiosflags(ios::right) << setw(4) << step << " ��("
                << setw(2) << n << "#: " << src << "-->" << dst << ") ";
            move(n, src, dst);
            print();
            //��Ȼ�����Ǻ����ӡ��������ۺϿ������ǰѲ˵�8�������ӡ�������ƶ��ĵ��ü���������
            //�����������Ч�������٣������ܼ��ٵݹ麯�����ֵ��������������ĺô�
            print_zong(choice);
            move(n, dst, src);
            plate_move(n, src, tmp, dst, choice);
            move(n, src, dst);
            break;
    }
    
}

/***************************************************************************
  �������ƣ�print_zong
  ��    �ܣ��˵�4��8�е��������
***************************************************************************/
void print_zong(char choice)
{
    switch (choice) 
    {
        case '4'://�ڲ�������ʾ������+����

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
            break;

        case '8':
            //��׼�������Ϊԭ����2����������ͼ�β����ó�λ��
            //׼������ʾ���������ƶ��Ŀ��
            cct_gotoxy(A_X - 2, A_Y * 2 - 1);
            cout << "=========================" << endl;
            cct_gotoxy(A_X, A_Y * 2);
            cout << "A         B         C";

            //�ڶ�Ӧλ�ô�ӡ���Ӻ�
            for (int i = 0; i < 10; i++) {
                cct_gotoxy(A_X - 1, A_Y * 2 - 2 - i);
                //�������ֵΪ0��Ԫ�أ��ʹ�ӡ�����ո񣨱�ʾ���λ��û�����ӣ�
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
  �������ƣ�print_cylinder
  ��    �ܣ�����Ļ�ϻ����������ӣ��˵�5��
***************************************************************************/
void print_cylinder()
{
    //���ӵĻ�������
    for (int i = 0; i < 3; i++)
    {
        cct_showch(zhuA_X + i * (length + space), zhuA_Y, ' ', 14, 14, length);
    }

    //���ӵ�������
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < 3; i++) {
            cct_showch(zhuA_X + i * (length + space) + length / 2, zhuA_Y - j - 1, ' ', 14, 14, 1);
            Sleep(50);//����һ��С��ʱ
        }
    }

    cct_gotoxy(0, 40);
    cct_setcolor(0, 7);//�ָ�Ĭ����ɫ
}


/***************************************************************************
  �������ƣ�print_plate
  ��    �ܣ�����ʼ���ϻ�n�����ӣ���ʼ״̬�����˵�6��
***************************************************************************/
void print_plate(char src, int n)
{
    int num = n;//�����ݼ�ͬ���޸�������ɫ
    int start_X = zhuA_X + (src - 'A') * (length + space); // ��ǰ���ӵ���ʼX����

    // ��ָ�������ϻ���n�����ӣ��ӵײ���ʼ
    for (int i = 0; i < n; i++) {
        int width = n * 2 + 1 - i * 2; // �������ӵĿ��
        cct_showch(start_X + (length / 2 - width / 2), zhuA_Y - 1 - i, ' ', num, num, width);
        num--;
        Sleep(50);//����һ��С��ʱ
    }

    cct_gotoxy(0, 40);
    cct_setcolor(0, 7);//�ָ�Ĭ����ɫ
}


/***************************************************************************
  �������ƣ�plate_move
  ��    �ܣ������Ӽ��ƶ����ӣ��˵�7~9��
***************************************************************************/
//�����ǵ�һ��д��ʱ�������е㽬�����õ���ٷ���������Ĳ����ǽ�Ϻ궨�塢�����ظ�����֮������д��

//void plate_move(int n, char src, char tmp, char dst, char choice)
//{
//    //���n����������һ���Ǵ���ʼ���Ƶ�Ŀ����
//    //���n��ż������һ���Ǵ���ʼ���Ƶ��м���
//    //����д��ʱ���벻�����ˣ�ֻ��ʹ����ٷ���
//    
//    Sleep(1000);
//    if (src == 'A')
//    {
//        //�����ƶ�
//        for (int i = 0; i + topA < height; i++)
//        {
//            cct_showch(12, zhuA_Y - topA - i, ' ', 0, 0, 1); // ������Ӷ������
//            //�����λ��
//            cct_showch(12 - stackA[topA - 1], zhuA_Y - topA-i, ' ', 0, 0, stackA[topA - 1] * 2 + 1);
//            
//            //������λ��
//            cct_showch(12, zhuA_Y - topA - i, 0, 14, 14, 1);// �������Ӷ������
//            cct_showch(12 - stackA[topA - 1], zhuA_Y - topA - i-1, 0, stackA[topA - 1], stackA[topA - 1], stackA[topA - 1] * 2 + 1);
//            cct_showch(2, 3, ' ', 0, 0, 21);//����������ʣ���
//            Sleep(50);                        
//        }       
//        if (dst == 'B')
//        {
//            //�����ƶ�
//            for (int i = 0; i < length + space; i++)
//            {                     
//                // �����λ�õ�����ͼ��
//                cct_showch(12 - stackA[topA - 1] + i, 1, ' ', 0, 0, stackA[topA - 1] * 2 + 1);
//                // ������λ�õ�����ͼ��
//                if (i < length + space) // �����һ�ε���ʱ���ٻ�����λ��
//                {
//                    cct_showch(12 - stackA[topA - 1] + i + 1, 1, 0, stackA[topA - 1], stackA[topA - 1], stackA[topA - 1] * 2 + 1);
//                }
//                Sleep(50);
//            }
//
//            cct_showch(12 + length + space - stackA[topA - 1], 1, ' ', 0, 0, stackA[topA - 1] * 2 + 1);
//            
//            //�����ƶ�
//            for (int i = 0; i < height-1 - topB; i++)
//            {
//                cct_showch(44, 3, ' ', 14, 14, 1);//new!
//                //�����λ��
//                cct_showch(44 - stackA[topA - 1], 1 + i+2, ' ', 0, 0, stackA[topA - 1] * 2 + 1);
//                //������ǵ�һ����Ҳ������Ӷ����ı��
//                if (i != 0)
//                    cct_showch(44, 1 + i + 2, ' ', 14, 14, 1);
//                //������λ��
//                cct_showch(44 - stackA[topA - 1], 1 + i + 1+2, ' ', stackA[topA - 1], stackA[topA - 1], stackA[topA - 1] * 2 + 1);               
//                Sleep(50);               
//            }
//            
//            
//        }
//        else if (dst == 'C')
//        {
//            // �����ƶ�
//            for (int i = 0; i < 2 * (length + space); i++)
//            {
//                // �����λ�õ�����ͼ��
//                cct_showch(12 - stackA[topA - 1] + i, 1, ' ', 0, 0, stackA[topA - 1] * 2 + 1);
//                // ������λ�õ�����ͼ��
//                if (i < 2 * (length + space)) // �����һ�ε���ʱ���ٻ�����λ��
//                {
//                    cct_showch(12 - stackA[topA - 1] + i + 1, 1, 0, stackA[topA - 1], stackA[topA - 1], stackA[topA - 1] * 2 + 1);
//                }
//                Sleep(50);
//            }
//
//            // ������һ������ͼ��
//            cct_showch(12 + 2 * (length + space) - stackA[topA - 1], 1, ' ', 0, 0, stackA[topA - 1] * 2 + 1);
//
//            // �����ƶ�
//            for (int i = 0; i < height - 1 - topC; i++)
//            {
//                cct_showch(76, 3, ' ', 14, 14, 1);//new!
//                // �����λ��
//                cct_showch(76 - stackA[topA - 1], 1 + i + 2, ' ', 0, 0, stackA[topA - 1] * 2 + 1);
//                // ������ǵ�һ����Ҳ������Ӷ����ı��
//                if (i != 0)
//                {
//                    cct_showch(76, 1 + i + 2, ' ', 14, 14, 1);
//                }
//                // ������λ��
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
//        //�����ƶ�
//        for (int i = 0; i + topB < height; i++)
//        {
//            cct_showch(44, zhuA_Y - topB - i, ' ', 0, 0, 1); // ������Ӷ������
//            //�����λ��
//            cct_showch(44 - stackB[topB - 1], zhuA_Y - topB - i, ' ', 0, 0, stackB[topB - 1] * 2 + 1);
//
//            //������λ��
//            cct_showch(44, zhuA_Y - topB - i, 0, 14, 14, 1);// �������Ӷ������
//            cct_showch(44 - stackB[topB - 1], zhuA_Y - topB - i - 1, 0, stackB[topB - 1], stackB[topB - 1], stackB[topB - 1] * 2 + 1);
//            cct_showch(34, 3, ' ', 0, 0, 21);//����������ʣ���
//            Sleep(50);
//        }
//
//        if (dst == 'A')
//        {
//            //�����ƶ�
//            for (int i = 0; i < length + space; i++)
//            {
//                // �����λ�õ�����ͼ��
//                cct_showch(44 - stackB[topB - 1] - i, 1, ' ', 0, 0, stackB[topB - 1] * 2 + 1);
//                // ������λ�õ�����ͼ��
//                if (i < length + space) // �����һ�ε���ʱ���ٻ�����λ��
//                {
//                    cct_showch(44 - stackB[topB - 1] - i - 1, 1, ' ', stackB[topB - 1], stackB[topB - 1], stackB[topB - 1] * 2 + 1);
//                }
//                Sleep(50);
//            }
//
//            cct_showch(44 - length - space - stackB[topB - 1], 1, ' ', 0, 0, stackB[topB - 1] * 2 + 1);
//
//            //�����ƶ�
//            for (int i = 0; i < height - 1 - topA; i++)
//            {
//                cct_showch(12, 3, ' ', 14, 14, 1);//new!
//                //�����λ��
//                cct_showch(12 - stackB[topB - 1], 1 + i + 2, ' ', 0, 0, stackB[topB - 1] * 2 + 1);
//                //������ǵ�һ����Ҳ������Ӷ����ı��
//                if (i != 0)
//                    cct_showch(12, 1 + i + 2, ' ', 14, 14, 1);
//                //������λ��
//                cct_showch(12 - stackB[topB - 1], 1 + i + 1 + 2, ' ', stackB[topB - 1], stackB[topB - 1], stackB[topB - 1] * 2 + 1);
//                Sleep(50);
//            }
//        }
//        else if (dst == 'C')
//        {
//            //�����ƶ�
//            for (int i = 0; i < length + space; i++)
//            {
//                // �����λ�õ�����ͼ��
//                cct_showch(44 - stackB[topB - 1] + i, 1, ' ', 0, 0, stackB[topB - 1] * 2 + 1);
//                // ������λ�õ�����ͼ��
//                if (i < length + space) // �����һ�ε���ʱ���ٻ�����λ��
//                {
//                    cct_showch(44 - stackB[topB - 1] + i + 1, 1, ' ', stackB[topB - 1], stackB[topB - 1], stackB[topB - 1] * 2 + 1);
//                }
//                Sleep(50);
//            }
//
//            cct_showch(44 + length + space - stackB[topB - 1], 1, ' ', 0, 0, stackB[topB - 1] * 2 + 1);
//
//            //�����ƶ�
//            for (int i = 0; i < height - 1 - topC; i++)
//            {
//                cct_showch(76, 3, ' ', 14, 14, 1);//new!
//                //�����λ��
//                cct_showch(76 - stackB[topB - 1], 1 + i + 2, ' ', 0, 0, stackB[topB - 1] * 2 + 1);
//                //������ǵ�һ����Ҳ������Ӷ����ı��
//                if (i != 0)
//                    cct_showch(76, 1 + i + 2, ' ', 14, 14, 1);
//                //������λ��
//                cct_showch(76 - stackB[topB - 1], 1 + i + 1 + 2, ' ', stackB[topB - 1], stackB[topB - 1], stackB[topB - 1] * 2 + 1);
//                Sleep(50);
//            }
//        }
//
//    }//src=='B'
//
//    if (src == 'C')
//    {
//        //�����ƶ�
//        for (int i = 0; i + topC < height; i++)
//        {
//            cct_showch(76, zhuA_Y - topC - i, ' ', 0, 0, 1); // ������Ӷ������
//            //�����λ��
//            cct_showch(76 - stackC[topC - 1], zhuA_Y - topC - i, ' ', 0, 0, stackC[topC - 1] * 2 + 1);
//
//            //������λ��
//            cct_showch(76, zhuA_Y - topC - i, ' ', 14, 14, 1);// �������Ӷ������
//            cct_showch(76 - stackC[topC - 1], zhuA_Y - topC - i - 1, 0, stackC[topC - 1], stackC[topC - 1], stackC[topC - 1] * 2 + 1);
//            cct_showch(66, 3, ' ', 0, 0, 21);//����������ʣ���
//            Sleep(50);
//        }
//
//        if (dst == 'A')
//        {
//            //�����ƶ�
//            for (int i = 0; i < (length + space)*2; i++)
//            {
//                // �����λ�õ�����ͼ��
//                cct_showch(76 - stackC[topC - 1] - i, 1, ' ', 0, 0, stackC[topC - 1] * 2 + 1);
//                // ������λ�õ�����ͼ��
//                if (i < (length + space)*2) // �����һ�ε���ʱ���ٻ�����λ��
//                {
//                    cct_showch(76 - stackC[topC - 1] - i - 1, 1, ' ', stackC[topC - 1], stackC[topC - 1], stackC[topC - 1] * 2 + 1);
//                }
//                Sleep(50);
//            }
//
//            cct_showch(76 - (length - space)*2 - stackC[topC - 1], 1, ' ', 0, 0, stackC[topC - 1] * 2 + 1);
//
//            //�����ƶ�
//            for (int i = 0; i < height - 1 - topA; i++)
//            {
//                cct_showch(12, 3, ' ', 14, 14, 1);//new!
//                //�����λ��
//                cct_showch(12 - stackC[topC - 1], 1 + i + 2, ' ', 0, 0, stackC[topC - 1] * 2 + 1);
//                //������ǵ�һ����Ҳ������Ӷ����ı��
//                if (i != 0)
//                    cct_showch(12, 1 + i + 2, ' ', 14, 14, 1);
//                //������λ��
//                cct_showch(12 - stackC[topC - 1], 1 + i + 1 + 2, ' ', stackC[topC - 1], stackC[topC - 1], stackC[topC - 1] * 2 + 1);
//                Sleep(50);
//            }
//        }
//        else if (dst == 'B')
//        {
//            //�����ƶ�
//            for (int i = 0; i < length + space; i++)
//            {
//                // �����λ�õ�����ͼ��
//                cct_showch(76 - stackC[topC - 1] - i, 1, ' ', 0, 0, stackC[topC - 1] * 2 + 1);
//                // ������λ�õ�����ͼ��
//                if (i < length + space) // �����һ�ε���ʱ���ٻ�����λ��
//                {
//                    cct_showch(76 - stackC[topC - 1] - i - 1, 1, ' ', stackC[topC - 1], stackC[topC - 1], stackC[topC - 1] * 2 + 1);
//                }
//                Sleep(50);
//            }
//
//            cct_showch(76 - length - space - stackC[topC - 1], 1, ' ', 0, 0, stackC[topC - 1] * 2 + 1);
//
//            //�����ƶ�
//            for (int i = 0; i < height - 1 - topB; i++)
//            {
//                cct_showch(44, 3, ' ', 14, 14, 1);//new!
//                //�����λ��
//                cct_showch(44 - stackC[topC - 1], 1 + i + 2, ' ', 0, 0, stackC[topC - 1] * 2 + 1);
//                //������ǵ�һ����Ҳ������Ӷ����ı��
//                if (i != 0)
//                    cct_showch(44, 1 + i + 2, ' ', 14, 14, 1);
//                //������λ��
//                cct_showch(44 - stackC[topC - 1], 1 + i + 1 + 2, ' ', stackC[topC - 1], stackC[topC - 1], stackC[topC - 1] * 2 + 1);
//                Sleep(50);
//            }
//        }
//
//    }//src=='C'
//    
//
//    cct_gotoxy(0, 35);
//    cct_setcolor(0, 7); // �ָ�Ĭ����ɫ
//}

void plate_move(int n, char src, char tmp, char dst, char choice)
{
    Sleep(1000);//��ʼ����ɺ��ͣ��һ��
    int top = 0, top_dst = 0, mid = 0, mid_dst = 0;
    int* stack = NULL;//��������ָ������stackA��B��C
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

    //�����ƶ�
    for (int i = 0; i + top < height; i++)
    {
        cct_showch(mid, zhuA_Y - top - i, ' ', 0, 0, 1);// ������Ӷ������
        //�����λ��
        cct_showch(mid - stack[top - 1], zhuA_Y - top - i, ' ', 0, 0, stack[top - 1] * 2 + 1);
        //������λ��
        cct_showch(mid, zhuA_Y - top - i, ' ', 14, 14, 1);// �������Ӷ������
        cct_showch(mid - stack[top - 1], zhuA_Y - top - i - 1, ' ', stack[top - 1], stack[top - 1], stack[top - 1] * 2 + 1);
        cct_showch(mid - length / 2 + 1, 3, ' ', 0, 0, 21);//����������ʣ���
        Sleep(50);
    }

    //�����ƶ�
    int distance = abs(dst - src) * (length + space);//�����ƶ�����
    for (int i = 0; i < distance; i++)
    {
        //�����λ�õ�����ͼ��
        cct_showch(mid - stack[top - 1] + (dst - src > 0 ? 1 : -1) * i, 1, ' ', 0, 0, stack[top - 1] * 2 + 1);
        //������λ�õ�����ͼ��
        if (i < distance)  //�����һ�ε���ʱ���ٻ�����λ��
        {
            cct_showch(mid - stack[top - 1] +(dst-src>0?1:-1)*(i+1), 1, ' ', stack[top - 1], stack[top - 1], stack[top - 1] * 2 + 1);
        }
        Sleep(50);
    }
    cct_showch(mid + (dst - src > 0 ? 1 : -1) * distance - stack[top - 1], 1, ' ', 0, 0, stack[top - 1] * 2 + 1);

    //�����ƶ�
    for (int i = 0; i < height - 1 - top_dst; i++)
    {
        cct_showch(mid_dst, 3, ' ', 14, 14, 1);
        //�����λ��
        cct_showch(mid_dst - stack[top - 1], 1 + i + 2, ' ', 0, 0, stack[top - 1] * 2 + 1);
        //������ǵ�һ����Ҳ������Ӷ����ı��
        if (i != 0)
        {
            cct_showch(mid_dst, 1 + i + 2, ' ', 14, 14, 1);
        }
        //������λ��
        cct_showch(mid_dst - stack[top - 1], 1 + i + 3, ' ', stack[top - 1], stack[top - 1], stack[top - 1] * 2 + 1);
        Sleep(50);
    }

    cct_gotoxy(0, 35);
    cct_setcolor(0, 7); // �ָ�Ĭ����ɫ
}





/***************************************************************************
  �������ƣ�hanoi
  ��    �ܣ��ݹ麯��
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
  �������ƣ�initialization
  ��    �ܣ���ʼ���Լ�����׼������
***************************************************************************/
void initialization(char choice)
{
    //ȫ����0���¿�ʼ��������һ�ε����ݻ����£�����
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


    if (choice == '4' || choice == '8')
    {
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
                //break;
                cin.clear();
                cin.ignore(65536, '\n');
            }

            cct_cls();

            cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << yanshi << endl;

            if (choice == '4') 
            {
                print_zong(choice);
                cct_gotoxy(0, A_Y + 4);
                cout << "��ʼ:  ";
                print();
                hanoi(n, src, tmp, dst, choice);
                cct_gotoxy(0, 40);
                break;
                
            }

            if (choice == '8')
            {
                print_zong(choice);
                cct_gotoxy(0, A_Y * 2 + 4);
                cout << "��ʼ:                ";
                print();
                print_cylinder();//����Ļ�ϻ�����������
                print_plate(src, n);//����ʼ���ϻ�n������
                hanoi(n, src, tmp, dst, choice);
                cct_gotoxy(0, 40);
                break;
            }

        }
        return;
    }
    
    else if (choice == '6')//ͼ�ν�-Ԥ��-����ʼ���ϻ�n������
    {
        cct_cls();
        cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��" << endl;
        print_cylinder();//����Ļ�ϻ�����������
        print_plate(src, n);//����ʼ���ϻ�n������
    }
   
    else if (choice == '7')//ͼ�ν�-Ԥ��-��һ���ƶ�
    {
        cct_cls();
        cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��" << endl;
        print_cylinder();//����Ļ�ϻ�����������
        print_plate(src, n);//����ʼ���ϻ�n������

        //���n����������һ���Ǵ���ʼ���Ƶ�Ŀ����
        //���n��ż������һ���Ǵ���ʼ���Ƶ��м���
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