#include <stdio.h>
#define M 10
#define N 10
void sort(int *a,int n)   //冒泡排序
{
    int i,j,t;
    for (i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
}

int com(int *a, int *b, int *c)
{
    int i,j,count=0;
    for (i=0; i<M; i++) //将a[i]的所有元素插入进*(c+i),再在每一个a[i]后插入b[j],两两比较
    {
        c[2*i] = a[i];
        c[2*i+1] = b[i];
    }
    sort(c,M+N); 
    for (i=0; i<M+N; i++)
    {
        if (*(c+i)==*(c+i+1)) 
        {
            count++;
            for (j=i; j<M+N-1; j++)
                *(c+j) = *(c+j+2);
        }
    }    
    return count;   
}


int main()
{
    int a[M] = {3, 6, 7, 18, 23, 33, 35, 43, 48, 78};
    int b[N] = {2, 7, 13, 21, 33, 37, 48, 50, 58, 67};
    int c[M+N]= {0};
    int i, count=0;
    printf("【测试数据】\n数组a：");
    for (i=0; i<M; i++)
    {
        printf("%-3d",*(a+i));
    }
    printf("\n数组b：");
    for (i=0; i<N; i++)
    {
        printf("%-3d",*(b+i));
    }
    count = com(a, b, c);
    printf("\n【运行结果】\n");
    for (i=0; i<M+N-2*count; i++)   //数组c里面有（M+N-2*count）个元素
        printf("%d ", *(c+i));
    printf("\ncount=%d ", count);
    return 0;
}