/*2353126 ��03 ��¶��*/
#include <iostream>
using namespace std;

int main()
{
	int daxie = 0, xiaoxie = 0, shuzi = 0, kongge = 0, qita = 0;
	char str[3][128];
	for (int i = 0; i < 3; i++)
	{
		cout << "�������" << i + 1 << "��" << endl;
		cin.getline(str[i], 128);
		for (int j = 0; str[i][j] != '\0'; j++)
		{
			if (str[i][j] >= 'A' && str[i][j] <= 'Z')
			{
				daxie++;
			}
			else if (str[i][j] >= 'a' && str[i][j] <= 'z')
			{
				xiaoxie++;
			}
			else if (str[i][j] >= '0' && str[i][j] <= '9')
			{
				shuzi++;
			}
			else if (str[i][j] == ' ')
			{
				kongge++;
			}
			else
			{
				qita++;
			}				
		}
	}
	cout << "��д : " << daxie << endl;
	cout << "Сд : " << xiaoxie << endl;
	cout << "���� : " << shuzi << endl;
	cout << "�ո� : " << kongge << endl;
	cout << "���� : " << qita << endl;

	return 0;
}