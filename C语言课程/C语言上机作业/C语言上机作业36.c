#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int suiji(int x)
{
    int a;
    a=rand();
	x=a%100+1;    //���÷�Χ1-100
    return x;
}

int main()
{
    int a[10];
    int x,i;
    srand(time(NULL));
    printf("������ɵ�����Ϊ��");    
    for (i = 0; i < 10; i++)
    {
        a[i]=suiji(x);
        printf("%d  ",a[i]);
    }
    printf("\n���ú������Ϊ��");  
    for (i = 9; i >= 0; i--)
    {
        printf("%d  ",a[i]);
    }
    return 0;
}