#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int suiji(int x)
{
    int a;
    a=rand();
	x=a%200 + 1;    //���÷�Χ1-200
    return x;
}

int main()
{
    int a[10];
    int k,x,i;
    srand(time(NULL));
    printf("������ɵ�����Ϊ��");    
    for (i = 0; i < 10; i++)
    {
        a[i]=suiji(x);
        printf("%d  ",a[i]);
    }
    printf("\n������Ҫɾ��������");
    scanf("%d",&k);
    for (i=0; i<10; ++i) //˳�����
    {
        if (a[i] == k)
        {
            a[i]=0;
        }
    } 
    printf("ɾ�����ֺ������Ϊ��");        
    for (i = 0; i < 10; i++)
    {
        if(a[i]!=0)
            printf("%d  ",a[i]);
    }
    return 0;
}