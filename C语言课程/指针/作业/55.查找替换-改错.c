/*【要求】
1.按以下程序功能改正程序的错误。
2.可以修改语句中的一部分内容，调整语句次序，增加变量声明或预处理命令，但不能增加其他语句，也不能删去整条语句。
【程序功能】
以下程序中函数findreplace的功能是若s1指向的字符串（以下简称s1串）或s2指向的字符串（以下简称s2串）是空串则函数返回0；若s1串和s2串均不是空串，
则在s1串中查找s2串，并用s3指向的字符串替换在s1串中找到的所有s2串（子串）。若s1串中没有出现s2串（子串）则不做替换并使函数返回0，否则函数返回1。
【测试数据与运行结果】
测试字符串： s1串为"This is a sample program and sample data."
            s2串为"sample"
            s3串为"real"
        输出：This is a real program and real data.
【含有错误的源程序】*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
int findreplace(char *s1, char *s2, char *s3)
{
    int i,j,k=0,t=0;      //初始化k=0
    char temp[80];
    if(*s1=='\0'||*s2=='\0')
        return 0;
    for(i=0;s1[i]!='\0';i++)    //遍历s1串
    {
        for(j=i, k=0; s1[j]&&s1[j]==s2[k]; j++, k++)    //j=i开始
        {
            if(s2[k]=='\0') 
            {
                strcpy(temp,&s1[j]);    //把s1[j]以后的一起接过去
                strcpy(s1+i,s3);    
                i=i+strlen(s3);     //s2改成s3
                strcpy(s1+i,temp);
                t=1;
            }
        }
    }
    return t;
}
int main()
{
    char s1[80]="This is a sample program and sample data.";
    char s2[10]="sample",s3[10]="real";
    int t;
    t=findreplace(s1,s2,s3);    //t是int类型
    if(t) 
        puts(s1);     //if(t)用于判断t是不是真(也就是1)
    else 
        printf("not found");
    getch();    //等待按下任意键，再继续执行下面的语句
    return 0;
}