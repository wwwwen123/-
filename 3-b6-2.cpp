/*2353126 ��03 ��¶��*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double a;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> a;
	cout << "��д�����:" << endl;

	cout << setprecision(11);
	double b = a - static_cast<double>(static_cast<int>(a / 1000000000)) * 1000000000;
	double c = b - (static_cast<int>(a / 100000000) % 10) * 100000000;
	double d = c - (static_cast<int>(a / 10000000) % 10) * 10000000;
	double e = d - (static_cast<int>(a / 1000000) % 10) * 1000000;
	double f = e - (static_cast<int>(a / 100000) % 10) * 100000;
	double g = f - (static_cast<int>(a / 10000) % 10) * 10000;
	double h = g - (static_cast<int>(a / 1000) % 10) * 1000;
	double i = h - (static_cast<int>(a / 100) % 10) * 100;
	double j = i - (static_cast<int>(a / 10) % 10) * 10;

	int A = static_cast<int>(a / 1000000000) % 10;//ʰ��
	int B = static_cast<int>(a / 100000000) % 10;//��
	int C = static_cast<int>(a / 10000000) % 10;//Ǫ��
	int D = static_cast<int>(a / 1000000) % 10;//����
	int E = static_cast<int>(a / 100000) % 10;//ʰ��
	int F = static_cast<int>(a / 10000) % 10;//��
	int G = static_cast<int>(a / 1000) % 10;//Ǫ
	int H = static_cast<int>(a / 100) % 10;//��
	int I = static_cast<int>(a / 10) % 10;//ʰ
	int J = static_cast<int>(b) % 10;//Բ
	int K = static_cast<int>((j + 0.002) * 10) % 10;//��
	int L = static_cast<int>((j + 0.002) * 100) % 10;//��

	//ʮ��~��
	switch (A) {
		case 0:
			break;
		case 1:
			cout << "Ҽʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 9:
			cout << "��ʰ";
			break;
	}
	if (A != 0 && B == 0)
		cout << "��";

	switch (B) {
		case 0:
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "����";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "����";
			break;
		case 8:
			cout << "����";
			break;
		case 9:
			cout << "����";
			break;
	}

	//ǧ��~��
	switch (C) {
		case 0:
			if ((A != 0 || B != 0) && (D != 0 || E != 0 || F != 0)) //ǧ��~��Ϊ0����������㡱
				cout << "��";
			    break;
			if (!(A != 0 || B != 0) && (D != 0 || E != 0 || F != 0))
				break;
		case 1:
			cout << "ҼǪ";
			break;
		case 2:
			cout << "��Ǫ";
			break;
		case 3:
			cout << "��Ǫ";
			break;
		case 4:
			cout << "��Ǫ";
			break;
		case 5:
			cout << "��Ǫ";
			break;
		case 6:
			cout << "½Ǫ";
			break;
		case 7:
			cout << "��Ǫ";
			break;
		case 8:
			cout << "��Ǫ";
			break;
		case 9:
			cout << "��Ǫ";
			break;
	}
	if (C != 0 && D == 0 && E == 0 && F == 0)
		cout << "��";

	switch (D) {
		case 0:
			if (C != 0 && (E != 0 || F != 0)) //ǧ��λ��Ϊ0��ʮ��λ����λ������һ����0
				cout << "��";
			    break;
			if (!(C != 0 && (E != 0 || F != 0)))
				break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�ư�";
			break;
		case 9:
			cout << "����";
			break;
	}
	if (D != 0 && E == 0 && F == 0)
		cout << "��";

	switch (E) {
		case 0:
			if (D != 0 && F != 0)
				cout << "��";
			    break;
			if (!(D != 0 && F != 0))
			    break;
		case 1:
			cout << "Ҽʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 9:
			cout << "��ʰ";
			break;
	}
	if ((D != 0 && E != 0 && F == 0) || D == 0 && E != 0 && F == 0) 
		cout << "��";

	switch (F) {
		case 0:
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "����";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "����";
			break;
		case 8:
			cout << "����";
			break;
		case 9:
			cout << "����";
			break;
	}

	//ǧ~Ԫ
	switch (G) {
		case 0:
			if ((A != 0 || B != 0 || C != 0 || D != 0 || E != 0 || F != 0) && (H != 0 || I != 0 || J != 0)) 
				cout << "��";
			    break;
			if (!(A != 0 || B != 0 || C != 0 || D != 0 || E != 0 || F != 0))
			    break;
		case 1:
			cout << "ҼǪ";
			break;
		case 2:
			cout << "��Ǫ";
			break;
		case 3:
			cout << "��Ǫ";
			break;
		case 4:
			cout << "��Ǫ";
			break;
		case 5:
			cout << "��Ǫ";
			break;
		case 6:
			cout << "½Ǫ";
			break;
		case 7:
			cout << "��Ǫ";
			break;
		case 8:
			cout << "��Ǫ";
			break;
		case 9:
			cout << "��Ǫ";
			break;
	}

	switch (H) {
		case 0:
			if (G != 0 && ((I != 0 && J != 0) || (I == 0 && J != 0) || (I != 0 && J == 0)))
				cout << "��";
			    break;
			if (!(G != 0 && ((I != 0 && J != 0) || (I == 0 && J != 0) || (I != 0 && J == 0))))
                break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�ư�";
			break;
		case 9:
			cout << "����";
			break;
	}

	switch (I) {
		case 0:
			if (H != 0 && J != 0)
				cout << "��";
			    break;
			if (!(H != 0 && J != 0))
				break;
		case 1:
			cout << "Ҽʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 9:
			cout << "��ʰ";
			break;
	}

	switch (J) {
		case 0:
			if (A == 0 && B == 0 && C == 0 && D == 0 && E == 0 && F == 0 && G == 0 && H == 0 && I == 0 &&(K!=0||L!=0))
				break;
			else if (A == 0 && B == 0 && C == 0 && D == 0 && E == 0 && F == 0 && G == 0 && H == 0 && I == 0 && K == 0 && L == 0) {
				cout << "��Բ";
				break;
			}
			else {
				cout << "Բ";
				break;
			}
		case 1:
			cout << "ҼԲ";
			break;
		case 2:
			cout << "��Բ";
			break;
		case 3:
			cout << "��Բ";
			break;
		case 4:
			cout << "��Բ";
			break;
		case 5:
			cout << "��Բ";
			break;
		case 6:
			cout << "½Բ";
			break;
		case 7:
			cout << "��Բ";
			break;
		case 8:
			cout << "��Բ";
			break;
		case 9:
			cout << "��Բ";
			break;
	}

	if (K == 0 && L == 0)
		cout << "��";

	switch (K) {
		case 0:
			if (L != 0&&(A!=0|| B != 0 || C != 0 || D != 0 || E != 0 || F != 0 || G != 0 || H != 0 || I != 0 || J != 0 ))
				cout << "��";
			    break;
			if (L == 0)
			    break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�ƽ�";
			break;
		case 9:
			cout << "����";
			break;
	}

	if (K != 0 && L == 0)
		cout << "��";

	switch (L) {
		case 0:
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�Ʒ�";
			break;
		case 9:
			cout << "����";
			break;
	}
	cout << endl;
	return 0;
}