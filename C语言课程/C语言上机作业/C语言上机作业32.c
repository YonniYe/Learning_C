#include<stdio.h>
int main()
{
    int i,max=0;
    int a[10];
    for(i=0;i<10;i++)
    {
        printf("请输入第%d个数：",i+1);
        scanf("%d",&a[i]);
    }
    
    for(i=1;i<10;i++)
        if(a[i]>a[max])
        {
            max=i;
        }
    printf("输出的最大数值为%d，其所在数组下标是%d\n",a[max],max);
    return 0;
}