/*2353126 信03 崔露文*/
#include<iostream>
using namespace std;
int main()
{
	int input_grade[1000];
	int count[101] = { 0 };//每个分段计数
	cout << "请输入成绩（最多1000个），负数结束输入" << endl;
	int i = 0;
	while (cin >> input_grade[i]) {
		if (input_grade[i] < 0)
			break;
		else
			count[input_grade[i]]++;
		i++;
		if (i >= 1000)
			break;
	}

	if (input_grade[0] < 0)
		cout << "无有效输入" << endl;
	else
	{
		cout << "输入的数组为:" << endl;
		for (int j = 0; j < i && input_grade[j] >= 0; j++) {
			cout << input_grade[j] << " ";
			if (j % 10 == 9)
				cout << endl;
		}
		cout << endl;
		cout << "分数与名次的对应关系为:" << endl;
		int rank = 1;
		for (int score = 100; score >= 0; score--) {
			if (count[score] > 0) { 
				for (int k = 0; k < count[score]; k++) { // 对每个分数计数
					cout << score << " " << rank << endl;
				}
				rank += count[score]; // 计算下一次的排名, 当前排名加上这个分数的个数
			}
		}
	}//else
	return 0;
}
