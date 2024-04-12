/*2353126 信03 崔露文*/
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
			char ch    ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
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

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/

/***************************************************************************
  函数名称：menu
  功    能：输出菜单
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int menu()
{
	int choice;//初始选择0-6

	printf("1.用I、J、K、L键控制上下左右(大小写均可，边界停止)\n");
	printf("2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)\n");
	printf("3.用箭头键控制上下左右，边界停止\n");
	printf("4.用箭头键控制上下左右，边界回绕\n");
	printf("5.用I、J、K、L键控制上下左右(按左箭头不向下移动，大小写均可，边界停止)\n");
	printf("6.用I、J、K、L键控制上下左右(按左箭头不向下移动，大小写均可，边界回绕)\n");
	printf("0.退出\n");
	printf("[请选择0-6]");

	while (1) {
		choice = _getch();
		if (choice >= '0' && choice <= '6') {
			break;
		}
	}
	return choice;
}


/***************************************************************************
  函数名称：move_by_ijkl
  功    能：使用ijkl控制光标移动
  输入参数：
  返 回 值：
  说    明：
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
					printf("游戏结束，按回车键返回菜单.\n");
					while (1) {
						ch = _getch();
						if (ch == 13) {
							cls(hout);
							gotoxy(hout, 0, 0);
							return;
						}
					}
					cls(hout);
				}//if(ch=='q')的右括号

				switch (ch)
				{
					case 73:
					case 105:
						if (y > 1) {
							gotoxy(hout, x, y - 1);
							y = y - 1;//向上
						}
						break;
					case 74:
					case 106:
						if (x > 1) {
							gotoxy(hout, x - 1, y);
							x = x - 1;//向左
						}
						break;
					case 75:
					case 107:
						if (y < MAX_Y) {
							gotoxy(hout, x, y + 1);
							y = y + 1;//向下
						}
						break;
					case 76:
					case 108:
						if (x < MAX_X) {
							gotoxy(hout, x + 1, y);
							x = x + 1;//向右
						}
						break;
					case 32:
						_putch(' ');
						_putch('\b');
						break;
					default:
						break;
				}//switch-case的右括号



			}//while(ch=_getch())的右括号
		}//if (choice == 1)的右括号



		if (choice == 2) {
			while (ch = _getch())
			{
				if (ch == 81 || ch == 113) {
					gotoxy(hout, 0, 23);
					printf("游戏结束，按回车键返回菜单.\n");
					while (1) {
						ch = _getch();
						if (ch == 13) {
							cls(hout);
							gotoxy(hout, 0, 0);
							return;
						}
					}
					cls(hout);
				}//if(ch=='q')的右括号

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
							y = y - 1;//向上
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
							x = x - 1;//向左
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
							y = y + 1;//向下
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
							x = x + 1;//向右
						}
						break;
					case 32:
						_putch(' ');
						_putch('\b');
						break;
					default:
						break;
				}//switch-case的右括号

			}//while (ch = _getch())的右括号
		}//if(choiece==2)的右括号


		if (choice == 5) {
			while (ch = _getch())
			{
				if (ch == 81 || ch == 113) {
					gotoxy(hout, 0, 23);
					printf("游戏结束，按回车键返回菜单.\n");
					while (1) {
						ch = _getch();
						if (ch == 13) {
							cls(hout);
							gotoxy(hout, 0, 0);
							return;
						}
					}
					cls(hout);
				}//if(ch=='q')的右括号

				switch (ch)
				{
					case 73:
					case 105:
						if (y > 1) {
							gotoxy(hout, x, y - 1);
							y = y - 1;//向上
						}
						break;
					case 74:
					case 106:
						if (x > 1) {
							gotoxy(hout, x - 1, y);
							x = x - 1;//向左
						}
						break;
					case 75:
					case 107:
						if (y < MAX_Y) {
							gotoxy(hout, x, y + 1);
							y = y + 1;//向下
						}
						break;
					case 76:
					case 108:
						if (x < MAX_X) {
							gotoxy(hout, x + 1, y);
							x = x + 1;//向右
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
				}//switch-case的右括号
			}//while(ch=_getch())的右括号
		}//if (choice == 5)的右括号

		if (choice == 6) {
			while (ch = _getch())
			{
				if (ch == 81 || ch == 113) {
					gotoxy(hout, 0, 23);
					printf("游戏结束，按回车键返回菜单.\n");
					while (1) {
						ch = _getch();
						if (ch == 13) {
							cls(hout);
							gotoxy(hout, 0, 0);
							return;
						}
					}
					cls(hout);
				}//if(ch=='q')的右括号

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
							y = y - 1;//向上
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
							x = x - 1;//向左
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
							y = y + 1;//向下
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
							x = x + 1;//向右
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
				}//switch-case的右括号

			}//while (ch = _getch())的右括号
		}//if(choiece==6)的右括号

	}//while(1)的右括号

}//函数结束的右括号



/***************************************************************************
  函数名称：move_by_arrow
  功    能：使用←↑↓→控制光标移动
  输入参数：
  返 回 值：
  说    明：
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
				printf("游戏结束，按回车键返回菜单.\n");
				while (1) {
					ch = _getch();
					if (ch == 13) {
						cls(hout);
						gotoxy(hout, 0, 0);
						return;
					}
				}
				cls(hout);
			}//if(ch=='q')的右括号

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
				}//上下左右移动的switch-case右括号

			}//if(ch==224)的右括号
			if (ch == 32) {
				_putch(' ');
				_putch('\b');
			}

			if (ch == 'H' || ch == 'P' || ch == 'K' || ch == 'M')
			{

			}
		}//if (choice == 3)的右括号


		if (choice == 4) {
			ch = _getch();
			if (ch == 81 || ch == 113) {
				gotoxy(hout, 0, 23);
				printf("游戏结束，按回车键返回菜单.\n");
				while (1) {
					ch = _getch();
					if (ch == 13) {
						cls(hout);
						gotoxy(hout, 0, 0);
						return;
					}
				}
				cls(hout);
			}//if(ch=='q')的右括号

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
							y = y - 1;//向上
						}
						break;
					case 75:
						if (x == 1) {
							gotoxy(hout, 69, y);
							x = 69;
						}
						else if (x > 1) {
							gotoxy(hout, x - 1, y);
							x = x - 1;//向左
						}
						break;
					case 80:
						if (y == 17) {
							gotoxy(hout, x, 1);
							y = 1;
						}
						else if (y < MAX_Y) {
							gotoxy(hout, x, y + 1);
							y = y + 1;//向下
						}
						break;
					case 77:
						if (x == 69) {
							gotoxy(hout, 1, y);
							x = 1;
						}
						else if (x < MAX_X) {
							gotoxy(hout, x + 1, y);
							x = x + 1;//向右
						}
						break;
				}//switch-case的右括号

			}//if(ch==224)的右括号
			if (ch == 32) {
				_putch(' ');
				_putch('\b');
			}

			if (ch == 'H' || ch == 'P' || ch == 'K' || ch == 'M')
			{

			}
		}//if (choice == 4)的右括号
	}//while(1)的右括号
}//函数move_by_arrow的右括号




/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
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

//思考：
//1.出现了，因为上下左右箭头的ASCII码值不是单独一个，
//例如左箭头是75+224，而75对应的是K，所以按左箭头光标会向下
//2.不一定总是20个，因为是随机生成，如果在同一位置随机生成多个则看起来总数不足20




