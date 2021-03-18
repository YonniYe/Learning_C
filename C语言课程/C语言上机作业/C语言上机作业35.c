#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int suiji(int x)
{
    int a;
    a=rand();
	x=a%200 + 1;    //设置范围1-200
    return x;
}

int main()
{
    int a[10];
    int k,x,i;
    srand(time(NULL));
    printf("随机生成的数列为：");    
    for (i = 0; i < 10; i++)
    {
        a[i]=suiji(x);
        printf("%d  ",a[i]);
    }
    printf("\n请输入要删除的数：");
    scanf("%d",&k);
    for (i=0; i<10; ++i) //顺序查找
    {
        if (a[i] == k)
        {
            a[i]=0;
        }
    } 
    printf("删除数字后的数列为：");        
    for (i = 0; i < 10; i++)
    {
        if(a[i]!=0)
            printf("%d  ",a[i]);
    }
    return 0;
}