/*2353126 ��03 ��¶��*/
#include <iostream>
#include <string>
using namespace std;

//���ⰴѧ�������ӡȫ��ѧ����string�ࣩ

//����10���˵�ѧ�š��������ɼ�
void input(string ID[], string Name[], int Grade[])
{
	for (int i = 0; i < 10; i++)
	{
		cout << "�������" << i + 1 << "���˵�ѧ�š��������ɼ�" << endl;
		cin >> ID[i] >> Name[i] >> Grade[i];
	}
}

//����ѧ���������򡪡�ð�ݷ�
void sequence(string ID[], string Name[], int Grade[])
{
	for (int i = 0; i < 9; i++)//���ѭ��ֻ��Ҫ��������-1��
	{
		for (int j = 0; j < 9 - i; j++)//ÿ�����ѭ����ĩβ��i����ȷ���򣬲����ظ�����Ƚ�
		{
			if (ID[j] > ID[j + 1])//����û�е��ڣ���ʾ�ɼ���ͬ�İ�����ԭʼ˳����
			{
				//������
				string tmpName = Name[j];
				Name[j] = Name[j + 1];
				Name[j + 1] = tmpName;

				//��ѧ��
				string tmpID = ID[j];
				ID[j] = ID[j + 1];
				ID[j + 1] = tmpID;

				//���ɼ�
				int tmpGrade = Grade[j];
				Grade[j] = Grade[j + 1];
				Grade[j + 1] = tmpGrade;
			}
		}
	}
}

//��ӡȫ��ѧ������
void output(string ID[], string Name[], int Grade[])
{
	cout << endl << "ȫ��ѧ��(ѧ������):" << endl;
	for (int i = 0; i < 10; i++)
	{
			cout << Name[i] << " " << ID[i] << " " << Grade[i] << endl;
	}
}

int main()
{
	string ID[10];
	string Name[10];
	int Grade[10];

	input(ID, Name, Grade);
	sequence(ID, Name, Grade);
	output(ID, Name, Grade);

	return 0;
}