#include<stdio.h>
int main()
{
    int a[10];
    int low=0,high=9,flag=0,i,mid,t; //t是所要查询的数，i是个数，flag是判断数组中有无所查询的数
    printf("请按递增顺序输入以下10个数\n"); 
    for ( i = 0; i < 10; i++)
    {
        printf("请输入第%d个数：",i+1);
        scanf("%d",&a[i]);
    }
    printf("输入要查询的数：");
    scanf("%d",&t);

    while(low<=high)    //注意这里是小于等于！！！
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
        printf("要查询的数在%d位置\n",mid+1);
    else
        printf("所要查询的数不在数组范围内！\n");
    return 0;
}