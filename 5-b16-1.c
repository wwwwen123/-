/*2353126 ��03 ��¶��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//���ⰴѧ�Ž����ӡ��������

//����10���˵�ѧ�š��������ɼ�
void input(char ID[][8],char Name[][9],int Grade[])
{
	for (int i = 0; i < 10; i++) 
	{
		printf("�������%d���˵�ѧ�š��������ɼ�\n", i + 1);
		scanf("%s%s%d", ID[i], Name[i], &Grade[i]);
	}
}

//����ѧ�Ž������򡪡�ð�ݷ�
void sequence(char ID[][8], char Name[][9], int Grade[])
{
	for (int i = 0; i < 9; i++)//���ѭ��ֻ��Ҫ��������-1��
	{
		for (int j = 0; j < 9 - i; j++)//ÿ�����ѭ����ĩβ��i����ȷ���򣬲����ظ�����Ƚ�
		{
			if (strcmp(ID[j],ID[j+1])<0)
			//�ַ�����Ƚϲ���ֱ����<
			//ID[j]��ID[j+1]С��strcmp����ֵС��0�����н���(����)
			{
				//������
				char tmpName[9];
				strcpy(tmpName, Name[j]);
				strcpy(Name[j], Name[j + 1]);
				strcpy(Name[j + 1], tmpName);

				//��ѧ��
				char tmpID[8];
				strcpy(tmpID, ID[j]);
				strcpy(ID[j], ID[j + 1]);
				strcpy(ID[j + 1], tmpID);

				//���ɼ�(�ɼ���int�ͣ�����ֱ������д)
				int tmpGrade = Grade[j];
				Grade[j] = Grade[j + 1];
				Grade[j + 1] = tmpGrade;
			}
		}
	}
}

//��ѡ���������
void output(char ID[][8], char Name[][9], int Grade[])
{
	printf("\n");
	printf("��������(ѧ�Ž���):\n");
	for (int i = 0; i < 10; i++)
	{
		if (Grade[i] >= 60)
		{
			printf("%s %s %d\n", Name[i], ID[i], Grade[i]);
		}
	}
}

int main()
{
	char ID[10][8];
	char Name[10][9];
	int Grade[10];

	input(ID, Name, Grade);
	sequence(ID, Name, Grade);
	output(ID, Name, Grade);

	return 0;
}