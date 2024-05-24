/*2353126 信03 崔露文*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//本题按成绩降序打印全部学生（成绩相同的按输入原始顺序排）

//输入10个人的学号、姓名、成绩
void input(char ID[][8], char Name[][9], int Grade[])
{
	for (int i = 0; i < 10; i++)
	{
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		scanf("%s%s%d", ID[i], Name[i], &Grade[i]);
	}
}

//按照成绩降序排序——冒泡法
void sequence(char ID[][8], char Name[][9], int Grade[])
{
	for (int i = 0; i < 9; i++)//外层循环只需要进行人数-1次
	{
		for (int j = 0; j < 9 - i; j++)//每次外层循环后，末尾的i已正确排序，不用重复参与比较
		{
			if (Grade[j] < Grade[j + 1])
				//Grade[j]比Grade[j+1]小，进行交换(降序)
				//没有等于0，表示成绩相同的按输入原始顺序排
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

//打印全部学生名单
void output(char ID[][8], char Name[][9], int Grade[])
{
	printf("\n");
	printf("全部学生(成绩降序):\n");
	for (int i = 0; i < 10; i++)
	{
			printf("%s %s %d\n", Name[i], ID[i], Grade[i]);
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