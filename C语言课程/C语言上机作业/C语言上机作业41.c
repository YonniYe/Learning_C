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
	char a[100],str[100],targetstr[100],temp[100];   //a��������ַ�����str�Ǳ��滻���ַ�����targetstr�ǽ����滻���ַ�����temp������ʱ����str������ַ���
    int i=0,length1,length2,length3,m,n;
    puts("������һ���ַ�����");
    gets(a);
    puts("�����뱻�滻���ַ�����");
    gets(str);
    puts("�����뽫Ҫ�滻�ɵ��ַ�����");
    gets(targetstr);
    length1=strlen(a);
    length2=strlen(str);
    length3=strlen(targetstr);
    for(i=0; i<length1; i++)
    {
        getnewstr(a,newstr,i,length2);  //ȡ���Ӵ�
        if (strcmp(str,newstr)==0) //ʹ��strcmp�����ж����Ӵ���Ŀ���Ӵ��Ƿ�һ��!��һ����ʹ��continue����ѭ��
            {
                for(m=i+length2,n=0 ; m<length1 ; m++,n++)    //����s1�ַ�����ʣ����ַ�������i+length2����Ϊi��Ŀ�����λ������length2�͵���Ŀ���ĩλ��
                {
                    temp[n]=a[m];
                }
                temp[n]='\0';   //���ַ�����ת����ַ�����
                for (m=i,n=0 ; n<length3 ; m++,n++)   //����iλ������ַ���ͳͳ�滻��targetstr
                {
                    a[m]=targetstr[n];
                }
                for(n=0 ; n<strlen(temp) ; m++,n++)
                {
                    a[m]=temp[n];
                }
                a[m]='\0';  //���ַ�����ת����ַ���
                continue;   //ʹ��continue������break��ʹ���������ѭ��
            }
        if(i>=length1)  //�����ĸ����ȡ��i�Ѿ�������ĸ���ĳ��ȣ���ĸ���п϶��Ͳ�����Ŀ���Ӵ�
            i=-1;
    }
    if (i<0)
        printf("������ַ�����û��Ҫ���滻���ַ�����\n");
    else
        printf("%s",a);
    return 0; 
}