#include<stdio.h>
#include<string.h>
int main(void)
{	
	char a[20]="hello world";//
	char *pc=a;//�����ַ�ָ�����pcָ������a
	char **pb;
	pb=&pc;//ָ��ָ���ָ��pb�������ַ���a
	puts(*pb);//����pb������ַ���
	printf("%c",*(*pb+2));//����pb�����3���ַ�
	return 0;
} 