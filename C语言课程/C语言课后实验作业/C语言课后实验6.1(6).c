#include<stdio.h>
int GCD(int a,int b);
int LCM(int a,int b);
int main()
{
    int n,i,k;
    int a[n];
    printf("������Ҫ�󼸸�������С������(n>2)��");
    scanf("%d",&n);
    printf("---������%d������������С������---\n",n);
    for (i=0; i<n; i++)
    {
        printf("�������%d������",i+1);
        scanf("%d",&a[i]);
    }
    k=LCM(a[0],a[1]);   //�����ǰ����������С������
    for (i = 2; i < n; i++)     //������a[i]������LCM
    {
        k=LCM(k,a[i]);
    }
    printf("��%d��������С������Ϊ%d\n",n,k);
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