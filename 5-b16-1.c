/*2353126 信03 崔露文*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//本题按学号降序打印及格名单

//输入10个人的学号、姓名、成绩
void input(char ID[][8],char Name[][9],int Grade[])
{
	for (int i = 0; i < 10; i++) 
	{
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		scanf("%s%s%d", ID[i], Name[i], &Grade[i]);
	}
}

//按照学号降序排序——冒泡法
void sequence(char ID[][8], char Name[][9], int Grade[])
{
	for (int i = 0; i < 9; i++)//外层循环只需要进行人数-1次
	{
		for (int j = 0; j < 9 - i; j++)//每次外层循环后，末尾的i已正确排序，不用重复参与比较
		{
			if (strcmp(ID[j],ID[j+1])<0)
			//字符数组比较不能直接用<
			//ID[j]比ID[j+1]小，strcmp返回值小于0，进行交换(降序)
			{
				//换姓名
				char tmpName[9];
				strcpy(tmpName, Name[j]);
				strcpy(Name[j], Name[j + 1]);
				strcpy(Name[j + 1], tmpName);

				//换学号
				char tmpID[8];
				strcpy(tmpID, ID[j]);
				strcpy(ID[j], ID[j + 1]);
				strcpy(ID[j + 1], tmpID);

				//换成绩(成绩是int型，可以直接这样写)
				int tmpGrade = Grade[j];
				Grade[j] = Grade[j + 1];
				Grade[j + 1] = tmpGrade;
			}
		}
	}
}

//挑选及格者输出
void output(char ID[][8], char Name[][9], int Grade[])
{
	printf("\n");
	printf("及格名单(学号降序):\n");
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