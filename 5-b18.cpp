/*2353126 ��03 ��¶��*/
#include<iostream>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";

int main()
{
    //�����άchar���飬�ӵ����п�ʼ�洢����
    char password[12][666];

    // ��ȡ��һ�в�����
    cin.getline(password[0], 666);

    // ��ȡ���볤�Ⱥ͸����ַ�����СҪ��
    int len, min_daxie, min_xiaoxie, min_shuzi, min_qita;
    cin >> len >> min_daxie >> min_xiaoxie >> min_shuzi >> min_qita;

    // �������������Ļ��з�
    cin.ignore();

    // �ӵ����п�ʼ��ȡ����
    for (int i = 2; i < 12; i++)
    {
        cin.getline(password[i], 666);
    }

    

    //��֤����
    for (int i = 2; i < 12; i++) //�ӵ����п�ʼ�������
    {
        int num_len = 0, daxie = 0, xiaoxie = 0, shuzi = 0, qita = 0;
        for (int j = 0; password[i][j] != '\0'; j++)
        {
            num_len++;
            if (password[i][j] >= 'A' && password[i][j] <= 'Z')
                daxie++;
            else if (password[i][j] >= 'a' && password[i][j] <= 'z')
                xiaoxie++;
            else if (password[i][j] >= '0' && password[i][j] <= '9')
                shuzi++;
            else 
            {
                
                for (int k = 0; k < 15; k++)
                {
                    if (password[i][j] == other[k]) 
                    {
                        
                        //����15���ַ�֮һ����++���ո�Ȳ���
                        qita++;
                    }
                    
                }
            }
        }


        //��֤���Ⱥ��ַ����������Ƿ����Ҫ��
        if (num_len < 12 || num_len > 16 || num_len != len || daxie < min_daxie ||
            xiaoxie < min_xiaoxie || shuzi < min_shuzi || qita < min_qita ||
            min_daxie < 2 || min_xiaoxie < 2 || min_shuzi < 2 || min_qita < 2 || daxie+xiaoxie+shuzi+qita!=len)
        {
            cout << "����" << endl;
            return 0;
        }
    }

    // �����֤���
    cout << "��ȷ" << endl;

    return 0;
}