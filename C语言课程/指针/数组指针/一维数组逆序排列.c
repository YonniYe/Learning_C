#include <stdio.h>
void reverse(int a[],int n)
{ 
    int *p;
    for(p=a+n-1; p>=a; p--) //������⣺a���׵�ַ��a+1����a[1]��a+n-1����a[n-1]
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