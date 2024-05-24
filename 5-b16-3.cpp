/*2353126 信03 崔露文*/
#include <iostream>
#include <string>
using namespace std;

//本题按学号升序打印全部学生（string类）

//输入10个人的学号、姓名、成绩
void input(string ID[], string Name[], int Grade[])
{
	for (int i = 0; i < 10; i++)
	{
		cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
		cin >> ID[i] >> Name[i] >> Grade[i];
	}
}

//按照学号升序排序——冒泡法
void sequence(string ID[], string Name[], int Grade[])
{
	for (int i = 0; i < 9; i++)//外层循环只需要进行人数-1次
	{
		for (int j = 0; j < 9 - i; j++)//每次外层循环后，末尾的i已正确排序，不用重复参与比较
		{
			if (ID[j] > ID[j + 1])//这里没有等于，表示成绩相同的按输入原始顺序排
			{
				//换姓名
				string tmpName = Name[j];
				Name[j] = Name[j + 1];
				Name[j + 1] = tmpName;

				//换学号
				string tmpID = ID[j];
				ID[j] = ID[j + 1];
				ID[j + 1] = tmpID;

				//换成绩
				int tmpGrade = Grade[j];
				Grade[j] = Grade[j + 1];
				Grade[j + 1] = tmpGrade;
			}
		}
	}
}

//打印全部学生名单
void output(string ID[], string Name[], int Grade[])
{
	cout << endl << "全部学生(学号升序):" << endl;
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