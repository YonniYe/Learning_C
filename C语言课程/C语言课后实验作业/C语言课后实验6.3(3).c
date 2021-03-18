#include <stdio.h>
#include <string.h>
int mystrcmp(char s1[], char s2[])
{
    int i=0;
    while (s1[i] == s2[i] && s1[i] != '\0')
    {
        i++;
    }
    
    return s1[i] - s2[i];
}

int main()
{   
    char a[50]={0},b[50]={0};
    printf("请输入第一个字符串：\n");
	gets(a);    
    printf("请输入第二个字符串：\n");
	gets(b);
	int t=mystrcmp(a,b);
	printf("两字符串的比较结果是%d\n",t);
    if (t>0)
        printf("%s > %s",a,b);
    else if(t==0)
        printf("%s = %s",a,b);
    else
        printf("%s < %s",a,b);
	return 0;
}