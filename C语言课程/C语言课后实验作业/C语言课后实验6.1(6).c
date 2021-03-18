#include<stdio.h>
int GCD(int a,int b);
int LCM(int a,int b);
int main()
{
    int n,i,k;
    int a[n];
    printf("请输入要求几个数的最小公倍数(n>2)：");
    scanf("%d",&n);
    printf("---以下求%d个正整数的最小公倍数---\n",n);
    for (i=0; i<n; i++)
    {
        printf("请输入第%d个数：",i+1);
        scanf("%d",&a[i]);
    }
    k=LCM(a[0],a[1]);   //先算出前两个数的最小公倍数
    for (i = 2; i < n; i++)     //往后与a[i]逐项求LCM
    {
        k=LCM(k,a[i]);
    }
    printf("这%d个数的最小公倍数为%d\n",n,k);
    return 0;
}


int GCD(int a, int b)
{
    if (b==0) 
        return a;
    return GCD(b, a%b);
}

int LCM(int a,int b)
{
    int result;
    result=(a*b)/GCD(a,b);
    return result;
}