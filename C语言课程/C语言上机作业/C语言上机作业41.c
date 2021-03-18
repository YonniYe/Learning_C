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
	char a[100],str[100],targetstr[100],temp[100];   //a是输入的字符串，str是被替换的字符串，targetstr是将被替换的字符串，temp用于临时保存str后面的字符串
    int i=0,length1,length2,length3,m,n;
    puts("请输入一个字符串：");
    gets(a);
    puts("请输入被替换的字符串：");
    gets(str);
    puts("请输入将要替换成的字符串：");
    gets(targetstr);
    length1=strlen(a);
    length2=strlen(str);
    length3=strlen(targetstr);
    for(i=0; i<length1; i++)
    {
        getnewstr(a,newstr,i,length2);  //取新子串
        if (strcmp(str,newstr)==0) //使用strcmp函数判断新子串和目标子串是否一致!若一致则使用continue跳出循环
            {
                for(m=i+length2,n=0 ; m<length1 ; m++,n++)    //保存s1字符串中剩余的字符，其中i+length2是因为i是目标的首位，加上length2就到了目标的末位后
                {
                    temp[n]=a[m];
                }
                temp[n]='\0';   //将字符数组转变成字符串？
                for (m=i,n=0 ; n<length3 ; m++,n++)   //将从i位置起的字符串统统替换成targetstr
                {
                    a[m]=targetstr[n];
                }
                for(n=0 ; n<strlen(temp) ; m++,n++)
                {
                    a[m]=temp[n];
                }
                a[m]='\0';  //将字符数组转变成字符串
                continue;   //使用continue而不用break，使跳出后继续循环
            }
        if(i>=length1)  //如果从母串所取的i已经超过了母串的长度，则母串中肯定就不包含目标子串
            i=-1;
    }
    if (i<0)
        printf("输入的字符串里没有要被替换的字符串！\n");
    else
        printf("%s",a);
    return 0; 
}