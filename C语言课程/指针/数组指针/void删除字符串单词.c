#include<stdio.h>
#include<string.h>
void Find(char *a, char *b, int length)
{
    int i,m=1;
    char *p=b;
    while(*a!='\0' && m!=0) //直至a字符串中字符读取完毕或m=0
    {
        if(*a==*p)  //如果*a和*p相等，就继续往下判断，直到*(a+1)为空格或结束为止。
        {
            p++;
            if(*(a+1)==' '||*(a+1)=='\0')
            {
                m=0;
                for(i=0;i<length;i++)
                    *(a-i)='@';
            }
        }
        else
            p=b;
        a++;
    }
}

int main()
{
    char a[100],b[100];
    int lengthb,lengtha,i;
    printf("请输入字符串：");
    gets(a);
    printf("请输入要删除的字符：");
    gets(b);
    lengthb=strlen(b);
    lengtha=strlen(a);    
    Find(a,b,lengthb);
    for(i=0;i<lengtha;i++)
    {
        if(a[i]!='@')
        printf("%c",a[i]);
    }
    return 0;
}