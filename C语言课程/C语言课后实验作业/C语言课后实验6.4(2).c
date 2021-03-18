#include<stdio.h>
void midsearch(int a[10])
{
    int low=0,high=9,flag=0,mid,t; //t是所要查询的数，i是个数，flag判断数组中有无所查询的数
    printf("\n请输入要查询的数：");
    scanf("%d",&t);
    while(low<=high)
    {
        mid=(low+high)/2;   //mid指向数据可能所在的区间中位置
        if(t==a[mid])   //找到了就判断为真，使flag==1
        {
            flag=1;
            break;
        }
        if(t>a[mid])    //不符合就改变区间
            low=mid+1;
        else
            high=mid-1;
    }
    if(flag==1)
        printf("所要查询的数%d在数组里的下标是%d\n",t,mid);
    else
        printf("所要查询的数不在数组范围内！\n");
}

int main()
{
    int a[10];
    int i;
    printf("请务必按递增顺序输入以下10个整数\n"); 
    for (i=0; i<10; i++)
    {
        printf("请输入第%d个数：",i+1);
        scanf("%d",&a[i]);
    }
    printf("\n所输入的数组是：\n");
    for (i=0; i<10; i++)
    {
        printf("%-4d",a[i]);
    }
    midsearch(a);
    return 0;
}