#include<stdio.h>
#include<stdlib.h>
int fun(int *a, int n)
{
    int i,j;
    int sum=0;
    for (i=0;i<n;i++)
    {
        for (j=i;j<n;j++)
        {
            sum = sum + a[i*n+j];
        }
    }
    return sum;
}
int main()
{
    int a[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int n=4,i,j;
    for (i=0; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    printf("右上三角连同对角线的和为%d",fun(a,n));
    return 0;
}