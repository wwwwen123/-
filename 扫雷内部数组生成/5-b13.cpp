/*2353126 信03 崔露文*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int row = 10;
    const int col = 26;
    const int total_mine = 50;
    char game[row][col];
    int mine = 0;

    // 初始化游戏区域
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            game[i][j] = '0'; //初始化全为0，周围都没有雷（注意是字符0而不是数字0！！）
        }
    }
    
    srand((unsigned)time(NULL));

    //放地雷
    while (mine < total_mine) 
    {
        int r = rand() % row;//得到行号，范围0~row-1
        int c = rand() % col;//得到列号，范围0~col-1
        if (game[r][c] == '*') 
        {
            continue; //如果选中的位置已经是地雷，则重新选择
        }
        game[r][c] = '*';
        mine++;

        // 更新周围格子的数字（雷的个数）
        for (int i = r - 1; i <= r + 1; i++) 
        {
            for (int j = c - 1; j <= c + 1; j++) 
            {
                //遍历周围3*3的方块
                if (i >= 0 && i < row && j >= 0 && j < col && game[i][j] != '*') 
                    //确保i和j没越界，且这个地方不是雷
                {
                    game[i][j]++; // 更新周围格子的地雷计数
                }
            }
        }
    }

    //打印整个游戏板块
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << game[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
