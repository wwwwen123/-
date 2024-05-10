/*2353126 ��03 ��¶��*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int step = 0;
int stackA[10] = { 0 }, stackB[10] = { 0 }, stackC[10] = { 0 };
int topA = 0, topB = 0, topC = 0;

void move(int n, char src, char dst) 
{
    //��Դ���ƿ�����
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

    //��������ӵ�Ŀ����
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
    //����stackA���飬��ӡ����A�ϵ�����
    for (int i = 0; i < 10; i++) {
        //�������ֵΪ0��Ԫ�أ��ʹ�ӡ�����ո񣨱�ʾ���λ��û�����ӣ�
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
        printf("��%4d ��(%2d): %c-->%c ", step, n, src, dst);
        move(n, src, dst);
        print();
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        step++;
        printf("��%4d ��(%2d): %c-->%c ", step, n, src, dst);
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
        printf("�����뺺ŵ���Ĳ���(1-10)\n");
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
        printf("��������ʼ��(A-C)\n");
        scanf("%c", &src);
        while (getchar() != '\n');
        if (src >= 'a' && src <= 'c')
            src -= 32;//Сдת��д
        if (src >= 'A' && src <= 'C')
            break;
    }

    while (1)
    {
        printf("������Ŀ����(A-C)\n");
        scanf("%c", &dst);
        while (getchar() != '\n');
        if (dst >= 'a' && dst <= 'c')
            dst -= 32;//Сдת��д
        if (dst == src) {
            printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", src, dst);
            continue;
        }
        if (dst >= 'A' && dst <= 'C')
            break;
    }

    tmp = 'A' + 'B' + 'C' - src - dst;

    //�����ӽ��г�ʼ����ȷ�����������ڵײ�����С�������ڶ���
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

    printf("��ʼ:                ");//16���ո�
    print();
    hanoi(n, src, tmp, dst);
    return 0;
}