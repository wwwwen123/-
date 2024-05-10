/*2353126 信03 崔露文*/
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
    printf("请输入年，月，日\n");
    int year, month, day, total;
    scanf("%d %d %d", &year, &month, &day);
    if (month < 1 || month > 12) {
        printf("输入错误-月份不正确\n");
        return 0;
    }
    if (day < 1 || day > 31) {
        printf("输入错误-日与月的关系非法\n");
        return 0;
    }
    if (((year % 4 != 0) || (year % 100 == 0 && year % 400 != 0)) && day > 28) {
        printf("输入错误-日与月的关系非法\n");
        return 0;
    }
    if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && day > 29) {
        printf("输入错误-日与月的关系非法\n");
        return 0;
    }
    total = total_days(year, month, day);
    printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, total);
    return 0;
}