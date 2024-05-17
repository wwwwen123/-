/*2353126 信03 崔露文*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//可按需增加需要的头文件

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/

/***************************************************************************
  函数名称：daxie
  功    能：
***************************************************************************/
void daxie(int num, int flag_of_zero) {
    if (num == 0 && !flag_of_zero) {
        // 如果数字是0，并且flag_of_zero为假，则不进行任何操作
        return;
    }

    // 计算在chnstr中的索引位置
    int position = num * 2;

    //用一个临时字符串来存储单个中文大写数字
    char tmp[3]; //别忘了多一个放\0！
    tmp[0] = chnstr[position];
    tmp[1] = chnstr[position + 1];
    tmp[2] = '\0';

    // 将临时字符串追加到result字符串中
    strcat(result, tmp);
}

int main()
{
    /* --允许添加需要的内容 --*/
	double a;
	printf("请输入[0-100亿)之间的数字:\n");
	scanf("%lf", &a);;
	int flag_of_zero = 0;
	printf("大写结果是:\n");
	double b = a - (double)((int)(a / 1000000000)) * 1000000000;
	double c = b - ((int)(a / 100000000) % 10) * 100000000;
	double d = c - ((int)(a / 10000000) % 10) * 10000000;
	double e = d - ((int)(a / 1000000) % 10) * 1000000;
	double f = e - ((int)(a / 100000) % 10) * 100000;
	double g = f - ((int)(a / 10000) % 10) * 10000;
	double h = g - ((int)(a / 1000) % 10) * 1000;
	double i = h - ((int)(a / 100) % 10) * 100;
	double j = i - ((int)(a / 10) % 10) * 10;

	int shiyi = (int)(a / 1000000000) % 10;//拾亿
	int yi = (int)(a / 100000000) % 10;//亿
	int qianwan = (int)(a / 10000000) % 10;//仟万
	int baiwan = (int)(a / 1000000) % 10;//佰万
	int shiwan = (int)(a / 100000) % 10;//拾万
	int wan = (int)(a / 10000) % 10;//万
	int qian = (int)(a / 1000) % 10;//仟
	int bai = (int)(a / 100) % 10;//佰
	int shi = (int)(a / 10) % 10;//拾
	int yuan = (int)(b) % 10;//圆
	int jiao = (int)((j + 0.002) * 10) % 10;//角
	int fen = (int)((j + 0.002) * 100) % 10;//分


	//十亿~亿
	daxie(shiyi, flag_of_zero);
	if (shiyi != 0) {
		strcat(result,"拾");
		if (yi == 0)
			strcat(result, "亿");
	}

	daxie(yi, flag_of_zero);
	if (yi != 0)
		strcat(result, "亿");


	//千万~万
	if ((shiyi != 0 || yi != 0) && (baiwan != 0 || shiwan != 0 || wan != 0) && qianwan == 0) {//千万~万都为0，不输出“零”
		daxie(qianwan, 1);
	}
	if (!(shiyi != 0 || yi != 0) && (baiwan != 0 || shiwan != 0 || wan != 0)) {
		;
	}
	if (qianwan != 0) {
		daxie(qianwan, 0);
		strcat(result, "仟");
	}
	if (qianwan != 0 && baiwan == 0 && shiwan == 0 && wan == 0)
		strcat(result, "万");

	//百万
	if (baiwan == 0 && qianwan != 0 && (shiwan != 0 || wan != 0)) {//千万位不为0，十万位和万位至少有一个非0
		daxie(baiwan, 1);
	}
	if (!(qianwan != 0 && (shiwan != 0 || wan != 0))) {
		;
	}
	if (baiwan != 0) {
		daxie(baiwan, 0);
		strcat(result, "佰");
	}
	if (baiwan != 0 && shiwan == 0 && wan == 0)
		strcat(result, "万");

	//十万
	if (shiwan == 0 && baiwan != 0 && wan != 0) {
		daxie(shiwan, 1);
	}
	if (!(baiwan != 0 && wan != 0)) {
		;
	}
	if (shiwan != 0) {
		daxie(shiwan, 0);
		strcat(result, "拾");
	}
	if ((baiwan != 0 && shiwan != 0 && wan == 0) || baiwan == 0 && shiwan != 0 && wan == 0)
		strcat(result, "万");

	daxie(wan, flag_of_zero);
	if (wan != 0)
		strcat(result, "万");

	//千~元
	if (qian == 0 && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0
		|| shiwan != 0 || wan != 0) && (bai != 0 || shi != 0 || yuan != 0)) {
		daxie(qian, 1);
	}
	if (qian == 0 && !(shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0)) {
		;
	}
	if (qian != 0) {
		daxie(qian, 0);
		strcat(result, "仟");
	}

	//百
	if (bai == 0 && qian != 0 && (shi != 0 || yuan != 0)) {
		daxie(bai, 1);
	}
	if (bai == 0 && !(qian != 0 && (shi != 0 || yuan != 0))) {
		;
	}
	if (bai != 0) {
		daxie(bai, 0);
		strcat(result, "佰");
	}

	//十
	if (shi == 0 && bai != 0 && yuan != 0) {
		daxie(shi, 1);
	}
	if (shi == 0 && !(bai != 0 && yuan != 0)) {
		;
	}
	if (shi != 0) {
		daxie(shi, 0);
		strcat(result, "拾");
	}


	//元
	if (yuan == 0) {
		if (shiyi == 0 && yi == 0 && qianwan == 0 && baiwan == 0 && shiwan == 0
			&& wan == 0 && qian == 0 && bai == 0 && shi == 0 && (jiao != 0 || fen != 0)) {
			;
		}
		else if (shiyi == 0 && yi == 0 && qianwan == 0 && baiwan == 0 && shiwan == 0
			&& wan == 0 && qian == 0 && bai == 0 && shi == 0 && jiao == 0 && fen == 0) {
			daxie(yuan, 1);
			strcat(result, "圆");
		}
		else
			strcat(result, "圆");
	}

	else {
		daxie(yuan, 0);
		strcat(result, "圆");
	}

	if (jiao == 0 && fen == 0)
		strcat(result, "整");

	//角~分
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
		strcat(result, "角");
	}

	if (jiao != 0 && fen == 0)
		strcat(result, "整");

	daxie(fen, 0);
	if (fen != 0)
		strcat(result, "分");

	

    printf("%s\n", result);  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
    return 0;
}