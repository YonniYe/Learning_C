#include<stdio.h>
#include<string.h>
int StrToInt(char s[]) 
{
    int i,result=0;
    for(i=0; i<strlen(s); ++i) 
    {
        if(s[i] >= '0' && s[i] <= '9')  //用if来先跳过负号“-”，从而先算出数字result。
        {
            result=10 * result +(s[i]-'0'); //'0'表示0的ASCII码值，s[i]同理。s[i]-'0'正好算出整型数的值
        }
    }
    if(s[0] == '-') //如果有负号存在，就让整型数变成负数
        result = -result;
    return result;
}

int main()
{
    char a[50];
    int i,x;
    puts("请输入一个由数字构成的字符串：");
    gets(a);
    x=StrToInt(a);
    printf("字符串“%s”转换成的整形数为%d",a,x);
}
