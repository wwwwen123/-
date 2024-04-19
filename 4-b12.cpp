/*2353126 ��03 ��¶��*/
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */

   /***************************************************************************
     �������ƣ�hanoi
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        cout << setiosflags(ios::right) << setw(2) << 1 << "# " 
             << (src < 97 ? char(src) : char(src - 32)) << "-->" << (dst < 97 ? char(dst) : char(dst - 32)) << endl;
        //���������Ǵ�д����Сд�������Ϊ��д��ĸ
    }

    else {
        hanoi(n - 1, src, dst, tmp);
        //��n-1�����Ӵ���ʼ�Ƶ��м�
        cout << setiosflags(ios::right) << setw(2) << n << "# "
            << (src < 97 ? char(src) : char(src - 32)) << "-->" << (dst < 97 ? char(dst) : char(dst - 32)) << endl;
        hanoi(n - 1, tmp, src, dst);
        //��n-1�����Ӵ��м��Ƶ�Ŀ��
        //��n-1��������������������ʼ����Ҫ�ƶ�������������Ŀ����
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
    int n;
    char src, tmp, dst;
    
    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
        cin >> n;
        if (n < 1 || n>16) {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        else {
            cin.clear();
            cin.ignore(65536, '\n');
            break;
        }
    }

    while (1) 
    {
        cout << "��������ʼ��(A-C)" << endl;
        cin >> src;
        if (src == 'A' || src == 'a' || src == 'B' || src == 'b' || src == 'C' || src == 'c') {
            cin.clear();
            cin.ignore(65536, '\n');
            break;
        }
        else {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
    }

    while (1) 
    {
        cout << "������Ŀ����(A-C)" << endl;
        cin >> dst;
        if ((dst == 'A' || dst == 'a' || dst == 'B' || dst == 'b' || dst == 'C' || dst == 'c') 
            && dst != src && dst != src+32 && dst != src-32) //Ŀ����������ȷ�Ҳ�����ʼ����ͬ
        {
            cin.clear();
            cin.ignore(65536, '\n');
            break;
        }
        else 
        {
            cin.clear();
            cin.ignore(65536, '\n');
            if (dst == src || dst == src + 32 || dst == src - 32) {
                cout << "Ŀ����(" << (src < 97 ? char(src) : char(src - 32)) 
                     << ")��������ʼ��(" << (src < 97 ? char(src) : char(src - 32)) << ")��ͬ" << endl;
            }
            continue;
        }
    }
    
    if ((src == 'A' || src == 'a') && (dst == 'B' || dst == 'b') || (src == 'B' || src == 'b') && (dst == 'A' || dst == 'a')) {
        tmp = 'C';
    }
    else if ((src == 'A' || src == 'a') && (dst == 'C' || dst == 'c') || (src == 'C' || src == 'c') && (dst == 'A' || dst == 'a')) {
        tmp = 'B';
    }
    else {
        tmp = 'A';
    }

    cout << "�ƶ�����Ϊ:" << endl;
    hanoi(n, src, tmp, dst);
    return 0;
}


