/*2353126 ��03 ��¶��*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int isleapyear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int total_days(int year, int month, int day) {
    int days_of_month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    days_of_month[1] = isleapyear(year) ? 29 : 28;
    int total = 0;
    for (int i = 0; i < month - 1; i++) {
        total += days_of_month[i];
    }
    total += day;
    return total;
}

int main()
{
    printf("�������꣬�£���\n");
    int year, month, day, total;
    scanf("%d %d %d", &year, &month, &day);
    if (month < 1 || month > 12) {
        printf("�������-�·ݲ���ȷ\n");
        return 0;
    }
    if (day < 1 || day > 31) {
        printf("�������-�����µĹ�ϵ�Ƿ�\n");
        return 0;
    }
    if (((year % 4 != 0) || (year % 100 == 0 && year % 400 != 0)) && day > 28) {
        printf("�������-�����µĹ�ϵ�Ƿ�\n");
        return 0;
    }
    if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && day > 29) {
        printf("�������-�����µĹ�ϵ�Ƿ�\n");
        return 0;
    }
    total = total_days(year, month, day);
    printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, total);
    return 0;
}