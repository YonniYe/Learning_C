/*【程序功能】
在一个字符串中找到第一个未出现在另一个字符串中的字符，用字符串中此字符之前的所有字符组成一个新的字符串。
【编程要求】
1．编写void strsp(char *s1,char *s2,char *s3)函数。函数功能是自左向右找出s1指向的字符串中第一个未在s2指向的字符串中出现的字符，
将s1串中该字符前的所有字符作为一个新字符串复制到s3指向的数组中。 
例如，s1字符串为“this is a test string”，s2字符串为“a this”，在s1串中找到的第一个未出现在s2串中的字符是'e'，s1串中字符'e'之前
的所有字符是“this is a t”，因此s3字符串为“this is a t”。

2．编写main函数。函数功能是声明3个字符数组并用测试数据初始化其中2个数组，用3个数组作实参调用strsp函数，将测试字符串和生成的新字
符串输出到屏幕

【测试数据与运行结果】
测试数据： s1串 "this is a test string"
        s2串 "a this"
    输出： this is a test string
            a this
            this is a t
*/
#include<stdio.h>
#include<string.h>
void strsp(char *s1,char *s2,char *s3)
{
    int len2,j;
    len2=strlen(s2);
    char *ps3=s3;
    char *ps2=s2;
    strcpy(s3,s1);    
    while (*ps3 != '\0')
    {
        for (j=0; j<len2; j++)
        {
            if(*ps3==*(ps2+j))
            {
                j=-1;   //先判断再j++，把j重新赋值很关键！
                ps3++;
            }
        }
        *ps3='\0';
    }
}

int main()
{
    char s1[50]="this is a test string";
    char s2[20]="a this";
    char s3[50];
    strsp(s1,s2,s3);
    puts(s3);
    return 0;
}