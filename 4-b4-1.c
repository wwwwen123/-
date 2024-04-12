/*2353126 ��03 ��¶��*/
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
			char ch    ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/

/***************************************************************************
  �������ƣ�menu
  ��    �ܣ�����˵�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int menu()
{
	int choice;//��ʼѡ��0-6

	printf("1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)\n");
	printf("2.��I��J��K��L��������������(��Сд���ɣ��߽����)\n");
	printf("3.�ü�ͷ�������������ң��߽�ֹͣ\n");
	printf("4.�ü�ͷ�������������ң��߽����\n");
	printf("5.��I��J��K��L��������������(�����ͷ�������ƶ�����Сд���ɣ��߽�ֹͣ)\n");
	printf("6.��I��J��K��L��������������(�����ͷ�������ƶ�����Сд���ɣ��߽����)\n");
	printf("0.�˳�\n");
	printf("[��ѡ��0-6]");

	while (1) {
		choice = _getch();
		if (choice >= '0' && choice <= '6') {
			break;
		}
	}
	return choice;
}


/***************************************************************************
  �������ƣ�move_by_ijkl
  ��    �ܣ�ʹ��ijkl���ƹ���ƶ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void move_by_ijkl(int x, int y, const HANDLE hout, int choice)
{
	int ch;
	/*const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);*/
	srand((unsigned int)(time(0)));
	init_border(hout);
	gotoxy(hout, x, y);
	while (1) {
		if (choice == 1) {
			while (ch = _getch())
			{
				if (ch == 81 || ch == 113) {
					gotoxy(hout, 0, 23);
					printf("��Ϸ���������س������ز˵�.\n");
					while (1) {
						ch = _getch();
						if (ch == 13) {
							cls(hout);
							gotoxy(hout, 0, 0);
							return;
						}
					}
					cls(hout);
				}//if(ch=='q')��������

				switch (ch)
				{
					case 73:
					case 105:
						if (y > 1) {
							gotoxy(hout, x, y - 1);
							y = y - 1;//����
						}
						break;
					case 74:
					case 106:
						if (x > 1) {
							gotoxy(hout, x - 1, y);
							x = x - 1;//����
						}
						break;
					case 75:
					case 107:
						if (y < MAX_Y) {
							gotoxy(hout, x, y + 1);
							y = y + 1;//����
						}
						break;
					case 76:
					case 108:
						if (x < MAX_X) {
							gotoxy(hout, x + 1, y);
							x = x + 1;//����
						}
						break;
					case 32:
						_putch(' ');
						_putch('\b');
						break;
					default:
						break;
				}//switch-case��������



			}//while(ch=_getch())��������
		}//if (choice == 1)��������



		if (choice == 2) {
			while (ch = _getch())
			{
				if (ch == 81 || ch == 113) {
					gotoxy(hout, 0, 23);
					printf("��Ϸ���������س������ز˵�.\n");
					while (1) {
						ch = _getch();
						if (ch == 13) {
							cls(hout);
							gotoxy(hout, 0, 0);
							return;
						}
					}
					cls(hout);
				}//if(ch=='q')��������

				switch (ch)
				{
					case 73:
					case 105:
						if (y == 1) {
							gotoxy(hout, x, 17);
							y = 17;
						}
						else if (y > 1) {
							gotoxy(hout, x, y - 1);
							y = y - 1;//����
						}
						break;
					case 74:
					case 106:
						if (x == 1) {
							gotoxy(hout, 69, y);
							x = 69;
						}
						else if (x > 1) {
							gotoxy(hout, x - 1, y);
							x = x - 1;//����
						}
						break;
					case 75:
					case 107:
						if (y == 17) {
							gotoxy(hout, x, 1);
							y = 1;
						}
						else if (y < MAX_Y) {
							gotoxy(hout, x, y + 1);
							y = y + 1;//����
						}
						break;
					case 76:
					case 108:
						if (x == 69) {
							gotoxy(hout, 1, y);
							x = 1;
						}
						else if (x < MAX_X) {
							gotoxy(hout, x + 1, y);
							x = x + 1;//����
						}
						break;
					case 32:
						_putch(' ');
						_putch('\b');
						break;
					default:
						break;
				}//switch-case��������

			}//while (ch = _getch())��������
		}//if(choiece==2)��������


		if (choice == 5) {
			while (ch = _getch())
			{
				if (ch == 81 || ch == 113) {
					gotoxy(hout, 0, 23);
					printf("��Ϸ���������س������ز˵�.\n");
					while (1) {
						ch = _getch();
						if (ch == 13) {
							cls(hout);
							gotoxy(hout, 0, 0);
							return;
						}
					}
					cls(hout);
				}//if(ch=='q')��������

				switch (ch)
				{
					case 73:
					case 105:
						if (y > 1) {
							gotoxy(hout, x, y - 1);
							y = y - 1;//����
						}
						break;
					case 74:
					case 106:
						if (x > 1) {
							gotoxy(hout, x - 1, y);
							x = x - 1;//����
						}
						break;
					case 75:
					case 107:
						if (y < MAX_Y) {
							gotoxy(hout, x, y + 1);
							y = y + 1;//����
						}
						break;
					case 76:
					case 108:
						if (x < MAX_X) {
							gotoxy(hout, x + 1, y);
							x = x + 1;//����
						}
						break;
					case 32:
						_putch(' ');
						_putch('\b');
						break;
					case 224:
						_getch();
						break;
					default:
						break;
				}//switch-case��������
			}//while(ch=_getch())��������
		}//if (choice == 5)��������

		if (choice == 6) {
			while (ch = _getch())
			{
				if (ch == 81 || ch == 113) {
					gotoxy(hout, 0, 23);
					printf("��Ϸ���������س������ز˵�.\n");
					while (1) {
						ch = _getch();
						if (ch == 13) {
							cls(hout);
							gotoxy(hout, 0, 0);
							return;
						}
					}
					cls(hout);
				}//if(ch=='q')��������

				switch (ch)
				{
					case 73:
					case 105:
						if (y == 1) {
							gotoxy(hout, x, 17);
							y = 17;
						}
						else if (y > 1) {
							gotoxy(hout, x, y - 1);
							y = y - 1;//����
						}
						break;
					case 74:
					case 106:
						if (x == 1) {
							gotoxy(hout, 69, y);
							x = 69;
						}
						else if (x > 1) {
							gotoxy(hout, x - 1, y);
							x = x - 1;//����
						}
						break;
					case 75:
					case 107:
						if (y == 17) {
							gotoxy(hout, x, 1);
							y = 1;
						}
						else if (y < MAX_Y) {
							gotoxy(hout, x, y + 1);
							y = y + 1;//����
						}
						break;
					case 76:
					case 108:
						if (x == 69) {
							gotoxy(hout, 1, y);
							x = 1;
						}
						else if (x < MAX_X) {
							gotoxy(hout, x + 1, y);
							x = x + 1;//����
						}
						break;
					case 32:
						_putch(' ');
						_putch('\b');
						break;
					case 224:
						_getch();
						break;
					default:
						break;
				}//switch-case��������

			}//while (ch = _getch())��������
		}//if(choiece==6)��������

	}//while(1)��������

}//����������������



