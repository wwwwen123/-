/*2353126 ��03 ��¶��*/
#pragma once

/* ------------------------------------------------------------------------------------------------------

     ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ------------------------------------------------------------------------------------------------------ */

char menu(void);//�˵�
void delay(void);//������ʱ
void move(int n, char src, char dst);
void print(void);
void print_heng(int n, char src, char tmp, char dst, char choice);//�������
void print_zong(char choice);//�������
void print_cylinder(void);//����Ļ�ϻ�����������
void print_plate(char src, int n);//����ʼ���ϻ�n������
void plate_move(int n, char src, char tmp, char dst, char choice);//�����ƶ�
void hanoi(int n, char src, char tmp, char dst, char choice);//�ݹ麯��
void initialization(char choice);//��ʼ��+׼������


