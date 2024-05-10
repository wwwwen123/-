/*2353126 信03 崔露文*/
#include <iostream>
using namespace std;
int main()
{
	int a[21] = { 0 };
	int num;//插入的数
	int count=0;//输入数据数量
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	cin >> num;
	if (num <= 0) 
	{
		cout << "无有效输入" << endl;
	}
	else
	{
		a[count++] = num;//存储第一个数并且计数增加（最开始忘了这个导致第一个数丢失）
		for (int i = 1; i < 20; i++) 
		{
			cin >> num;
			if (num <= 0)
				break;
			a[count++] = num;
		}//for
		cout << "原数组为：" << endl;
		for (int i = 0; i < count; i++) 
		{
			cout << a[i] << " ";
		}
		cout << endl;
		cout << "请输入要插入的正整数" << endl;
		cin >> num;
		//进行插入
		int position = count;
		for (int i = 0; i < count; i++) {
			if (num < a[i]) {
				position = i;
				break;
			}
		}
		for (int i = count; i > position; i--) {
			a[i] = a[i - 1];//从插入点开始，每个元素向后移一位
		}
		a[position] = num;//插入新的数

		cout << "插入后的数组为：" << endl;
		for (int i = 0; i <= count; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
		
	return 0;
}


