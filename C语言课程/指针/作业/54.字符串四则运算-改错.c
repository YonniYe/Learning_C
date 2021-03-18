/*【程序功能】
输入一个字符串，按字符串中包含的算式完成整数四则运算，输出运算结果。若运算符错误（除“+，-，*，/”外的其他字符），则输出“operator error!”。
【测试数据与运行结果】
输入1234+567时，输出应为：1234+567=1801
输入12/2时，输出应为：12/2=6
【含有错误的程序】*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
long stoi(char *s,int *i)	//int改成了long，返回类型跟返回值保持一致,stoi函数表示字符型转换成整数型
{	
	long n=0;
	while(isdigit(s[*i]))   //isdigit用于检查其参数是否为十进制数字字符
		n=n*10+s[(*i)++]-'0';	//这里加的是两者字符的差值，‘0’也就是48。例如123经历的循环就是0-1-12-123
	return n;
}
long add(char *s)       //long是长整型，即long int
{	
	int i=0,*pi=&i;		//pi要指向i的地址
	char op;	//op表示符号
	long a=0,b=0;	//c多余，故删除
	a=stoi(s,pi);
	op=s[i++];  //i到了判断isdigit后的第一个数，表示符号
	b=stoi(s,pi);
	switch(op) 
	{
		case '+':
            return a+b;
		case '-':
            return a-b;
		case '*':
            return a*b;
		case '/':
            if(b==0) 
            {
                printf("div!0");
                exit(0); 
			}
            else	//这里加else，表示如果不为0，再返回a/b
				return a/b;
            
		default: printf("operator error!");exit(0);
	}
}
int main(void)
{	
	char s[80];
	gets(s);
    printf("%s=",s);
	printf("%ld\n",add(s));
	return 0;
}