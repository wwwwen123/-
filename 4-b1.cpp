/*2353126 ��03 ��¶��*/
#include <iostream>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/***************************************************************************
  �������ƣ�
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		default:
			cout << "error";
			break;
	}
}

/* �ɸ�����Ҫ�Զ�����������(Ҳ���Բ�����) */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	double a;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> a;
	int flag_of_zero = 0;
	cout << "��д�����:" << endl;
	double b = a - static_cast<double>(static_cast<int>(a / 1000000000)) * 1000000000;
	double c = b - (static_cast<int>(a / 100000000) % 10) * 100000000;
	double d = c - (static_cast<int>(a / 10000000) % 10) * 10000000;
	double e = d - (static_cast<int>(a / 1000000) % 10) * 1000000;
	double f = e - (static_cast<int>(a / 100000) % 10) * 100000;
	double g = f - (static_cast<int>(a / 10000) % 10) * 10000;
	double h = g - (static_cast<int>(a / 1000) % 10) * 1000;
	double i = h - (static_cast<int>(a / 100) % 10) * 100;
	double j = i - (static_cast<int>(a / 10) % 10) * 10;

	int shiyi = static_cast<int>(a / 1000000000) % 10;//ʰ��
	int yi = static_cast<int>(a / 100000000) % 10;//��
	int qianwan = static_cast<int>(a / 10000000) % 10;//Ǫ��
	int baiwan = static_cast<int>(a / 1000000) % 10;//����
	int shiwan = static_cast<int>(a / 100000) % 10;//ʰ��
	int wan = static_cast<int>(a / 10000) % 10;//��
	int qian = static_cast<int>(a / 1000) % 10;//Ǫ
	int bai = static_cast<int>(a / 100) % 10;//��
	int shi = static_cast<int>(a / 10) % 10;//ʰ
	int yuan = static_cast<int>(b) % 10;//Բ
	int jiao = static_cast<int>((j + 0.002) * 10) % 10;//��
	int fen = static_cast<int>((j + 0.002) * 100) % 10;//��


	//ʮ��~��
	daxie(shiyi,flag_of_zero);
	if (shiyi != 0) {
		cout << "ʰ";
		if (yi == 0)
		    cout << "��";
	}

	daxie(yi, flag_of_zero);
	if (yi != 0) 
	    cout << "��";


	//ǧ��~��
	if ((shiyi != 0 || yi != 0) && (baiwan != 0 || shiwan != 0 || wan != 0) && qianwan==0) {//ǧ��~��Ϊ0����������㡱
		daxie(qianwan, 1);
	    }
	if (!(shiyi != 0 || yi != 0) && (baiwan != 0 || shiwan != 0 || wan != 0)) {
		;
	}
	if (qianwan != 0) {
		daxie(qianwan, 0);
		cout << "Ǫ";
	}
	if (qianwan != 0 && baiwan == 0 && shiwan == 0 && wan == 0)
		cout << "��";

	//����
	if (baiwan==0 && qianwan != 0 && (shiwan != 0 || wan != 0)) {//ǧ��λ��Ϊ0��ʮ��λ����λ������һ����0
		daxie(baiwan, 1);
	    }
	if (!(qianwan != 0 && (shiwan != 0 || wan != 0))) {
		;
	}
	if (baiwan != 0) {
		daxie(baiwan, 0);
		cout << "��";
	}
	if (baiwan != 0 && shiwan == 0 && wan == 0)
		cout << "��";

	//ʮ��
	if (shiwan==0 && baiwan != 0 && wan != 0) {
		daxie(shiwan, 1);
	}
	if (!(baiwan != 0 && wan != 0)) {
		;
	}
	if (shiwan != 0) {
		daxie(shiwan, 0);
		cout << "ʰ";
	}
	if ((baiwan != 0 && shiwan != 0 && wan == 0) || baiwan == 0 && shiwan != 0 && wan == 0)
		cout << "��";

	daxie(wan, flag_of_zero);
	if (wan != 0)
		cout << "��";

	//ǧ~Ԫ
	if (qian==0 && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0
		|| shiwan != 0 || wan != 0) && (bai != 0 || shi != 0 || yuan != 0)) {
		daxie(qian, 1);
	}
	if (qian==0 && !(shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0)) {
		;
	}
	if (qian != 0) {
		daxie(qian, 0);
		cout << "Ǫ";
	}
		
    //��
	if (bai==0 && qian != 0 && (shi != 0 || yuan != 0)) {
		daxie(bai, 1);
	}
	if (bai==0 && !(qian != 0 && (shi != 0 || yuan != 0))) {
		;
	}
	if (bai != 0) {
		daxie(bai, 0);
		cout << "��";
	}
	
    //ʮ
	if (shi==0 && bai != 0 && yuan != 0) {
		daxie(shi, 1);
	}
	if (shi==0 && !(bai != 0 && yuan != 0)) {
		;
	}
	if (shi != 0) {
		daxie(shi, 0);
		cout << "ʰ";
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
			cout << "Բ";
		}
		else
			cout << "Բ";
	}
	
	else {
		daxie(yuan, 0);
		cout << "Բ";
	}

	if (jiao == 0 && fen == 0)
		cout << "��";

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
		cout << "��";
	}

	if (jiao != 0 && fen == 0)
		cout << "��";

	daxie(fen, 0);
	if (fen != 0)
		cout << "��";

	cout << endl;

	return 0;
}

