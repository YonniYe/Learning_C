#include<stdio.h>
#include<string.h>
int main()
{
    char str[50];
    int a=0,b=0,i;
    printf("�������ַ�����\n");   //"I am a student.My age is 18.His age is 19"
	gets(str);  //��������ո�
	for(i=0; i<strlen(str); i++)    //i<strlen(str)����ʵ�ʳ���ѭ��
	{
		if(str[i]>='A'&&str[i]<='Z'||str[i]>='a'&&str[i]<='z')
			a++;
		else if(str[i]>='0'&&str[i]<='9')
			b++;
	}
    printf("��ĸ����=%d,���ָ���=%d\n",a,b);
	return 0;
}