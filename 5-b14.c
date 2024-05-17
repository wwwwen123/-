/*2353126 ��03 ��¶��*/
/*2351572 ������� 2350283 ������ 2352024 ����˶ 2251225 ����Ǭ 2352212 ����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define row 10
#define col 26
#define total_mine 50
//��const�б���

int main() 
{   
    int mine_count = 0;
    char game[row][col];
    char jianyan[row][col];
    int i, j;
    int m, n;

    for (i = 0; i < row; i++) 
    {
        for (j = 0; j < col; j++) 
        {
            jianyan[i][j] = '0';
        }
    }//��ʼ����ʱ������ַ�0����������0

    //����ǲ�����50��*
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%c ", &game[i][j]);//ע��%c�����пո�
            if (game[i][j] == '*') 
            {
                mine_count++;
            }
        }
    }
    if (mine_count != total_mine) 
    {
        printf("����1\n");
        return 0;
    }

    for (i = 0; i < row; i++) 
    {
        for (j = 0; j < col; j++) 
        {
            if (game[i][j] == '*') 
            {
                jianyan[i][j] = '*';
                for (m = i - 1; m <= i + 1; m++) 
                {
                    for (n = j - 1; n <= j + 1; n++) 
                    {
                        if (m >= 0 && m < row && n >= 0 && n < col && game[m][n] != '*')
                            jianyan[m][n]++;
                    }
                }
            }
        }
    }

    
    for (i = 0; i < row; i++) 
    {
        for (j = 0; j < col; j++) 
        {
            if (game[i][j] != jianyan[i][j]) 
            {
                printf("����2\n");
                return 0;
            }
        }
    }

    printf("��ȷ\n");
    return 0;
}
