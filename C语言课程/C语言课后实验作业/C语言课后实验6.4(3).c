#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define m 5
#define n 5
int suiji(int x)
{
    int a;
    a=rand();
	x=a%100 + 1;    //设置范围1-100
    return x;
}

void andian(int a[m][n])
{
    int i,j,k,max,t,count=0;  //k存放最大值的列号,count判断鞍点，t表示行号，k表示列号
    for (i=0; i<m; i++)
    {
        for (j=0,k=0,max=a[i][k]; j<n; j++) //在第i行上找出最大值所在的列号
        {
            if(a[i][j]>max)
            {
                max=a[i][j];
                k=j;
            }
        }
        for(t=0;t<n;t++)
        {
            if(a[t][k]<max)
                break;
            if(t==m)
            {
                printf("行号%d，列号%d是鞍点",i,k);
                count++;
            }
            if(0==count)
                printf("没有鞍点");
        }
    }
}

int main()
{
    int a[5][5];
    int x,i,j;
    srand(time(NULL));
    printf("随机生成的数列为：\n");    
    for (i=0; i<5; i++)
    {
        for (j=0; j<5; j++)
        {
            a[i][j]=suiji(x);
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
    andian(a);
    return 0;
}