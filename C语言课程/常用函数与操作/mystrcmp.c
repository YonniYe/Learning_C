#include<stdio.h>
int mystrcmp(char *str1, char *str2)
{
    char *pstr1=str1;
    char *pstr2=str2;
    while (*pstr1 != '\0')
    {
        if (*pstr1 > *pstr2)
            return 1;
        else if(*pstr1 < *pstr2)
            return -1;
        else if(*pstr1 == *pstr2)
            pstr1++,pstr2++;
    }
    if(*pstr2=='\0')\
        return 0;
    else
        return -1;
}

int main()
{
    char s1[20]="Helloworld";
    char s2[20]="Helloword";
    int n;
    n=mystrcmp(s1, s2);
    printf("n=%d",n);
    return 0;
}