#include <stdio.h>
#define N 80
int fun(int a[],int n)
{
    int i,j=1;
    for(i=1; i<n; i++)  //这里的n是原数组长度
    {
        if(a[j-1] != a[i])  //刚开始是将a[0]和a[1]进行比较，然后i递增，直到a[0]和a[i]不等时，就把a[i]赋值给a[j]，j++。也就是说j是不同数字的个数
        {
            a[j] = a[i]; 
            j++;
        }
    }
    return j;
}

int main()
{    
    int i,n=21;
    int a[N]={2,2,2,3,4,4,5,6,6,6,6,7,7,8,9,9,10,10,10,10,11};
    printf("The original data:\n");
    for(i=0;i<n;i++) 
        printf("%3d",a[i]);
    n=fun(a,n);     //改变了数组长度
    printf("\nThe data after deleted:\n");
    for(i=0;i<n;i++)    //这里数组a[]和长度n都改变了
        printf("%3d",a[i]);
    printf("\n\n");
    return 0;
}