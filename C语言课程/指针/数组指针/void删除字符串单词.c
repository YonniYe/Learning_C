#include<stdio.h>
#include<string.h>
void Find(char *a, char *b, int length)
{
    int i,m=1;
    char *p=b;
    while(*a!='\0' && m!=0) //ֱ��a�ַ������ַ���ȡ��ϻ�m=0
    {
        if(*a==*p)  //���*a��*p��ȣ��ͼ��������жϣ�ֱ��*(a+1)Ϊ�ո�����Ϊֹ��
        {
            p++;
            if(*(a+1)==' '||*(a+1)=='\0')
            {
                m=0;
                for(i=0;i<length;i++)
                    *(a-i)='@';
            }
        }
        else
            p=b;
        a++;
    }
}

int main()
{
    char a[100],b[100];
    int lengthb,lengtha,i;
    printf("�������ַ�����");
    gets(a);
    printf("������Ҫɾ�����ַ���");
    gets(b);
    lengthb=strlen(b);
    lengtha=strlen(a);    
    Find(a,b,lengthb);
    for(i=0;i<lengtha;i++)
    {
        if(a[i]!='@')
        printf("%c",a[i]);
    }
    return 0;
}