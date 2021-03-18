#include<stdio.h>
#include<string.h>
int main(void)
{	
	char a[20]="hello world";//
	char *pc=a;//定义字符指针变量pc指向数组a
	char **pb;
	pb=&pc;//指向指针的指针pb来访问字符串a
	puts(*pb);//利用pb输出该字符串
	printf("%c",*(*pb+2));//利用pb输出第3个字符
	return 0;
} 