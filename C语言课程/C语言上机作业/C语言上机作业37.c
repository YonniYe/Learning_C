#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int suiji(int x)    //���������
{
    int a;
    a=rand();
	x=a%200 + 1;    //���÷�Χ1-200
    return x;
}

void insert(int *a,int n,int i,int k)   //n��������Ԫ�ظ�����k�ǲ������,i��Ҫ�����λ��
{
    int j;  //j���ڽ�ÿ��Ԫ��������һλ������a[j+1]=a[j]
    for (j=n;j>=i;j--)
    {
        a[j+1]=a[j];
    }
    a[i+1]=k;   //i��0��ʼ���ʲ��뵽i+1��
}

int main()
{
    int a[10];
    int k,x,i,t;
    srand(time(NULL));
    printf("������ɵ�����Ϊ��");    
    for (i = 0; i < 9; i++)
    {
        a[i]=suiji(x);
        printf("%d  ",a[i]);
    }
    printf("\n������Ҫ���������");
    scanf("%d",&k);
    printf("����Ҫ��%d������a[?]��(������0~9)��",k);
    scanf("%d",&t);
    insert(a,9,t,k);   //���������� 
    printf("����������Ϊ��");
    for (i=0;i<10;i++)
        printf("%d  ",a[i]); 
    return 0;
}

