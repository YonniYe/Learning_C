#include <stdio.h>
void reverse(int a[],int n)
{ 
    int *p;
    for(p=a+n-1; p>=a; p--) //这样理解：a是首地址，a+1就是a[1]，a+n-1就是a[n-1]
        printf("%4d",*p);
    printf("\n");
}
int main()
{ 
    int a[20],n;
    int i;
    printf("Input the length of array:");
    scanf("%d",&n);
    printf("Input the number of array:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    reverse(a,n);
}