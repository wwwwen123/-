/*2353126 信03 崔露文*/
#include <iostream>
#include <iomanip>
using namespace std;

int step = 0;
int stack[3][10] = { 0 };
int top[3] = { 0 };

void move(int n, char src, char dst)
{
    //从源柱移开盘子
    switch (src)
    {
        case 'A':
            stack[0][--top[0]] = 0;
            break;
        case 'B':
            stack[1][--top[1]] = 0;
            break;
        case 'C':
            stack[2][--top[2]] = 0;
            break;
        default:
            break;
    }

    //将盘子添加到目标柱
    switch (dst)
    {
        case 'A':
            stack[0][top[0]++] = n;
            break;
        case 'B':
            stack[1][top[1]++] = n;
            break;
        case 'C':
            stack[2][top[2]++] = n;
            break;
        default:
            break;
    }

}

void print()
{
    cout << "A:";
    //遍历stackA数组，打印柱子A上的盘子
    for (int i = 0; i < 10; i++) {
        //如果遇到值为0的元素，就打印两个空格（表示这个位置没有盘子）
        if (stack[0][i] == 0) {
            cout << "  ";
        }
        else {
            cout << setiosflags(ios::right) << setw(2) << stack[0][i];
        }
    }

    cout << " B:";
    for (int i = 0; i < 10; i++) {
        if (stack[1][i] == 0) {
            cout << "  ";
        }
        else {
            cout << setiosflags(ios::right) << setw(2) << stack[1][i];
        }
    }

    cout << " C:";
    for (int i = 0; i < 10; i++) {
        if (stack[2][i] == 0) {
            cout << "  ";
        }
        else {
            cout << setiosflags(ios::right) << setw(2) << stack[2][i];
        }
    }

    cout << endl;
}

void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        step++;
        cout << "第" << setiosflags(ios::right) << setw(4) << step << " 步("
             << setw(2) << 1 << "): " << src << "-->" << dst << " ";
        move(n, src, dst);
        print();
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        step++;
        cout << "第" << setiosflags(ios::right) << setw(4) << step << " 步("
             << setw(2) << n << "): " << src << "-->" << dst << " ";
        move(n, src, dst);
        print();
        hanoi(n - 1, tmp, src, dst);
        }
    }



int main()
{
    int n;
    char src, tmp, dst;

    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        if (n < 1 || n>10) {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        else {
            cin.clear();
            cin.ignore(65536, '\n');
            break;
        }
    }

    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        cin.ignore(65536, '\n');
        if (src >= 'a' && src <= 'c')
            src -= 32;//小写转大写
        if (src >= 'A' && src <= 'C')
            break;
    }

    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        cin.ignore(65536, '\n');
        if (dst >= 'a' && dst <= 'c')
            dst -= 32;//小写转大写
        if (dst == src) {
            cout << "目标柱(" << src << ")不能与起始柱(" << dst << ")相同" << endl;
            continue;
        }
        if (dst >= 'A' && dst <= 'C')
            break;
    }

    tmp = 'A' + 'B' + 'C' - src - dst;

    //对柱子进行初始化，确保最大的盘子在底部，最小的盘子在顶部
    for (int i = 0; i < n; i++)
    {
        switch (src)
        {
            case 'A':
                stack[0][i] = n - i;
                top[0] = n;
                break;
            case 'B':
                stack[1][i] = n - i;
                top[1] = n;
                break;
            case 'C':
                stack[2][i] = n - i;
                top[2] = n;
                break;
        }
    }

    cout << "初始:                ";//16个空格
    print();
    hanoi(n, src, tmp, dst);
    return 0;
}