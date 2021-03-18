#include<stdio.h>
int max(int *a,int i)   //找评委中最高分
{
    int x;
    for (i = 0; i < 10; i++)
    {
        if(a[0] < a[i])
        a[0] = a[i];
    }
    x=a[0];
    return x;
}

int min(int *a,int i)   //找评委中最低分
{
    int x;
    for ( i = 0; i < 10; i++)
    {
        if(a[0]>a[i])
        a[0]=a[i];
    }
    x=a[0];
    return x;
}

int main()
{
    int i,sum=0;    //i是下标，sum是指未去除最高分和最低分的总得分
    float average;  //平均分用float定义了
    int a[10];  //这里定义评委输入的分数都是整数
    for(i=0;i<10;i++)
    {
        printf("请输入第%d个评委评的分数：",i+1);
        scanf("%d",&a[i]);
    }
    printf("评委所评的最高分为%d\n",max(a,10));    
    printf("评委所评的最低分为%d\n",min(a,10));
    for (i = 0; i < 10; i++)
    {
        sum+=a[i];
    }
    average=(sum-max(a,10)-min(a,10))*1.0/8.0;
    printf("去除最高分、最低分后算得的平均分为：%.2f",average);
    return 0;
}