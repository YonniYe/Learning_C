#include<stdio.h>
int main()
{    
    int i,count,t,x;
    int a[16]={8,8,8,7,6,8,5,7,6,8,8,7,8,8,7,7};
    int num[11]={0};
    for (i=0; i<16; i++)
    {
        printf("%-3d",a[i]);
    }
    printf("\n");
    for(count=0; count<16; count++)     //a[count]���ڱ���a[16]
    {
        x=a[count];   //a[count]���ڱ���������ÿһ��ֵ
        num[x]++;    //a[count]ȡ��ֵxʱ��num[x]���Լ�һ��
    }
    for(i=0; i<10; i++)     //i���ڱ�ʾ0~9ÿ������
    {
        t=num[i];   //����t���ڱ�ʾ0~9ÿ�����ֳ��ֵĴ���
        printf("ͳ����� %d ���ִ��� %d \n",i,t);
    }
    return 0;
}