/***************************************************************************
  �������ƣ�move_by_arrow
  ��    �ܣ�ʹ�á����������ƹ���ƶ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void move_by_arrow(int x, int y, const HANDLE hout, int choice)
{
	int ch = 0;
	/*const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);*/
	srand((unsigned int)(time(0)));
	init_border(hout);
	gotoxy(hout, x, y);
	while (1) {
		if (choice == 3) {
			ch = _getch();

			if (ch == 81 || ch == 113) {
				gotoxy(hout, 0, 23);
				printf("��Ϸ���������س������ز˵�.\n");
				while (1) {
					ch = _getch();
					if (ch == 13) {
						cls(hout);
						gotoxy(hout, 0, 0);
						return;
					}
				}
				cls(hout);
			}//if(ch=='q')��������

			if (ch == 224) {
				ch = _getch();
				switch (ch)
				{
					case 72:
						if (y > 1) {
							gotoxy(hout, x, y - 1);
							y = y - 1;
						}
						break;
					case 75:
						if (x > 1) {
							gotoxy(hout, x - 1, y);
							x = x - 1;
						}
						break;
					case 80:
						if (y < MAX_Y) {
							gotoxy(hout, x, y + 1);
							y = y + 1;
						}
						break;
					case 77:
						if (x < MAX_X) {
							gotoxy(hout, x + 1, y);
							x = x + 1;
						}
						break;
				}//���������ƶ���switch-case������

			}//if(ch==224)��������
			if (ch == 32) {
				_putch(' ');
				_putch('\b');
			}

			if (ch == 'H' || ch == 'P' || ch == 'K' || ch == 'M')
			{

			}
		}//if (choice == 3)��������


		if (choice == 4) {
			ch = _getch();
			if (ch == 81 || ch == 113) {
				gotoxy(hout, 0, 23);
				printf("��Ϸ���������س������ز˵�.\n");
				while (1) {
					ch = _getch();
					if (ch == 13) {
						cls(hout);
						gotoxy(hout, 0, 0);
						return;
					}
				}
				cls(hout);
			}//if(ch=='q')��������

			if (ch == 224) {
				ch = _getch();

				switch (ch)
				{
					case 72:
						if (y == 1) {
							gotoxy(hout, x, 17);
							y = 17;
						}
						else if (y > 1) {
							gotoxy(hout, x, y - 1);
							y = y - 1;//����
						}
						break;
					case 75:
						if (x == 1) {
							gotoxy(hout, 69, y);
							x = 69;
						}
						else if (x > 1) {
							gotoxy(hout, x - 1, y);
							x = x - 1;//����
						}
						break;
					case 80:
						if (y == 17) {
							gotoxy(hout, x, 1);
							y = 1;
						}
						else if (y < MAX_Y) {
							gotoxy(hout, x, y + 1);
							y = y + 1;//����
						}
						break;
					case 77:
						if (x == 69) {
							gotoxy(hout, 1, y);
							x = 1;
						}
						else if (x < MAX_X) {
							gotoxy(hout, x + 1, y);
							x = x + 1;//����
						}
						break;
				}//switch-case��������

			}//if(ch==224)��������
			if (ch == 32) {
				_putch(' ');
				_putch('\b');
			}

			if (ch == 'H' || ch == 'P' || ch == 'K' || ch == 'M')
			{

			}
		}//if (choice == 4)��������
	}//while(1)��������
}//����move_by_arrow��������




/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int choice;
	while (1) {
		choice = menu();
		switch (choice) {
			case '0':
				return 0;
			case '1':
				move_by_ijkl(35, 9, hout, 1);
				break;
			case '2':
				move_by_ijkl(35, 9, hout, 2);
				break;
			case '3':
				move_by_arrow(35, 9, hout, 3);
				break;
			case '4':
				move_by_arrow(35, 9, hout, 4);
				break;
			case '5':
				move_by_ijkl(35, 9, hout, 5);
				break;
			case '6':
				move_by_ijkl(35, 9, hout, 6);
				break;
			default:
				break;
		}
	}


	return 0;
}

//˼����
//1.�����ˣ���Ϊ�������Ҽ�ͷ��ASCII��ֵ���ǵ���һ����
//�������ͷ��75+224����75��Ӧ����K�����԰����ͷ��������
//2.��һ������20������Ϊ��������ɣ������ͬһλ��������ɶ����������������20




