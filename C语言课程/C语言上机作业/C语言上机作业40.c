#include<stdio.h>
#include<string.h>
char newstr[100];   //�������Ӵ�Ϊȫ�ֱ���������������getnewstr�����б�����
void getnewstr(char a[100],char b[100],int i,int length)    //��ĸ�ַ���a�л�ȡ��Ŀ���Ӵ�str������ȵ����Ӵ�b(newstr)��i��ĸ����ĳһλ��
{
    int j;
    for (j=0; j<length; j++)    //��ĸ���в���ȡ���Ӵ�
    {
        b[j]=a[i+j];
    }
    b[length]='\0';
}
int main()
{
	char a[100],str[100];   //a��ԭʼ���ַ�����str��Ҫ���ҵ��Ӵ�
    int i=0,length1,length2;
    puts("������һ���ַ�����");
    gets(a);
    puts("������Ҫ���ҵ��ַ�����");
    gets(str);
    length1=strlen(a);
    length2=strlen(str);
    while(1)  //����ѭ��
    {
        getnewstr(a,newstr,i,length2);  //ȡ���Ӵ�
        if (strcmp(str,newstr)==0) //ʹ��strcmp�����ж����Ӵ���Ŀ���Ӵ��Ƿ�һ��!!��һ��������ѭ��
            break;
        i++;
        if(i>=length1)  //�����ĸ����ȡ��i�Ѿ�������ĸ���ĳ��ȣ���ĸ���п϶��Ͳ�����Ŀ���Ӵ�
            i=-1;
    }
    if (i<0)
        printf("������ַ�����û��Ҫ���ҵĶ���\n");
    else
        printf("���Ҷ������ʼλ��(��0��ʼ)Ϊ%d:",i);
    return 0; 
}