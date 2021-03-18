#include<stdio.h>
int main()
{    
    int i,count,t,x;
    int a[16]={8,8,8,7,6,8,5,7,6,8,8,7,8,8,7,7};
    int num[11]={0};
    for (i=0; i<16; i++)
    {
        printf("%-3d",a[i]);
    }
    printf("\n");
    for(count=0; count<16; count++)     //a[count]用于遍历a[16]
    {
        x=a[count];   //a[count]用于遍历数组中每一个值
        num[x]++;    //a[count]取到值x时，num[x]就自加一次
    }
    for(i=0; i<10; i++)     //i用于表示0~9每个数字
    {
        t=num[i];   //这里t用于表示0~9每个数字出现的次数
        printf("统计输出 %d 出现次数 %d \n",i,t);
    }
    return 0;
}