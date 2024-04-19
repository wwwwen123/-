/*2353126 ��03 ��¶��*/
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������ݹ麯�����������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ���
				 2����print_tower֮������������в������徲̬�ֲ�����
   ----------------------------------------------------------------------------------- */

   /***************************************************************************
		�������ƣ�print_left
		��    �ܣ���ӡ����ַ���С�ַ�
		˵    ��������print_left('D','A'),���DCBA
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
		�������ƣ�print_right
		��    �ܣ���ӡС�ַ������ַ�
		˵    ������print_right('B','D')�����BCD
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
	 �������ƣ�print_tower
	 ��    �ܣ���ӡ��ĸ��
	 ���������
	 �� �� ֵ��
	 ˵    �����βΰ�������
			   ��ʾ����һ������order��ָ������/����
			   orderΪ1�������ǣ�orderΪ-1��������

			   depth����Ϊ������ʵ���벻����ô��ӡ�ո�żӵ�QAQ
   ***************************************************************************/
void print_tower(char start_ch, char end_ch, int order, int depth = 0)
{
	/* ����ʵ�֣������в������κ���ʽ��ѭ�����������徲̬�ֲ����� */
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
  �������ƣ�main
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����е�...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч��Ϊ����ѭ�����֣��������������) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();			//����������һ���ַ�
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "�����ַ����Ǵ�д��ĸ" << endl;
		return -1;
	}

	/* ��������ĸ��(�м�ΪA) */
	cout << setw((end_ch - 'A') * 2 + 1) << setfill('=') << '=' << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	cout << setw((end_ch - 'A') * 2 + 1) << setfill('=') << '=' << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower('A', end_ch, 1, 0); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ��������ĸ��(�м�ΪA) */
	cout << setw((end_ch - 'A') * 2 + 1) << setfill('=') << '=' << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	cout << setw((end_ch - 'A') * 2 + 1) << setfill('=') << '=' << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(end_ch, 'A', -1, 0); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ����������Ư�������Σ��м�ΪA�� */
	cout << setw((end_ch - 'A') * 2 + 1) << setfill('=') << '=' << endl;/* ����ĸ����������= */
	cout << "����(" << end_ch << "->A)" << endl;
	cout << setw((end_ch - 'A') * 2 + 1) << setfill('=') << '=' << endl;/* ����ĸ����������= */
	print_tower('A', end_ch, 1, 0);   //��ӡ A~�����ַ��������� 
	print_tower(end_ch-1, 'A', -1, 1);   //��ӡ A~�����ַ�-1�ĵ�����
	//ע������depth��1����������ÿһ��ǰ��һ���ո�

	cout << endl;

	return 0;
}


