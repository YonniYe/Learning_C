#include<stdio.h>
void Swap(int *p1,int *p2)
{
    int tmp= *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int main()
{
    int a=3,b=4;
    int *p1,*p2;
    p1=&a;
    p2=&b;
    Swap(p1,p2);
    printf("%d,%d\n",a,b);
    printf("%d,%d\n",*p1,*p2);
    return 0;
}