/*2353126 信03 崔露文*/
/*2351572 王杨杰瑞 2350283 康凤轩 2352024 张哲硕 2251225 王铭乾 2352212 李昊岚*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define row 10
#define col 26
#define total_mine 50
//用const有报错

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
    }//初始化的时候设成字符0而不是数字0

    //检查是不是有50个*
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%c ", &game[i][j]);//注意%c后面有空格
            if (game[i][j] == '*') 
            {
                mine_count++;
            }
        }
    }
    if (mine_count != total_mine) 
    {
        printf("错误1\n");
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
                printf("错误2\n");
                return 0;
            }
        }
    }

    printf("正确\n");
    return 0;
}
