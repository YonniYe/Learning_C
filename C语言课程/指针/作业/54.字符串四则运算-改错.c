/*�������ܡ�
����һ���ַ��������ַ����а�������ʽ��������������㣬���������������������󣨳���+��-��*��/����������ַ������������operator error!����
���������������н����
����1234+567ʱ�����ӦΪ��1234+567=1801
����12/2ʱ�����ӦΪ��12/2=6
�����д���ĳ���*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
long stoi(char *s,int *i)	//int�ĳ���long���������͸�����ֵ����һ��,stoi������ʾ�ַ���ת����������
{	
	long n=0;
	while(isdigit(s[*i]))   //isdigit���ڼ��������Ƿ�Ϊʮ���������ַ�
		n=n*10+s[(*i)++]-'0';	//����ӵ��������ַ��Ĳ�ֵ����0��Ҳ����48������123������ѭ������0-1-12-123
	return n;
}
long add(char *s)       //long�ǳ����ͣ���long int
{	
	int i=0,*pi=&i;		//piҪָ��i�ĵ�ַ
	char op;	//op��ʾ����
	long a=0,b=0;	//c���࣬��ɾ��
	a=stoi(s,pi);
	op=s[i++];  //i�����ж�isdigit��ĵ�һ��������ʾ����
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
            else	//�����else����ʾ�����Ϊ0���ٷ���a/b
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