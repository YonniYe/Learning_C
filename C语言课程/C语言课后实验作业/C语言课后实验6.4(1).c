#include<string.h>
#include<stdio.h>
void upstr(int a[10])   //冒泡升序
{
    int i,j,t;  //i表示排序的次数，j是数组下标，t是中间数
    for (i=0; i<9; i++)    
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
        printf("%-3d",a[i]);
    }
}

int main()
{
    int a[10];
    int i;
    for(i=0;i<10;i++)
    {
        printf("请输入第%d个数：",i+1);
        scanf("%d",&a[i]);
    }
    printf("\n排序前：");
    for (i=0; i<10; i++)
    {
        printf("%-3d",a[i]);
    }
    printf("\n");   
    upstr(a);
    return 0;
}