/*2353126 ��03 ��¶��*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    double a;
    printf("������[0-100��)֮�������:\n");
    scanf("%lf", &a);
    double b = a - (double)((int)(a / 1000000000)) * 1000000000;
    double c = b - ((int)(a / 100000000) % 10) * 100000000;
    double d = c - ((int)(a / 10000000) % 10) * 10000000;
    double e = d - ((int)(a / 1000000) % 10) * 1000000;
    double f = e - ((int)(a / 100000) % 10) * 100000;
    double g = f - ((int)(a / 10000) % 10) * 10000;
    double h = g - ((int)(a / 1000) % 10) * 1000;
    double i = h - ((int)(a / 100) % 10) * 100;
    double j = i - ((int)(a / 10) % 10) * 10;
    printf("ʮ��λ : %d\n", (int)(a / 1000000000) % 10);
    printf("��λ   : %d\n", (int)(a / 100000000) % 10);
    printf("ǧ��λ : %d\n", (int)(a / 10000000) % 10);
    printf("����λ : %d\n", (int)(a / 1000000) % 10);
    printf("ʮ��λ : %d\n", (int)(a / 100000) % 10);
    printf("��λ   : %d\n", (int)(a / 10000) % 10);
    printf("ǧλ   : %d\n", (int)(a / 1000) % 10);
    printf("��λ   : %d\n", (int)(a / 100) % 10);
    printf("ʮλ   : %d\n", (int)(a / 10) % 10);
    printf("Բ     : %d\n", (int)b % 10);
    printf("��     : %d\n", (int)((j + 0.002) * 10) % 10);
    printf("��     : %d\n", (int)((j + 0.002) * 100) % 10);
    return 0;
}
