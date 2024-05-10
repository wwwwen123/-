/*2353126 ��03 ��¶��*/
#include <iostream>
#include <iomanip>
using namespace std;

int step = 0;
int stack[3][10] = { 0 };
int top[3] = { 0 };

void move(int n, char src, char dst)
{
    //��Դ���ƿ�����
    switch (src)
    {
        case 'A':
            stack[0][--top[0]] = 0;
            break;
        case 'B':
            stack[1][--top[1]] = 0;
            break;
        case 'C':
            stack[2][--top[2]] = 0;
            break;
        default:
            break;
    }

    //��������ӵ�Ŀ����
    switch (dst)
    {
        case 'A':
            stack[0][top[0]++] = n;
            break;
        case 'B':
            stack[1][top[1]++] = n;
            break;
        case 'C':
            stack[2][top[2]++] = n;
            break;
        default:
            break;
    }

}

void print()
{
    cout << "A:";
    //����stackA���飬��ӡ����A�ϵ�����
    for (int i = 0; i < 10; i++) {
        //�������ֵΪ0��Ԫ�أ��ʹ�ӡ�����ո񣨱�ʾ���λ��û�����ӣ�
        if (stack[0][i] == 0) {
            cout << "  ";
        }
        else {
            cout << setiosflags(ios::right) << setw(2) << stack[0][i];
        }
    }

    cout << " B:";
    for (int i = 0; i < 10; i++) {
        if (stack[1][i] == 0) {
            cout << "  ";
        }
        else {
            cout << setiosflags(ios::right) << setw(2) << stack[1][i];
        }
    }

    cout << " C:";
    for (int i = 0; i < 10; i++) {
        if (stack[2][i] == 0) {
            cout << "  ";
        }
        else {
            cout << setiosflags(ios::right) << setw(2) << stack[2][i];
        }
    }

    cout << endl;
}

void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        step++;
        cout << "��" << setiosflags(ios::right) << setw(4) << step << " ��("
             << setw(2) << 1 << "): " << src << "-->" << dst << " ";
        move(n, src, dst);
        print();
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        step++;
        cout << "��" << setiosflags(ios::right) << setw(4) << step << " ��("
             << setw(2) << n << "): " << src << "-->" << dst << " ";
        move(n, src, dst);
        print();
        hanoi(n - 1, tmp, src, dst);
        }
    }



int main()
{
    int n;
    char src, tmp, dst;

    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> n;
        if (n < 1 || n>10) {
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
        cin.ignore(65536, '\n');
        if (src >= 'a' && src <= 'c')
            src -= 32;//Сдת��д
        if (src >= 'A' && src <= 'C')
            break;
    }

    while (1)
    {
        cout << "������Ŀ����(A-C)" << endl;
        cin >> dst;
        cin.ignore(65536, '\n');
        if (dst >= 'a' && dst <= 'c')
            dst -= 32;//Сдת��д
        if (dst == src) {
            cout << "Ŀ����(" << src << ")��������ʼ��(" << dst << ")��ͬ" << endl;
            continue;
        }
        if (dst >= 'A' && dst <= 'C')
            break;
    }

    tmp = 'A' + 'B' + 'C' - src - dst;

    //�����ӽ��г�ʼ����ȷ�����������ڵײ�����С�������ڶ���
    for (int i = 0; i < n; i++)
    {
        switch (src)
        {
            case 'A':
                stack[0][i] = n - i;
                top[0] = n;
                break;
            case 'B':
                stack[1][i] = n - i;
                top[1] = n;
                break;
            case 'C':
                stack[2][i] = n - i;
                top[2] = n;
                break;
        }
    }

    cout << "��ʼ:                ";//16���ո�
    print();
    hanoi(n, src, tmp, dst);
    return 0;
}