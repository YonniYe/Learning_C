#include <stdio.h>
int main()
{
    int len,*p0,*p1,n;
    int a[10],i;
    len=sizeof(a) / sizeof(int);
    p0=&a[0];   //指向数组的首地址
    p1=&a[len-1];   //指向数组的尾地址
    for (i=0; i<10; i++)
    {
        printf("请输入a[%d]的值:",i);
        scanf("%d",&a[i]);
    }
    printf("倒置前的数组:");
    for (i=0; i<10; i++)
    {
        printf("%3d",a[i]);
    }
    while(1)    //两个指针同时向中间移动直到相遇
    {
        n=*p1;
        *p1=*p0;
        *p0=n;
        p0++;
        p1--;
        if(p1<=p0)  //数组元素为奇数个取等号，否则是小于号
            break;
    }
    printf("\n倒置后的数组:");
    for (i=0; i<10; i++)
    {
        printf("%3d",a[i]);
    }
    return 0;
}