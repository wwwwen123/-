/*2353126 ��03 ��¶��*/
#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?"; //�� 15 ��Ӣ�ķ���


//����������ָ��ASCII��Χ�ڵ�����ַ��ĺ���
char generate_char(int minAscii, int maxAscii)
{
	return static_cast<char>(minAscii + rand() % (maxAscii - minAscii + 1));
	//��rand()ȡ���������ȡģ��ʹ������0~(maxAscii - minAscii)
	//Ȼ�����minAscii��ʹ���������minAscii~maxAscii
}


//������������ĺ���
void generate_password(int len, int daxie, int xiaoxie, int shuzi, int qita)
{	
	char password[17];//�����Ϊ16λ����1λ��β0
	int num = 0;
	//��Ӵ�д
	for (int i = 0; i < daxie; i++, num++)
	{
		password[num] = generate_char('A', 'Z');
	}
	//���Сд
	for (int i = 0; i < xiaoxie; i++, num++)
	{
		password[num] = generate_char('a', 'z');
	}
	//�������
	for (int i = 0; i < shuzi; i++, num++)
	{
		password[num] = generate_char('0', '9');
	}
	//��������ַ�
	for (int i = 0; i < qita; i++, num++) {
		password[num] = other[rand() % (sizeof(other) - 1)];
	}
	//�������û�ﵽlen�������������������Դﵽָ������
	while (num < len)
	{
		int type = rand() % 4;
		switch (type)
		{
			case 0://�Ӵ�д��ĸ
				password[num++] = generate_char('A', 'Z');
				break;
			case 1://��Сд��ĸ
				password[num++] = generate_char('a', 'z');
				break;
			case 2://������
				password[num++] = generate_char('0', '9');
				break;
			case 3://�������ַ�
				password[num++] = other[rand() % (sizeof(other) - 1)];
				break;
		}
	}

	//����������Ԫ��˳��
	//���û����һ������ôÿ�����붼�Ǵ�д��ĸ-Сд��ĸ-����-�����ַ������Ĺ̶�˳��
	for (int i = 0; i < len; i++) 
	{
		int suiji = rand() % len;//ѡ�������е����λ��
		char tmp = password[i];
		password[i] = password[suiji];
		password[suiji] = tmp;
	}

	password[num] = '\0';//������Ҫ��β0

	cout << password << endl;
}


int main()
{
	int len = 0, daxie = 0, xiaoxie = 0, shuzi = 0, qita = 0;
	cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;
	cin >> len >> daxie >> xiaoxie >> shuzi >> qita;

	//���������
	if (cin.fail())
	{
		cout << "����Ƿ�" << endl;
		return 0;
	}
	if (len < 12 || len>16)
	{
		cout << "���볤��[" << len << "]����ȷ" << endl;
		return 0;
	}
	if (daxie < 2)
	{
		cout << "��д��ĸ����[" << daxie << "]����ȷ" << endl;
		return 0;
	}
	if (xiaoxie < 2)
	{
		cout << "Сд��ĸ����[" << xiaoxie << "]����ȷ" << endl;
		return 0;
	}
	if (shuzi < 2)
	{
		cout << "���ָ���[" << shuzi << "]����ȷ" << endl;
		return 0;
	}
	if (qita < 2)
	{
		cout << "�������Ÿ���[" << qita << "]����ȷ" << endl;
		return 0;
	}
	if (daxie + xiaoxie + shuzi + qita > len)
	{
		cout << "�����ַ�����֮��[" << daxie << "+" << xiaoxie << "+" << shuzi << "+" << qita << "]���������볤��[" << len << "]" << endl;
		return 0;
	}

	//�����������
	cout << len << " " << daxie << " " << xiaoxie << " " << shuzi << " " << qita << endl;

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; i++)//����10������
	{
		generate_password(len, daxie, xiaoxie, shuzi, qita);
	}

	return 0;
}