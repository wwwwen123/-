/*2353126 信03 崔露文*/
#include<iostream>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";

int main()
{
    //定义二维char数组，从第三行开始存储密码
    char password[12][666];

    // 读取第一行并忽略
    cin.getline(password[0], 666);

    // 读取密码长度和各种字符的最小要求
    int len, min_daxie, min_xiaoxie, min_shuzi, min_qita;
    cin >> len >> min_daxie >> min_xiaoxie >> min_shuzi >> min_qita;

    // 忽略整数输入后的换行符
    cin.ignore();

    // 从第三行开始读取密码
    for (int i = 2; i < 12; i++)
    {
        cin.getline(password[i], 666);
    }

    

    //验证密码
    for (int i = 2; i < 12; i++) //从第三行开始检查密码
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
                        
                        //是那15个字符之一才做++，空格等不算
                        qita++;
                    }
                    
                }
            }
        }


        //验证长度和字符类型数量是否符合要求
        if (num_len < 12 || num_len > 16 || num_len != len || daxie < min_daxie ||
            xiaoxie < min_xiaoxie || shuzi < min_shuzi || qita < min_qita ||
            min_daxie < 2 || min_xiaoxie < 2 || min_shuzi < 2 || min_qita < 2 || daxie+xiaoxie+shuzi+qita!=len)
        {
            cout << "错误" << endl;
            return 0;
        }
    }

    // 输出验证结果
    cout << "正确" << endl;

    return 0;
}