/*2353126 ĞÅ03 ´ŞÂ¶ÎÄ*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double a;
	cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:" << endl;
	cin >> a;
	cout << "´óĞ´½á¹ûÊÇ:" << endl;

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

	int A = static_cast<int>(a / 1000000000) % 10;//Ê°ÒÚ
	int B = static_cast<int>(a / 100000000) % 10;//ÒÚ
	int C = static_cast<int>(a / 10000000) % 10;//ÇªÍò
	int D = static_cast<int>(a / 1000000) % 10;//°ÛÍò
	int E = static_cast<int>(a / 100000) % 10;//Ê°Íò
	int F = static_cast<int>(a / 10000) % 10;//Íò
	int G = static_cast<int>(a / 1000) % 10;//Çª
	int H = static_cast<int>(a / 100) % 10;//°Û
	int I = static_cast<int>(a / 10) % 10;//Ê°
	int J = static_cast<int>(b) % 10;//Ô²
	int K = static_cast<int>((j + 0.002) * 10) % 10;//½Ç
	int L = static_cast<int>((j + 0.002) * 100) % 10;//·Ö

	//Ê®ÒÚ~ÒÚ
	switch (A) {
		case 0:
			break;
		case 1:
			cout << "Ò¼Ê°";
			break;
		case 2:
			cout << "·¡Ê°";
			break;
		case 3:
			cout << "ÈşÊ°";
			break;
		case 4:
			cout << "ËÁÊ°";
			break;
		case 5:
			cout << "ÎéÊ°";
			break;
		case 6:
			cout << "Â½Ê°";
			break;
		case 7:
			cout << "ÆâÊ°";
			break;
		case 8:
			cout << "°ÆÊ°";
			break;
		case 9:
			cout << "¾ÁÊ°";
			break;
	}
	if (A != 0 && B == 0)
		cout << "ÒÚ";

	switch (B) {
		case 0:
			break;
		case 1:
			cout << "Ò¼ÒÚ";
			break;
		case 2:
			cout << "·¡ÒÚ";
			break;
		case 3:
			cout << "ÈşÒÚ";
			break;
		case 4:
			cout << "ËÁÒÚ";
			break;
		case 5:
			cout << "ÎéÒÚ";
			break;
		case 6:
			cout << "Â½ÒÚ";
			break;
		case 7:
			cout << "ÆâÒÚ";
			break;
		case 8:
			cout << "°ÆÒÚ";
			break;
		case 9:
			cout << "¾ÁÒÚ";
			break;
	}

	//Ç§Íò~Íò
	switch (C) {
		case 0:
			if ((A != 0 || B != 0) && (D != 0 || E != 0 || F != 0)) //Ç§Íò~Íò¶¼Îª0£¬²»Êä³ö¡°Áã¡±
				cout << "Áã";
			    break;
			if (!(A != 0 || B != 0) && (D != 0 || E != 0 || F != 0))
				break;
		case 1:
			cout << "Ò¼Çª";
			break;
		case 2:
			cout << "·¡Çª";
			break;
		case 3:
			cout << "ÈşÇª";
			break;
		case 4:
			cout << "ËÁÇª";
			break;
		case 5:
			cout << "ÎéÇª";
			break;
		case 6:
			cout << "Â½Çª";
			break;
		case 7:
			cout << "ÆâÇª";
			break;
		case 8:
			cout << "°ÆÇª";
			break;
		case 9:
			cout << "¾ÁÇª";
			break;
	}
	if (C != 0 && D == 0 && E == 0 && F == 0)
		cout << "Íò";

	switch (D) {
		case 0:
			if (C != 0 && (E != 0 || F != 0)) //Ç§ÍòÎ»²»Îª0£¬Ê®ÍòÎ»ºÍÍòÎ»ÖÁÉÙÓĞÒ»¸ö·Ç0
				cout << "Áã";
			    break;
			if (!(C != 0 && (E != 0 || F != 0)))
				break;
		case 1:
			cout << "Ò¼°Û";
			break;
		case 2:
			cout << "·¡°Û";
			break;
		case 3:
			cout << "Èş°Û";
			break;
		case 4:
			cout << "ËÁ°Û";
			break;
		case 5:
			cout << "Îé°Û";
			break;
		case 6:
			cout << "Â½°Û";
			break;
		case 7:
			cout << "Æâ°Û";
			break;
		case 8:
			cout << "°Æ°Û";
			break;
		case 9:
			cout << "¾Á°Û";
			break;
	}
	if (D != 0 && E == 0 && F == 0)
		cout << "Íò";

	switch (E) {
		case 0:
			if (D != 0 && F != 0)
				cout << "Áã";
			    break;
			if (!(D != 0 && F != 0))
			    break;
		case 1:
			cout << "Ò¼Ê°";
			break;
		case 2:
			cout << "·¡Ê°";
			break;
		case 3:
			cout << "ÈşÊ°";
			break;
		case 4:
			cout << "ËÁÊ°";
			break;
		case 5:
			cout << "ÎéÊ°";
			break;
		case 6:
			cout << "Â½Ê°";
			break;
		case 7:
			cout << "ÆâÊ°";
			break;
		case 8:
			cout << "°ÆÊ°";
			break;
		case 9:
			cout << "¾ÁÊ°";
			break;
	}
	if ((D != 0 && E != 0 && F == 0) || D == 0 && E != 0 && F == 0) 
		cout << "Íò";

	switch (F) {
		case 0:
			break;
		case 1:
			cout << "Ò¼Íò";
			break;
		case 2:
			cout << "·¡Íò";
			break;
		case 3:
			cout << "ÈşÍò";
			break;
		case 4:
			cout << "ËÁÍò";
			break;
		case 5:
			cout << "ÎéÍò";
			break;
		case 6:
			cout << "Â½Íò";
			break;
		case 7:
			cout << "ÆâÍò";
			break;
		case 8:
			cout << "°ÆÍò";
			break;
		case 9:
			cout << "¾ÁÍò";
			break;
	}

	//Ç§~Ôª
	switch (G) {
		case 0:
			if ((A != 0 || B != 0 || C != 0 || D != 0 || E != 0 || F != 0) && (H != 0 || I != 0 || J != 0)) 
				cout << "Áã";
			    break;
			if (!(A != 0 || B != 0 || C != 0 || D != 0 || E != 0 || F != 0))
			    break;
		case 1:
			cout << "Ò¼Çª";
			break;
		case 2:
			cout << "·¡Çª";
			break;
		case 3:
			cout << "ÈşÇª";
			break;
		case 4:
			cout << "ËÁÇª";
			break;
		case 5:
			cout << "ÎéÇª";
			break;
		case 6:
			cout << "Â½Çª";
			break;
		case 7:
			cout << "ÆâÇª";
			break;
		case 8:
			cout << "°ÆÇª";
			break;
		case 9:
			cout << "¾ÁÇª";
			break;
	}

	switch (H) {
		case 0:
			if (G != 0 && ((I != 0 && J != 0) || (I == 0 && J != 0) || (I != 0 && J == 0)))
				cout << "Áã";
			    break;
			if (!(G != 0 && ((I != 0 && J != 0) || (I == 0 && J != 0) || (I != 0 && J == 0))))
                break;
		case 1:
			cout << "Ò¼°Û";
			break;
		case 2:
			cout << "·¡°Û";
			break;
		case 3:
			cout << "Èş°Û";
			break;
		case 4:
			cout << "ËÁ°Û";
			break;
		case 5:
			cout << "Îé°Û";
			break;
		case 6:
			cout << "Â½°Û";
			break;
		case 7:
			cout << "Æâ°Û";
			break;
		case 8:
			cout << "°Æ°Û";
			break;
		case 9:
			cout << "¾Á°Û";
			break;
	}

	switch (I) {
		case 0:
			if (H != 0 && J != 0)
				cout << "Áã";
			    break;
			if (!(H != 0 && J != 0))
				break;
		case 1:
			cout << "Ò¼Ê°";
			break;
		case 2:
			cout << "·¡Ê°";
			break;
		case 3:
			cout << "ÈşÊ°";
			break;
		case 4:
			cout << "ËÁÊ°";
			break;
		case 5:
			cout << "ÎéÊ°";
			break;
		case 6:
			cout << "Â½Ê°";
			break;
		case 7:
			cout << "ÆâÊ°";
			break;
		case 8:
			cout << "°ÆÊ°";
			break;
		case 9:
			cout << "¾ÁÊ°";
			break;
	}

	switch (J) {
		case 0:
			if (A == 0 && B == 0 && C == 0 && D == 0 && E == 0 && F == 0 && G == 0 && H == 0 && I == 0 &&(K!=0||L!=0))
				break;
			else if (A == 0 && B == 0 && C == 0 && D == 0 && E == 0 && F == 0 && G == 0 && H == 0 && I == 0 && K == 0 && L == 0) {
				cout << "ÁãÔ²";
				break;
			}
			else {
				cout << "Ô²";
				break;
			}
		case 1:
			cout << "Ò¼Ô²";
			break;
		case 2:
			cout << "·¡Ô²";
			break;
		case 3:
			cout << "ÈşÔ²";
			break;
		case 4:
			cout << "ËÁÔ²";
			break;
		case 5:
			cout << "ÎéÔ²";
			break;
		case 6:
			cout << "Â½Ô²";
			break;
		case 7:
			cout << "ÆâÔ²";
			break;
		case 8:
			cout << "°ÆÔ²";
			break;
		case 9:
			cout << "¾ÁÔ²";
			break;
	}

	if (K == 0 && L == 0)
		cout << "Õû";

	switch (K) {
		case 0:
			if (L != 0&&(A!=0|| B != 0 || C != 0 || D != 0 || E != 0 || F != 0 || G != 0 || H != 0 || I != 0 || J != 0 ))
				cout << "Áã";
			    break;
			if (L == 0)
			    break;
		case 1:
			cout << "Ò¼½Ç";
			break;
		case 2:
			cout << "·¡½Ç";
			break;
		case 3:
			cout << "Èş½Ç";
			break;
		case 4:
			cout << "ËÁ½Ç";
			break;
		case 5:
			cout << "Îé½Ç";
			break;
		case 6:
			cout << "Â½½Ç";
			break;
		case 7:
			cout << "Æâ½Ç";
			break;
		case 8:
			cout << "°Æ½Ç";
			break;
		case 9:
			cout << "¾Á½Ç";
			break;
	}

	if (K != 0 && L == 0)
		cout << "Õû";

	switch (L) {
		case 0:
			break;
		case 1:
			cout << "Ò¼·Ö";
			break;
		case 2:
			cout << "·¡·Ö";
			break;
		case 3:
			cout << "Èş·Ö";
			break;
		case 4:
			cout << "ËÁ·Ö";
			break;
		case 5:
			cout << "Îé·Ö";
			break;
		case 6:
			cout << "Â½·Ö";
			break;
		case 7:
			cout << "Æâ·Ö";
			break;
		case 8:
			cout << "°Æ·Ö";
			break;
		case 9:
			cout << "¾Á·Ö";
			break;
	}
	cout << endl;
	return 0;
}