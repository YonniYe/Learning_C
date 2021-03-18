#include<stdio.h>
#include<string.h>
int huiwen(char s[])
{
    char i,j;
    int flag=1;
    for (i=0,j=strlen(s)-1; j>1; i++,j--)
    {
        if (s[i]!=s[j])
        {
            flag=0;
            break;
        }
    }
    return flag;
}

int main()
{
    char s[50];
    printf("请输入字符串：\n");
    gets(s);
    if(huiwen(s)==1)
        printf("%s是回文字符串\n",s);
    else
        printf("%s不是回文字符串\n",s);
    return 0; 
}