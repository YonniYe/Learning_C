#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int i,num=0,length;
    printf("请输入字符串：\n");   //"I am a student.My age is 18.His age is 19"
	gets(str); 
    length=strlen(str);
    puts(str);
    for (i=0; i<length; i++)
    {
        if(str[i]!=' '&& str[(i+1)]==' ')   //计数空格的前一个单词
            num++;
        if(str[i]!=' '&& str[(i+1)]=='\0')  //计数字符串结束前的前一个单词
            num++;
        if(str[i]!=' '&& str[(i+1)]=='.') //计数句号的前一个单词
            num++;
    }
    printf("单词个数为%d",num);
    return 0;
}