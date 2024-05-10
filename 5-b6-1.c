/*2353126 信03 崔露文*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int step = 0;
int stackA[10] = { 0 }, stackB[10] = { 0 }, stackC[10] = { 0 };
int topA = 0, topB = 0, topC = 0;

void move(int n, char src, char dst) 
{
    //从源柱移开盘子
    switch(src) 
    {
        case 'A':
            stackA[--topA] = 0;
            break;
        case 'B':
            stackB[--topB] = 0;
            break;
        case 'C':
            stackC[--topC] = 0;
            break;
        default:
            break;
    }

    //将盘子添加到目标柱
    switch (dst)
    {
        case 'A':
            stackA[topA++] = n;
            break;
        case 'B':
            stackB[topB++] = n;
            break;
        case 'C':
            stackC[topC++] = n;
            break;
        default:
            break;
    }

}

void print()
{
    printf("A:");
    //遍历stackA数组，打印柱子A上的盘子
    for (int i = 0; i < 10; i++) {
        //如果遇到值为0的元素，就打印两个空格（表示这个位置没有盘子）
        if (stackA[i] == 0) {
            printf("  ");
        }
        else {

            printf("%2d", stackA[i]);
        }
    }
 
    printf(" B:");
    for (int i = 0; i < 10; i++) {
        if (stackB[i] == 0) {
            printf("  ");
        }
        else {
            printf("%2d", stackB[i]);
        }
    }

    printf(" C:");
    for (int i = 0; i < 10; i++) {
        if (stackC[i] == 0) {
            printf("  ");
        }
        else {
            printf("%2d", stackC[i]);
        }
    }

    printf("\n");
}

void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        step++;
        printf("第%4d 步(%2d): %c-->%c ", step, n, src, dst);
        move(n, src, dst);
        print();
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        step++;
        printf("第%4d 步(%2d): %c-->%c ", step, n, src, dst);
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
        printf("请输入汉诺塔的层数(1-10)\n");
        scanf("%d", &n);
        if (n < 1 || n>10) {
            while (getchar() != '\n');
            continue;
        }
        else {
            while (getchar() != '\n');
            break;
        }
    }

    while (1)
    {
        printf("请输入起始柱(A-C)\n");
        scanf("%c", &src);
        while (getchar() != '\n');
        if (src >= 'a' && src <= 'c')
            src -= 32;//小写转大写
        if (src >= 'A' && src <= 'C')
            break;
    }

    while (1)
    {
        printf("请输入目标柱(A-C)\n");
        scanf("%c", &dst);
        while (getchar() != '\n');
        if (dst >= 'a' && dst <= 'c')
            dst -= 32;//小写转大写
        if (dst == src) {
            printf("目标柱(%c)不能与起始柱(%c)相同\n", src, dst);
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
                stackA[i] = n - i;
                topA = n;
                break;
            case 'B':
                stackB[i] = n - i;
                topB = n;
                break;
            case 'C':
                stackC[i] = n - i;
                topC = n;
                break;
        }
    }

    printf("初始:                ");//16个空格
    print();
    hanoi(n, src, tmp, dst);
    return 0;
}