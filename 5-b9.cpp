/*2353126 ��03 ��¶��*/
#include <iostream>
using namespace std;

int main()
{
	int matrix[9][9] = { 0 };
	cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;
	for (int i = 0; i < 9; i++) 
	{
		for (int j = 0; j < 9; j++) 
		{
			while (1) 
			{
				cin >> matrix[i][j];
				if (cin.fail()) {
					cout << "�����������" << i + 1 << "��" << j + 1 << "��(���о���1��ʼ����)��ֵ" << endl;
					cin.clear();
					cin.ignore(65536, '\n');
					continue;
				}
				else if (cin.good()) {
					if (matrix[i][j] < 1 || matrix[i][j]>9)
					{
						cout << "�����������" << i + 1 << "��" << j + 1 << "��(���о���1��ʼ����)��ֵ" << endl;
						continue;
					}
					else
						break;
				}
			}//while(1)
		}//for jѭ��
	}//for i ѭ��

	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {

			//���ͬһ���г����ظ����֣����������Ľ�
			for (int row = 0; row < 9; row++) {
				if (i != row && matrix[i][j] == matrix[row][j]) {
					cout << "���������Ľ�" << endl;
					return 1;
				}
			}//����е�ѭ��

			//���ͬһ���г����ظ����֣����������Ľ�
			for (int col = 0; col < 9; col++) {
				if (j != col && matrix[i][j] == matrix[i][col]) {
					cout << "���������Ľ�" << endl;
					return 1;
				}
			}//����е�ѭ��

		}
	}

	//���һ��3*3С�����г����ظ����֣����������Ľ�
	for (int r = 0; r < 9; r += 3) {
		for (int c = 0; c < 9; c += 3) {
			//������ѭ���������ÿ��3*3С����������+=3
			for (int i = r; i < r + 3; i++) {
				for (int j = c; j < c + 3; j++) {
					//������ѭ����������ÿ��С�����е�9��Ԫ��
					//ע����i=r��j=c������i=0��j=0���ʼ����д���˵���������ȷ�Ľ�Ҳ����Ϊ���������Ľ�
					//����С��r+3��c+3����֤���ڼ��ÿ��3*3��С����
					for (int x = r; x < r + 3; x++) {
						for (int y = c; y < c + 3; y++) {
							//������ѭ�����ܺ���������ͬ
							if ((i != x || j != y) && matrix[i][j] == matrix[x][y]) {
								//��ͬһ��3*3С�����Ҳ�����ͬλ�õ��������
								cout << "���������Ľ�" << endl;
								return 1;
							}
						}
					}
				}
			}
		}
	}
	cout << "�������Ľ�" << endl;
	return 0;
}