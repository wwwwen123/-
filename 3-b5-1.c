/*2353126 ��03 ��¶��*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    printf("�������꣬�£���\n");
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (b < 1 || b > 12) {
        printf("�������-�·ݲ���ȷ\n");
        return 0;
    }
    if (c < 1 || c > 31) {
        printf("�������-�����µĹ�ϵ�Ƿ�\n");
        return 0;
    }
    if (((a % 4 != 0) || (a % 100 == 0 && a % 400 != 0)) && c > 28) {
        printf("�������-�����µĹ�ϵ�Ƿ�\n");
        return 0;
    }
    if (((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)) && c > 29) {
        printf("�������-�����µĹ�ϵ�Ƿ�\n");
        return 0;
    }
    int yeah;
    if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
        yeah = 1;
    else
        yeah = 0;
    int e = 0;
    switch (b) {
        case 1:
            e = c;
            break;
        case 2:
            e = c + 31;
            break;
        case 3:
            e = c + 31 + 28 + yeah;
            break;
        case 4:
            e = c + 31 + 28 + yeah + 31;
            break;
        case 5:
            e = c + 31 + 28 + yeah + 31 + 30;
            break;
        case 6:
            e = c + 31 + 28 + yeah + 31 + 30 + 31;
            break;
        case 7:
            e = c + 31 + 28 + yeah + 31 + 30 + 31 + 30;
            break;
        case 8:
            e = c + 31 + 28 + yeah + 31 + 30 + 31 + 30 + 31;
            break;
        case 9:
            e = c + 31 + 28 + yeah + 31 + 30 + 31 + 30 + 31 + 31;
            break;
        case 10:
            e = c + 31 + 28 + yeah + 31 + 30 + 31 + 30 + 31 + 31 + 30;
            break;
        case 11:
            e = c + 31 + 28 + yeah + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
            break;
        case 12:
            e = c + 31 + 28 + yeah + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
            break;
    }
    printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c, a, e);
    return 0;
}