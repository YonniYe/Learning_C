#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int suiji(int x)    //生成随机数
{
    int a;
    a=rand();
	x=a%200 + 1;    //设置范围1-200
    return x;
}

void insert(int *a,int n,int i,int k)   //n是数组中元素个数，k是插入的数,i是要插入的位置
{
    int j;  //j用于将每个元素往后移一位，即让a[j+1]=a[j]
    for (j=n;j>=i;j--)
    {
        a[j+1]=a[j];
    }
    a[i+1]=k;   //i从0开始，故插入到i+1后
}

int main()
{
    int a[10];
    int k,x,i,t;
    srand(time(NULL));
    printf("随机生成的数组为：");    
    for (i = 0; i < 9; i++)
    {
        a[i]=suiji(x);
        printf("%d  ",a[i]);
    }
    printf("\n请输入要插入的数：");
    scanf("%d",&k);
    printf("请问要将%d插入在a[?]后(可输入0~9)：",k);
    scanf("%d",&t);
    insert(a,9,t,k);   //排序后的数组 
    printf("插入后的数组为：");
    for (i=0;i<10;i++)
        printf("%d  ",a[i]); 
    return 0;
}

