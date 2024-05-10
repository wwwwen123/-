/*2353126 信03 崔露文*/
#include <iostream>
using namespace std;

int main()
{
	int matrix[9][9] = { 0 };
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	for (int i = 0; i < 9; i++) 
	{
		for (int j = 0; j < 9; j++) 
		{
			while (1) 
			{
				cin >> matrix[i][j];
				if (cin.fail()) {
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
					cin.clear();
					cin.ignore(65536, '\n');
					continue;
				}
				else if (cin.good()) {
					if (matrix[i][j] < 1 || matrix[i][j]>9)
					{
						cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
						continue;
					}
					else
						break;
				}
			}//while(1)
		}//for j循环
	}//for i 循环

	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {

			//如果同一行中出现重复数字，则不是数独的解
			for (int row = 0; row < 9; row++) {
				if (i != row && matrix[i][j] == matrix[row][j]) {
					cout << "不是数独的解" << endl;
					return 1;
				}
			}//检查行的循环

			//如果同一列中出现重复数字，则不是数独的解
			for (int col = 0; col < 9; col++) {
				if (j != col && matrix[i][j] == matrix[i][col]) {
					cout << "不是数独的解" << endl;
					return 1;
				}
			}//检查列的循环

		}
	}

	//如果一个3*3小矩阵中出现重复数字，则不是数独的解
	for (int r = 0; r < 9; r += 3) {
		for (int c = 0; c < 9; c += 3) {
			//这两个循环用来检查每个3*3小方格，所以是+=3
			for (int i = r; i < r + 3; i++) {
				for (int j = c; j < c + 3; j++) {
					//这两个循环用来覆盖每个小方格中的9个元素
					//注意是i=r，j=c，不是i=0和j=0！最开始这里写错了导致输入正确的解也被判为不是数独的解
					//且是小于r+3和c+3，保证是在检查每个3*3的小方格
					for (int x = r; x < r + 3; x++) {
						for (int y = c; y < c + 3; y++) {
							//这两个循环功能和上两个相同
							if ((i != x || j != y) && matrix[i][j] == matrix[x][y]) {
								//在同一个3*3小方格且不是相同位置但两数相等
								cout << "不是数独的解" << endl;
								return 1;
							}
						}
					}
				}
			}
		}
	}
	cout << "是数独的解" << endl;
	return 0;
}