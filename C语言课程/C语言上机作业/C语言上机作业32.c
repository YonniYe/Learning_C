#include<stdio.h>
int main()
{
    int i,max=0;
    int a[10];
    for(i=0;i<10;i++)
    {
        printf("�������%d������",i+1);
        scanf("%d",&a[i]);
    }
    
    for(i=1;i<10;i++)
        if(a[i]>a[max])
        {
            max=i;
        }
    printf("����������ֵΪ%d�������������±���%d\n",a[max],max);
    return 0;
}