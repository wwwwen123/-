/*2353126 ��03 ��¶��*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int input_grade[1000];
	int count[101] = { 0 };//ÿ���ֶμ���
	printf("������ɼ������1000������������������\n");
	int i = 0;
	while (scanf("%d", &input_grade[i])) {
		if (input_grade[i] < 0)
			break;
		else
			count[input_grade[i]]++;
		i++;
		if (i >= 1000)
			break;
	}
	
	if (input_grade[0] < 0)
		printf("����Ч����\n");
	else
	{
		printf("���������Ϊ:\n");
		for (int j = 0; j < i && input_grade[j] >= 0; j++) {
			printf("%d ", input_grade[j]);
			if (j % 10 == 9) 
				printf("\n");
		}
		printf("\n");
		printf("�����������Ķ�Ӧ��ϵΪ:\n");
		for (int j = 100; j >= 0; j--) {
			if (count[j] > 0) {
				printf("%d %d\n", j, count[j]);
			}
		}
	}
	return 0;
}

