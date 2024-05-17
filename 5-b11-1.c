/*2353126 ��03 ��¶��*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//�ɰ���������Ҫ��ͷ�ļ�

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/

/***************************************************************************
  �������ƣ�daxie
  ��    �ܣ�
***************************************************************************/
void daxie(int num, int flag_of_zero) {
    if (num == 0 && !flag_of_zero) {
        // ���������0������flag_of_zeroΪ�٣��򲻽����κβ���
        return;
    }

    // ������chnstr�е�����λ��
    int position = num * 2;

    //��һ����ʱ�ַ������洢�������Ĵ�д����
    char tmp[3]; //�����˶�һ����\0��
    tmp[0] = chnstr[position];
    tmp[1] = chnstr[position + 1];
    tmp[2] = '\0';

    // ����ʱ�ַ���׷�ӵ�result�ַ�����
    strcat(result, tmp);
}

int main()
{
    /* --���������Ҫ������ --*/
	double a;
	printf("������[0-100��)֮�������:\n");
	scanf("%lf", &a);;
	int flag_of_zero = 0;
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

	int shiyi = (int)(a / 1000000000) % 10;//ʰ��
	int yi = (int)(a / 100000000) % 10;//��
	int qianwan = (int)(a / 10000000) % 10;//Ǫ��
	int baiwan = (int)(a / 1000000) % 10;//����
	int shiwan = (int)(a / 100000) % 10;//ʰ��
	int wan = (int)(a / 10000) % 10;//��
	int qian = (int)(a / 1000) % 10;//Ǫ
	int bai = (int)(a / 100) % 10;//��
	int shi = (int)(a / 10) % 10;//ʰ
	int yuan = (int)(b) % 10;//Բ
	int jiao = (int)((j + 0.002) * 10) % 10;//��
	int fen = (int)((j + 0.002) * 100) % 10;//��


	//ʮ��~��
	daxie(shiyi, flag_of_zero);
	if (shiyi != 0) {
		strcat(result,"ʰ");
		if (yi == 0)
			strcat(result, "��");
	}

	daxie(yi, flag_of_zero);
	if (yi != 0)
		strcat(result, "��");


	//ǧ��~��
	if ((shiyi != 0 || yi != 0) && (baiwan != 0 || shiwan != 0 || wan != 0) && qianwan == 0) {//ǧ��~��Ϊ0����������㡱
		daxie(qianwan, 1);
	}
	if (!(shiyi != 0 || yi != 0) && (baiwan != 0 || shiwan != 0 || wan != 0)) {
		;
	}
	if (qianwan != 0) {
		daxie(qianwan, 0);
		strcat(result, "Ǫ");
	}
	if (qianwan != 0 && baiwan == 0 && shiwan == 0 && wan == 0)
		strcat(result, "��");

	//����
	if (baiwan == 0 && qianwan != 0 && (shiwan != 0 || wan != 0)) {//ǧ��λ��Ϊ0��ʮ��λ����λ������һ����0
		daxie(baiwan, 1);
	}
	if (!(qianwan != 0 && (shiwan != 0 || wan != 0))) {
		;
	}
	if (baiwan != 0) {
		daxie(baiwan, 0);
		strcat(result, "��");
	}
	if (baiwan != 0 && shiwan == 0 && wan == 0)
		strcat(result, "��");

	//ʮ��
	if (shiwan == 0 && baiwan != 0 && wan != 0) {
		daxie(shiwan, 1);
	}
	if (!(baiwan != 0 && wan != 0)) {
		;
	}
	if (shiwan != 0) {
		daxie(shiwan, 0);
		strcat(result, "ʰ");
	}
	if ((baiwan != 0 && shiwan != 0 && wan == 0) || baiwan == 0 && shiwan != 0 && wan == 0)
		strcat(result, "��");

	daxie(wan, flag_of_zero);
	if (wan != 0)
		strcat(result, "��");

	//ǧ~Ԫ
	if (qian == 0 && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0
		|| shiwan != 0 || wan != 0) && (bai != 0 || shi != 0 || yuan != 0)) {
		daxie(qian, 1);
	}
	if (qian == 0 && !(shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0)) {
		;
	}
	if (qian != 0) {
		daxie(qian, 0);
		strcat(result, "Ǫ");
	}

	//��
	if (bai == 0 && qian != 0 && (shi != 0 || yuan != 0)) {
		daxie(bai, 1);
	}
	if (bai == 0 && !(qian != 0 && (shi != 0 || yuan != 0))) {
		;
	}
	if (bai != 0) {
		daxie(bai, 0);
		strcat(result, "��");
	}

	//ʮ
	if (shi == 0 && bai != 0 && yuan != 0) {
		daxie(shi, 1);
	}
	if (shi == 0 && !(bai != 0 && yuan != 0)) {
		;
	}
	if (shi != 0) {
		daxie(shi, 0);
		strcat(result, "ʰ");
	}


	//Ԫ
	if (yuan == 0) {
		if (shiyi == 0 && yi == 0 && qianwan == 0 && baiwan == 0 && shiwan == 0
			&& wan == 0 && qian == 0 && bai == 0 && shi == 0 && (jiao != 0 || fen != 0)) {
			;
		}
		else if (shiyi == 0 && yi == 0 && qianwan == 0 && baiwan == 0 && shiwan == 0
			&& wan == 0 && qian == 0 && bai == 0 && shi == 0 && jiao == 0 && fen == 0) {
			daxie(yuan, 1);
			strcat(result, "Բ");
		}
		else
			strcat(result, "Բ");
	}

	else {
		daxie(yuan, 0);
		strcat(result, "Բ");
	}

	if (jiao == 0 && fen == 0)
		strcat(result, "��");

	//��~��
	if (jiao == 0) {
		if (fen != 0 && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0
			|| shiwan != 0 || wan != 0 || qian != 0 || bai != 0 || shi != 0 || yuan != 0)) {
			daxie(jiao, 1);
		}
		if (fen == 0) {
			;
		}
	}
	else {
		daxie(jiao, 0);
		strcat(result, "��");
	}

	if (jiao != 0 && fen == 0)
		strcat(result, "��");

	daxie(fen, 0);
	if (fen != 0)
		strcat(result, "��");

	

    printf("%s\n", result);  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
    return 0;
}