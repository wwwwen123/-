/*2353126 ��03 ��¶��*/
#include<iostream>
using namespace std;
int main()
{
	int input_grade[1000];
	int count[101] = { 0 };//ÿ���ֶμ���
	cout << "������ɼ������1000������������������" << endl;
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
		cout << "����Ч����" << endl;
	else
	{
		cout << "���������Ϊ:" << endl;
		for (int j = 0; j < i && input_grade[j] >= 0; j++) {
			cout << input_grade[j] << " ";
			if (j % 10 == 9)
				cout << endl;
		}
		cout << endl;
		cout << "���������εĶ�Ӧ��ϵΪ:" << endl;
		int rank = 1;
		for (int score = 100; score >= 0; score--) {
			if (count[score] > 0) { 
				for (int k = 0; k < count[score]; k++) { // ��ÿ����������
					cout << score << " " << rank << endl;
				}
				rank += count[score]; // ������һ�ε�����, ��ǰ����������������ĸ���
			}
		}
	}//else
	return 0;
}
