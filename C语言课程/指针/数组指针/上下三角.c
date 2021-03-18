#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 5
int suiji(int x)    //生成随机数
{
    int a;
    a=rand();
    x=a%20+1;    //以1-20的范围为例
    return x;
}

void fun1(int *a, int n)        //fun1用于将左下三角元素值乘以n
{
    int i,j;
    for (i=0; i<N; i++)
        for (j=0; j<i+1; j++)
        {
            a[i*N+j]*=n;
        }
}

int fun2(int *a)      //fun2用于计算右上三角元素值之和
{
    int i,j;
    int sum=0;
    for (i=0;i<N;i++)
        for (j=i;j<N;j++)
            sum = sum + a[i*N+j];
    return sum;
}

int main()
{
    srand(time(NULL));
    int i,j,sum,n;    
    int a[N][N]; 
    for (i=0; i<N; i++)
    {
        for (j=0; j<N; j++)
        {
            a[i][j]=suiji(i);
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    printf("\n请输入要乘的数n：\n");
    scanf("%d",&n);
    fun1(a,n);    
    sum=fun2(a);
    for (i=0; i<N; i++)
    {
        for (j=0; j<N; j++)
        {
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    printf("sum=%-4d",sum);
    return 0;
}