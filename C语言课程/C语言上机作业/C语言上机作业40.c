#include<stdio.h>
#include<string.h>
char newstr[100];   //定义新子串为全局变量，这样才能在getnewstr函数中被引用
void getnewstr(char a[100],char b[100],int i,int length)    //从母字符串a中获取与目标子串str长度相等的新子串b(newstr)；i是母串的某一位置
{
    int j;
    for (j=0; j<length; j++)    //从母串中不断取新子串
    {
        b[j]=a[i+j];
    }
    b[length]='\0';
}
int main()
{
	char a[100],str[100];   //a是原始的字符串，str是要查找的子串
    int i=0,length1,length2;
    puts("请输入一个字符串：");
    gets(a);
    puts("请输入要查找的字符串：");
    gets(str);
    length1=strlen(a);
    length2=strlen(str);
    while(1)  //无限循环
    {
        getnewstr(a,newstr,i,length2);  //取新子串
        if (strcmp(str,newstr)==0) //使用strcmp函数判断新子串和目标子串是否一致!!若一致则跳出循环
            break;
        i++;
        if(i>=length1)  //如果从母串所取的i已经超过了母串的长度，则母串中肯定就不包含目标子串
            i=-1;
    }
    if (i<0)
        printf("输入的字符串里没有要查找的对象！\n");
    else
        printf("查找对象的起始位置(从0开始)为%d:",i);
    return 0; 
}