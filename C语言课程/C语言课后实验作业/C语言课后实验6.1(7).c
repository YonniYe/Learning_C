#include<stdio.h>
void insort(int *a,int n)   //n是数组中包含的个数
{
    int i,j,t;
    for(i=1; i<n; i++)  //步骤6——重复步骤2-5
    {
        t = a[i];    //t是要比较的值(新元素)，从第二个元素开始
        j = i-1;    //j从第一个元素(a[0])开始，a[j]被认为已排序
        while(a[j]>t && j>=0)    //步骤4——重复步骤3，从后向前扫描，直到出现比t大的值，或直到j=0(此时a[j]在数组第一项)
        {
            a[j+1] = a[j];  //步骤3——将该元素(已排序)往后移一位
            j--;
        }
        a[j+1] = t;  //步骤5——新元素t插在a[j]的后面(下一位置)
    }
}

int main()
{
    int a[10];
    int i;
    for (i=0; i<10; i++)
    {
        printf("请输入第%d个数：",i+1);
        scanf("%d",&a[i]);
    }
    printf("\n排序前：");
    for (i=0; i<10; i++)
    {
        printf("%d  ",a[i]);
    }
    insort(a,10);
    printf("\n使用直接插入排序法排序后：");
    for (i = 0; i < 10; i++)
    {
        printf("%d  ",a[i]);
    }
    return 0;
}