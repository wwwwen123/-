/*2353126 信03 崔露文*/
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	double a;
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> a;
	int flag_of_zero = 0;
	cout << "大写结果是:" << endl;
	double b = a - static_cast<double>(static_cast<int>(a / 1000000000)) * 1000000000;
	double c = b - (static_cast<int>(a / 100000000) % 10) * 100000000;
	double d = c - (static_cast<int>(a / 10000000) % 10) * 10000000;
	double e = d - (static_cast<int>(a / 1000000) % 10) * 1000000;
	double f = e - (static_cast<int>(a / 100000) % 10) * 100000;
	double g = f - (static_cast<int>(a / 10000) % 10) * 10000;
	double h = g - (static_cast<int>(a / 1000) % 10) * 1000;
	double i = h - (static_cast<int>(a / 100) % 10) * 100;
	double j = i - (static_cast<int>(a / 10) % 10) * 10;

	int shiyi = static_cast<int>(a / 1000000000) % 10;//拾亿
	int yi = static_cast<int>(a / 100000000) % 10;//亿
	int qianwan = static_cast<int>(a / 10000000) % 10;//仟万
	int baiwan = static_cast<int>(a / 1000000) % 10;//佰万
	int shiwan = static_cast<int>(a / 100000) % 10;//拾万
	int wan = static_cast<int>(a / 10000) % 10;//万
	int qian = static_cast<int>(a / 1000) % 10;//仟
	int bai = static_cast<int>(a / 100) % 10;//佰
	int shi = static_cast<int>(a / 10) % 10;//拾
	int yuan = static_cast<int>(b) % 10;//圆
	int jiao = static_cast<int>((j + 0.002) * 10) % 10;//角
	int fen = static_cast<int>((j + 0.002) * 100) % 10;//分


	//十亿~亿
	daxie(shiyi,flag_of_zero);
	if (shiyi != 0) {
		cout << "拾";
		if (yi == 0)
		    cout << "亿";
	}

	daxie(yi, flag_of_zero);
	if (yi != 0) 
	    cout << "亿";


	//千万~万
	if ((shiyi != 0 || yi != 0) && (baiwan != 0 || shiwan != 0 || wan != 0) && qianwan==0) {//千万~万都为0，不输出“零”
		daxie(qianwan, 1);
	    }
	if (!(shiyi != 0 || yi != 0) && (baiwan != 0 || shiwan != 0 || wan != 0)) {
		;
	}
	if (qianwan != 0) {
		daxie(qianwan, 0);
		cout << "仟";
	}
	if (qianwan != 0 && baiwan == 0 && shiwan == 0 && wan == 0)
		cout << "万";

	//百万
	if (baiwan==0 && qianwan != 0 && (shiwan != 0 || wan != 0)) {//千万位不为0，十万位和万位至少有一个非0
		daxie(baiwan, 1);
	    }
	if (!(qianwan != 0 && (shiwan != 0 || wan != 0))) {
		;
	}
	if (baiwan != 0) {
		daxie(baiwan, 0);
		cout << "佰";
	}
	if (baiwan != 0 && shiwan == 0 && wan == 0)
		cout << "万";

	//十万
	if (shiwan==0 && baiwan != 0 && wan != 0) {
		daxie(shiwan, 1);
	}
	if (!(baiwan != 0 && wan != 0)) {
		;
	}
	if (shiwan != 0) {
		daxie(shiwan, 0);
		cout << "拾";
	}
	if ((baiwan != 0 && shiwan != 0 && wan == 0) || baiwan == 0 && shiwan != 0 && wan == 0)
		cout << "万";

	daxie(wan, flag_of_zero);
	if (wan != 0)
		cout << "万";

	//千~元
	if (qian==0 && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0
		|| shiwan != 0 || wan != 0) && (bai != 0 || shi != 0 || yuan != 0)) {
		daxie(qian, 1);
	}
	if (qian==0 && !(shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0)) {
		;
	}
	if (qian != 0) {
		daxie(qian, 0);
		cout << "仟";
	}
		
    //百
	if (bai==0 && qian != 0 && (shi != 0 || yuan != 0)) {
		daxie(bai, 1);
	}
	if (bai==0 && !(qian != 0 && (shi != 0 || yuan != 0))) {
		;
	}
	if (bai != 0) {
		daxie(bai, 0);
		cout << "佰";
	}
	
    //十
	if (shi==0 && bai != 0 && yuan != 0) {
		daxie(shi, 1);
	}
	if (shi==0 && !(bai != 0 && yuan != 0)) {
		;
	}
	if (shi != 0) {
		daxie(shi, 0);
		cout << "拾";
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
			cout << "圆";
		}
		else
			cout << "圆";
	}
	
	else {
		daxie(yuan, 0);
		cout << "圆";
	}

	if (jiao == 0 && fen == 0)
		cout << "整";

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
		cout << "角";
	}

	if (jiao != 0 && fen == 0)
		cout << "整";

	daxie(fen, 0);
	if (fen != 0)
		cout << "分";

	cout << endl;

	return 0;
}

