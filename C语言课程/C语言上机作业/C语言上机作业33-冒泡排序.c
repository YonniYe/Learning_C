#include<stdio.h>
int main()
{
    int i,j,t;
    int a[10];
    for (i=0; i<10; i++)
    {
        printf("请输入第%d个数：",i+1);
        scanf("%d",&a[i]);
    }
    printf("\n排序前：");
    for (i=0; i<10; i++)
    {
        printf("%-4d",a[i]);
    }
    printf("\n");    
    //以下是冒泡排序
    for (i=0; i<9; i++)    //i表示排序的次数，j是数组下标
    {
        for (j=0; j<9-i; j++)
        {
            if (a[j]>a[j+1])    //如果前者大于后者，就交换顺序
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
            
        }
        
    }
    printf("排序后：");
    for (i=0; i<10; i++)
    {
        printf("%-4d",a[i]);
    }
    printf("\n");
    return 0;
}