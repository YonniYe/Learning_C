#include<stdio.h>
char *mystrcpy(char *dest, char *src)
{
    char *psrc=src;
    char *pdest=dest;
    while (*psrc!='\0')
    {
        *pdest=*psrc;
        pdest++;
        psrc++;
    }
    *pdest='\0';
    return dest;
}

int main()
{
    char s1[50];
    char s2[20]="Chris Yeser";
    mystrcpy(s1,s2);
    puts(s1);
    return 0;
}