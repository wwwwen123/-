/*2353126 ��03 ��¶��*/
/* ----------------------------------------------------------------------------------

	 ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

	 ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include"cmd_console_tools.h"
#include"hanoi.h"
using namespace std;
   
int main()
{
	/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	cct_setconsoleborder(120, 40, 120, 9000);

	while (1)
	{
		const char choice = menu();
		switch (choice)
		{
			case '0':
				return 0;

			case '1':
			case '2':
			case '3':
			case '4':
				initialization(choice);
				break;
			case '5':
				initialization(choice);
				cct_cls();
				print_cylinder();
				break;				
			case '6':
			case '7':
			case '8':
				initialization(choice);
				break;
			default:
				break;

		}

		cout << endl;
		cout << "���س�������" << endl;

		while (1)
		{
			int ch = _getch();
			if (ch == 13)
			{
				cct_cls();
				break;
			}

		}
	}
	
	return 0;
}

