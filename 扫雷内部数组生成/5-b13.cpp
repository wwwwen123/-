/*2353126 ��03 ��¶��*/

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

    // ��ʼ����Ϸ����
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            game[i][j] = '0'; //��ʼ��ȫΪ0����Χ��û���ף�ע�����ַ�0����������0������
        }
    }
    
    srand((unsigned)time(NULL));

    //�ŵ���
    while (mine < total_mine) 
    {
        int r = rand() % row;//�õ��кţ���Χ0~row-1
        int c = rand() % col;//�õ��кţ���Χ0~col-1
        if (game[r][c] == '*') 
        {
            continue; //���ѡ�е�λ���Ѿ��ǵ��ף�������ѡ��
        }
        game[r][c] = '*';
        mine++;

        // ������Χ���ӵ����֣��׵ĸ�����
        for (int i = r - 1; i <= r + 1; i++) 
        {
            for (int j = c - 1; j <= c + 1; j++) 
            {
                //������Χ3*3�ķ���
                if (i >= 0 && i < row && j >= 0 && j < col && game[i][j] != '*') 
                    //ȷ��i��jûԽ�磬������ط�������
                {
                    game[i][j]++; // ������Χ���ӵĵ��׼���
                }
            }
        }
    }

    //��ӡ������Ϸ���
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << game[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
