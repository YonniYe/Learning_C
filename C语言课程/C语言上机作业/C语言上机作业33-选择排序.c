#include<stdio.h>
int main()
{
    int i,j,t,min;  //i表示有序区的末尾位置和执行次数，j表示无序区的起始位置，min表示无序区中最小元素位置
    int a[10];
    for ( i = 0; i < 10; i++)
    {
        printf("请输入第%d个数：",i+1);
        scanf("%d",&a[i]);
    }
    printf("\n排序前：");
    for ( i = 0; i < 10; i++)   //输出排序前的列表
    {
        printf("%-4d",a[i]);
    }
    printf("\n");
    //以下是选择排序
    for (i = 0; i < 10; i++)
    {
        min=i;
        for (j = i+1; j < 10; j++)   //找"a[i+1]..a[10]"之间最小元素，并赋给min
        {
            if (a[j]<a[min])
            {
                min=j;
            }
            
        }
        if(min != i)    //若min!=i，则交换 a[i] 和 a[min]。交换后即保证a[0]..a[i]之间元素有序。
        {
            t=a[i];
            a[i]=a[min];
            a[min]=t;
        }
    }
    printf("排序后：");
    for ( i = 0; i < 10; i++)   //输出排序后的列表
    {
        printf("%-4d",a[i]);
    }
    printf("\n");
    return 0;
}