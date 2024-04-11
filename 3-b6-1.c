/*2353126 ÐÅ03 ´ÞÂ¶ÎÄ*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    double a;
    printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:\n");
    scanf("%lf", &a);
    printf("´óÐ´½á¹ûÊÇ:\n");
    double b = a - (double)((int)(a / 1000000000)) * 1000000000;
    double c = b - ((int)(a / 100000000) % 10) * 100000000;
    double d = c - ((int)(a / 10000000) % 10) * 10000000;
    double e = d - ((int)(a / 1000000) % 10) * 1000000;
    double f = e - ((int)(a / 100000) % 10) * 100000;
    double g = f - ((int)(a / 10000) % 10) * 10000;
    double h = g - ((int)(a / 1000) % 10) * 1000;
    double i = h - ((int)(a / 100) % 10) * 100;
    double j = i - ((int)(a / 10) % 10) * 10;
    
    int A = (int)(a / 1000000000) % 10;//Ê°ÒÚ
    int B = (int)(a / 100000000) % 10;//ÒÚ
    int C = (int)(a / 10000000) % 10;//ÇªÍò
    int D = (int)(a / 1000000) % 10;//°ÛÍò
    int E = (int)(a / 100000) % 10;//Ê°Íò
    int F = (int)(a / 10000) % 10;//Íò
    int G = (int)(a / 1000) % 10;//Çª
    int H = (int)(a / 100) % 10;//°Û
    int I = (int)(a / 10) % 10;//Ê°
    int J = (int)b % 10;//Ô²
    int K = (int)((j + 0.002) * 10) % 10;//½Ç
    int L = (int)((j + 0.002) * 100) % 10;//·Ö

    //Ê®ÒÚ~ÒÚ
    switch (A) {
        case 0:
            break;
        case 1:
            printf("Ò¼Ê°");
            break;
        case 2:
            printf("·¡Ê°");
            break;
        case 3:
            printf("ÈþÊ°");
            break;
        case 4:
            printf("ËÁÊ°");
            break;
        case 5:
            printf("ÎéÊ°");
            break;
        case 6:
            printf("Â½Ê°");
            break;
        case 7:
            printf("ÆâÊ°");
            break;
        case 8:
            printf("°ÆÊ°");
            break;
        case 9:
            printf("¾ÁÊ°");
            break;
    }
    if (A != 0 && B == 0)
        printf("ÒÚ");

    switch (B) {
        case 0:
            break;
        case 1:
            printf("Ò¼ÒÚ");
            break;
        case 2:
            printf("·¡ÒÚ");
            break;
        case 3:
            printf("ÈþÒÚ");
            break;
        case 4:
            printf("ËÁÒÚ");
            break;
        case 5:
            printf("ÎéÒÚ");
            break;
        case 6:
            printf("Â½ÒÚ");
            break;
        case 7:
            printf("ÆâÒÚ");
            break;
        case 8:
            printf("°ÆÒÚ");
            break;
        case 9:
            printf("¾ÁÒÚ");
            break;
    }

    //Ç§Íò~Íò
    switch (C) {
        case 0:
            if ((A != 0 || B != 0) && (D != 0 || E != 0 || F != 0)) //Ç§Íò~Íò¶¼Îª0£¬²»Êä³ö¡°Áã¡±
                printf("Áã");
                break;
            if (!(A != 0 || B != 0) && (D != 0 || E != 0 || F != 0))
                break;
        case 1:
            printf("Ò¼Çª");
            break;
        case 2:
            printf("·¡Çª");
            break;
        case 3:
            printf("ÈþÇª");
            break;
        case 4:
            printf("ËÁÇª");
            break;
        case 5:
            printf("ÎéÇª");
            break;
        case 6:
            printf("Â½Çª");
            break;
        case 7:
            printf("ÆâÇª");
            break;
        case 8:
            printf("°ÆÇª");
            break;
        case 9:
            printf("¾ÁÇª");
            break;
    }
    if (C != 0 && D == 0 && E == 0 && F == 0)
        printf("Íò");

    switch (D) {
        case 0:
            if (C != 0 && (E != 0 || F != 0)) //Ç§ÍòÎ»²»Îª0£¬Ê®ÍòÎ»ºÍÍòÎ»ÖÁÉÙÓÐÒ»¸ö·Ç0
                printf("Áã");
                break;
            if (!(C != 0 && (E != 0 || F != 0)))
                break;
        case 1:
            printf("Ò¼°Û");
            break;
        case 2:
            printf("·¡°Û");
            break;
        case 3:
            printf("Èþ°Û");
            break;
        case 4:
            printf("ËÁ°Û");
            break;
        case 5:
            printf("Îé°Û");
            break;
        case 6:
            printf("Â½°Û");
            break;
        case 7:
            printf("Æâ°Û");
            break;
        case 8:
            printf("°Æ°Û");
            break;
        case 9:
            printf("¾Á°Û");
            break;
    }
    if (D != 0 && E == 0 && F == 0)
        printf("Íò");

    switch (E) {
        case 0:
            if (D != 0 && F != 0)
                printf("Áã");
                break;
            if (!(D != 0 && F != 0))
                break;
        case 1:
            printf("Ò¼Ê°");
            break;
        case 2:
            printf("·¡Ê°");
            break;
        case 3:
            printf("ÈþÊ°");
            break;
        case 4:
            printf("ËÁÊ°");
            break;
        case 5:
            printf("ÎéÊ°");
            break;
        case 6:
            printf("Â½Ê°");
            break;
        case 7:
            printf("ÆâÊ°");
            break;
        case 8:
            printf("°ÆÊ°");
            break;
        case 9:
            printf("¾ÁÊ°");
            break;
    }
    if ((D != 0 && E != 0 && F == 0) || D == 0 && E != 0 && F == 0)
        printf("Íò");

    switch (F) {
        case 0:
            break;
        case 1:
            printf("Ò¼Íò");
            break;
        case 2:
            printf("·¡Íò");
            break;
        case 3:
            printf("ÈþÍò");
            break;
        case 4:
            printf("ËÁÍò");
            break;
        case 5:
            printf("ÎéÍò");
            break;
        case 6:
            printf("Â½Íò");
            break;
        case 7:
            printf("ÆâÍò");
            break;
        case 8:
            printf("°ÆÍò");
            break;
        case 9:
            printf("¾ÁÍò");
            break;
    }

    //Ç§~Ôª
    switch (G) {
        case 0:
            if ((A != 0 || B != 0 || C != 0 || D != 0 || E != 0 || F != 0) && (H != 0 || I != 0 || J != 0))
                printf("Áã");
                break;
            if (!(A != 0 || B != 0 || C != 0 || D != 0 || E != 0 || F != 0))
                break;
        case 1:
            printf("Ò¼Çª");
            break;
        case 2:
            printf("·¡Çª");
            break;
        case 3:
            printf("ÈþÇª");
            break;
        case 4:
            printf("ËÁÇª");
            break;
        case 5:
            printf("ÎéÇª");
            break;
        case 6:
            printf("Â½Çª");
            break;
        case 7:
            printf("ÆâÇª");
            break;
        case 8:
            printf("°ÆÇª");
            break;
        case 9:
            printf("¾ÁÇª");
            break;
    }

    switch (H) {
        case 0:
            if (G != 0 && ((I != 0 && J != 0) || (I == 0 && J != 0) || (I != 0 && J == 0)))
                printf("Áã");
                break;
            if (!(G != 0 && ((I != 0 && J != 0) || (I == 0 && J != 0) || (I != 0 && J == 0))))
                break;
        case 1:
            printf("Ò¼°Û");
            break;
        case 2:
            printf("·¡°Û");
            break;
        case 3:
            printf("Èþ°Û");
            break;
        case 4:
            printf("ËÁ°Û");
            break;
        case 5:
            printf("Îé°Û");
            break;
        case 6:
            printf("Â½°Û");
            break;
        case 7:
            printf("Æâ°Û");
            break;
        case 8:
            printf("°Æ°Û");
            break;
        case 9:
            printf("¾Á°Û");
            break;
    }

    switch (I) {
        case 0:
            if (H != 0 && J != 0)
                printf("Áã");
                break;
            if (!(H != 0 && J != 0))
                break;
        case 1:
            printf("Ò¼Ê°");
            break;
        case 2:
            printf("·¡Ê°");
            break;
        case 3:
            printf("ÈþÊ°");
            break;
        case 4:
            printf("ËÁÊ°");
            break;
        case 5:
            printf("ÎéÊ°");
            break;
        case 6:
            printf("Â½Ê°");
            break;
        case 7:
            printf("ÆâÊ°");
            break;
        case 8:
            printf("°ÆÊ°");
            break;
        case 9:
            printf("¾ÁÊ°");
            break;
    }

    switch (J) {
        case 0:
            if (A == 0 && B == 0 && C == 0 && D == 0 && E == 0 && F == 0 && G == 0 && H == 0 && I == 0 && (K != 0 || L != 0))
                break;
            else if (A == 0 && B == 0 && C == 0 && D == 0 && E == 0 && F == 0 && G == 0 && H == 0 && I == 0 && K == 0 && L == 0) {
                printf("ÁãÔ²");
                break;
            }
            else {
                printf("Ô²");
                break;
            }
        case 1:
            printf("Ò¼Ô²");
            break;
        case 2:
            printf("·¡Ô²");
            break;
        case 3:
            printf("ÈþÔ²");
            break;
        case 4:
            printf("ËÁÔ²");
            break;
        case 5:
            printf("ÎéÔ²");
            break;
        case 6:
            printf("Â½Ô²");
            break;
        case 7:
            printf("ÆâÔ²");
            break;
        case 8:
            printf("°ÆÔ²");
            break;
        case 9:
            printf("¾ÁÔ²");
            break;
    }

    if (K == 0 && L == 0)
        printf("Õû");

    switch (K) {
        case 0:
            if (L != 0 && (A != 0 || B != 0 || C != 0 || D != 0 || E != 0 || F != 0 || G != 0 || H != 0 || I != 0 || J != 0))
                printf("Áã");
                break;
            if (L == 0)
                break;
        case 1:
            printf("Ò¼½Ç");
            break;
        case 2:
            printf("·¡½Ç");
            break;
        case 3:
            printf("Èþ½Ç");
            break;
        case 4:
            printf("ËÁ½Ç");
            break;
        case 5:
            printf("Îé½Ç");
            break;
        case 6:
            printf("Â½½Ç");
            break;
        case 7:
            printf("Æâ½Ç");
            break;
        case 8:
            printf("°Æ½Ç");
            break;
        case 9:
            printf("¾Á½Ç");
            break;
    }

    if (K != 0 && L == 0)
        printf("Õû");

    switch (L) {
        case 0:
            break;
        case 1:
            printf("Ò¼·Ö");
            break;
        case 2:
            printf("·¡·Ö");
            break;
        case 3:
            printf("Èþ·Ö");
            break;
        case 4:
            printf("ËÁ·Ö");
            break;
        case 5:
            printf("Îé·Ö");
            break;
        case 6:
            printf("Â½·Ö");
            break;
        case 7:
            printf("Æâ·Ö");
            break;
        case 8:
            printf("°Æ·Ö");
            break;
        case 9:
            printf("¾Á·Ö");
            break;
    }
    printf("\n");
    return 0;
}
