/*2353126 ��03 ��¶��*/
#include <iostream>
using namespace std;
int main()
{
	int a[21] = { 0 };
	int num;//�������
	int count=0;//������������
	cout << "��������������������������20������0������������" << endl;
	cin >> num;
	if (num <= 0) 
	{
		cout << "����Ч����" << endl;
	}
	else
	{
		a[count++] = num;//�洢��һ�������Ҽ������ӣ��ʼ����������µ�һ������ʧ��
		for (int i = 1; i < 20; i++) 
		{
			cin >> num;
			if (num <= 0)
				break;
			a[count++] = num;
		}//for
		cout << "ԭ����Ϊ��" << endl;
		for (int i = 0; i < count; i++) 
		{
			cout << a[i] << " ";
		}
		cout << endl;
		cout << "������Ҫ�����������" << endl;
		cin >> num;
		//���в���
		int position = count;
		for (int i = 0; i < count; i++) {
			if (num < a[i]) {
				position = i;
				break;
			}
		}
		for (int i = count; i > position; i--) {
			a[i] = a[i - 1];//�Ӳ���㿪ʼ��ÿ��Ԫ�������һλ
		}
		a[position] = num;//�����µ���

		cout << "����������Ϊ��" << endl;
		for (int i = 0; i <= count; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
		
	return 0;
}


