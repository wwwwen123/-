/*2353126 ��03 ��¶��*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    double a;
    printf("������[0-100��)֮�������:\n");
    scanf("%lf", &a);
    printf("��д�����:\n");
    double b = a - (double)((int)(a / 1000000000)) * 1000000000;
    double c = b - ((int)(a / 100000000) % 10) * 100000000;
    double d = c - ((int)(a / 10000000) % 10) * 10000000;
    double e = d - ((int)(a / 1000000) % 10) * 1000000;
    double f = e - ((int)(a / 100000) % 10) * 100000;
    double g = f - ((int)(a / 10000) % 10) * 10000;
    double h = g - ((int)(a / 1000) % 10) * 1000;
    double i = h - ((int)(a / 100) % 10) * 100;
    double j = i - ((int)(a / 10) % 10) * 10;
    
    int A = (int)(a / 1000000000) % 10;//ʰ��
    int B = (int)(a / 100000000) % 10;//��
    int C = (int)(a / 10000000) % 10;//Ǫ��
    int D = (int)(a / 1000000) % 10;//����
    int E = (int)(a / 100000) % 10;//ʰ��
    int F = (int)(a / 10000) % 10;//��
    int G = (int)(a / 1000) % 10;//Ǫ
    int H = (int)(a / 100) % 10;//��
    int I = (int)(a / 10) % 10;//ʰ
    int J = (int)b % 10;//Բ
    int K = (int)((j + 0.002) * 10) % 10;//��
    int L = (int)((j + 0.002) * 100) % 10;//��

    //ʮ��~��
    switch (A) {
        case 0:
            break;
        case 1:
            printf("Ҽʰ");
            break;
        case 2:
            printf("��ʰ");
            break;
        case 3:
            printf("��ʰ");
            break;
        case 4:
            printf("��ʰ");
            break;
        case 5:
            printf("��ʰ");
            break;
        case 6:
            printf("½ʰ");
            break;
        case 7:
            printf("��ʰ");
            break;
        case 8:
            printf("��ʰ");
            break;
        case 9:
            printf("��ʰ");
            break;
    }
    if (A != 0 && B == 0)
        printf("��");

    switch (B) {
        case 0:
            break;
        case 1:
            printf("Ҽ��");
            break;
        case 2:
            printf("����");
            break;
        case 3:
            printf("����");
            break;
        case 4:
            printf("����");
            break;
        case 5:
            printf("����");
            break;
        case 6:
            printf("½��");
            break;
        case 7:
            printf("����");
            break;
        case 8:
            printf("����");
            break;
        case 9:
            printf("����");
            break;
    }

    //ǧ��~��
    switch (C) {
        case 0:
            if ((A != 0 || B != 0) && (D != 0 || E != 0 || F != 0)) //ǧ��~��Ϊ0����������㡱
                printf("��");
                break;
            if (!(A != 0 || B != 0) && (D != 0 || E != 0 || F != 0))
                break;
        case 1:
            printf("ҼǪ");
            break;
        case 2:
            printf("��Ǫ");
            break;
        case 3:
            printf("��Ǫ");
            break;
        case 4:
            printf("��Ǫ");
            break;
        case 5:
            printf("��Ǫ");
            break;
        case 6:
            printf("½Ǫ");
            break;
        case 7:
            printf("��Ǫ");
            break;
        case 8:
            printf("��Ǫ");
            break;
        case 9:
            printf("��Ǫ");
            break;
    }
    if (C != 0 && D == 0 && E == 0 && F == 0)
        printf("��");

    switch (D) {
        case 0:
            if (C != 0 && (E != 0 || F != 0)) //ǧ��λ��Ϊ0��ʮ��λ����λ������һ����0
                printf("��");
                break;
            if (!(C != 0 && (E != 0 || F != 0)))
                break;
        case 1:
            printf("Ҽ��");
            break;
        case 2:
            printf("����");
            break;
        case 3:
            printf("����");
            break;
        case 4:
            printf("����");
            break;
        case 5:
            printf("���");
            break;
        case 6:
            printf("½��");
            break;
        case 7:
            printf("���");
            break;
        case 8:
            printf("�ư�");
            break;
        case 9:
            printf("����");
            break;
    }
    if (D != 0 && E == 0 && F == 0)
        printf("��");

    switch (E) {
        case 0:
            if (D != 0 && F != 0)
                printf("��");
                break;
            if (!(D != 0 && F != 0))
                break;
        case 1:
            printf("Ҽʰ");
            break;
        case 2:
            printf("��ʰ");
            break;
        case 3:
            printf("��ʰ");
            break;
        case 4:
            printf("��ʰ");
            break;
        case 5:
            printf("��ʰ");
            break;
        case 6:
            printf("½ʰ");
            break;
        case 7:
            printf("��ʰ");
            break;
        case 8:
            printf("��ʰ");
            break;
        case 9:
            printf("��ʰ");
            break;
    }
    if ((D != 0 && E != 0 && F == 0) || D == 0 && E != 0 && F == 0)
        printf("��");

    switch (F) {
        case 0:
            break;
        case 1:
            printf("Ҽ��");
            break;
        case 2:
            printf("����");
            break;
        case 3:
            printf("����");
            break;
        case 4:
            printf("����");
            break;
        case 5:
            printf("����");
            break;
        case 6:
            printf("½��");
            break;
        case 7:
            printf("����");
            break;
        case 8:
            printf("����");
            break;
        case 9:
            printf("����");
            break;
    }

    //ǧ~Ԫ
    switch (G) {
        case 0:
            if ((A != 0 || B != 0 || C != 0 || D != 0 || E != 0 || F != 0) && (H != 0 || I != 0 || J != 0))
                printf("��");
                break;
            if (!(A != 0 || B != 0 || C != 0 || D != 0 || E != 0 || F != 0))
                break;
        case 1:
            printf("ҼǪ");
            break;
        case 2:
            printf("��Ǫ");
            break;
        case 3:
            printf("��Ǫ");
            break;
        case 4:
            printf("��Ǫ");
            break;
        case 5:
            printf("��Ǫ");
            break;
        case 6:
            printf("½Ǫ");
            break;
        case 7:
            printf("��Ǫ");
            break;
        case 8:
            printf("��Ǫ");
            break;
        case 9:
            printf("��Ǫ");
            break;
    }

    switch (H) {
        case 0:
            if (G != 0 && ((I != 0 && J != 0) || (I == 0 && J != 0) || (I != 0 && J == 0)))
                printf("��");
                break;
            if (!(G != 0 && ((I != 0 && J != 0) || (I == 0 && J != 0) || (I != 0 && J == 0))))
                break;
        case 1:
            printf("Ҽ��");
            break;
        case 2:
            printf("����");
            break;
        case 3:
            printf("����");
            break;
        case 4:
            printf("����");
            break;
        case 5:
            printf("���");
            break;
        case 6:
            printf("½��");
            break;
        case 7:
            printf("���");
            break;
        case 8:
            printf("�ư�");
            break;
        case 9:
            printf("����");
            break;
    }

    switch (I) {
        case 0:
            if (H != 0 && J != 0)
                printf("��");
                break;
            if (!(H != 0 && J != 0))
                break;
        case 1:
            printf("Ҽʰ");
            break;
        case 2:
            printf("��ʰ");
            break;
        case 3:
            printf("��ʰ");
            break;
        case 4:
            printf("��ʰ");
            break;
        case 5:
            printf("��ʰ");
            break;
        case 6:
            printf("½ʰ");
            break;
        case 7:
            printf("��ʰ");
            break;
        case 8:
            printf("��ʰ");
            break;
        case 9:
            printf("��ʰ");
            break;
    }

    switch (J) {
        case 0:
            if (A == 0 && B == 0 && C == 0 && D == 0 && E == 0 && F == 0 && G == 0 && H == 0 && I == 0 && (K != 0 || L != 0))
                break;
            else if (A == 0 && B == 0 && C == 0 && D == 0 && E == 0 && F == 0 && G == 0 && H == 0 && I == 0 && K == 0 && L == 0) {
                printf("��Բ");
                break;
            }
            else {
                printf("Բ");
                break;
            }
        case 1:
            printf("ҼԲ");
            break;
        case 2:
            printf("��Բ");
            break;
        case 3:
            printf("��Բ");
            break;
        case 4:
            printf("��Բ");
            break;
        case 5:
            printf("��Բ");
            break;
        case 6:
            printf("½Բ");
            break;
        case 7:
            printf("��Բ");
            break;
        case 8:
            printf("��Բ");
            break;
        case 9:
            printf("��Բ");
            break;
    }

    if (K == 0 && L == 0)
        printf("��");

    switch (K) {
        case 0:
            if (L != 0 && (A != 0 || B != 0 || C != 0 || D != 0 || E != 0 || F != 0 || G != 0 || H != 0 || I != 0 || J != 0))
                printf("��");
                break;
            if (L == 0)
                break;
        case 1:
            printf("Ҽ��");
            break;
        case 2:
            printf("����");
            break;
        case 3:
            printf("����");
            break;
        case 4:
            printf("����");
            break;
        case 5:
            printf("���");
            break;
        case 6:
            printf("½��");
            break;
        case 7:
            printf("���");
            break;
        case 8:
            printf("�ƽ�");
            break;
        case 9:
            printf("����");
            break;
    }

    if (K != 0 && L == 0)
        printf("��");

    switch (L) {
        case 0:
            break;
        case 1:
            printf("Ҽ��");
            break;
        case 2:
            printf("����");
            break;
        case 3:
            printf("����");
            break;
        case 4:
            printf("����");
            break;
        case 5:
            printf("���");
            break;
        case 6:
            printf("½��");
            break;
        case 7:
            printf("���");
            break;
        case 8:
            printf("�Ʒ�");
            break;
        case 9:
            printf("����");
            break;
    }
    printf("\n");
    return 0;
}
