/*在s和t两字符串中找到共同的字符，并保存到u里 */
#include<stdio.h>
#include<string.h>
void fun(char *s, char *t, char *u)
{
    char *q=s;
    char *p=t;
    int i,j=0,flag=0,lens;
    lens=strlen(s);
    while (*p != '\0')
    {
        for (i=0; i<lens; i++)
        {
            if(flag==0 && *p==*(q+i))
            {
                i=-1;
                flag=1;
            }
            if(flag==1)
            {
                *(u+j)=*p;
                j++;
                p++;
                flag=0;
            }
        }
        *p='\0';
        *(u+j)='\0';
    }
}

int main()
{
    char s[6]="ABCDE";
    char t[6]="BDFGG";
    char u[6];
    fun(s,t,u);
    puts(u);
    return 0;
}