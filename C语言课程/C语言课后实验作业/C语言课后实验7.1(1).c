#include<stdio.h>
int count1,count2,count3;   //count1是正数，count2是负数，count3是0
void judge(int *p)
{
    int i;
    if(p[i]>0)
        count1++;
    else if(p[i]<0)
        count2++;
    else
        count3++;
}

int main()
{
    int i,a[10],*p=NULL;
    p=a;
    printf("请分别输入10个整数：\n");
    for (i=0; i<10; i++)
    {
        printf("请输入第%d个数：",i+1);
        scanf("%d",p+i);
    }
    for (i=0; i<10; i++)
    {
        judge(p[i]);
    }
    
    printf("正数个数为%d，负数个数为%d，0的个数为%d",count1,count2,count3);
    return 0;
}