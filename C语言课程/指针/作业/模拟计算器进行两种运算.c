/*ģ��һ���򵥵ļ����������ú���ָ����Ϊ�����������������������㡰���Լ����������С�����������������һ�֣�
ͨ����������������������������1-2�ֱ��Ӧ�����Լ����������С�����������㡣*/
#include<stdio.h>
int GCD(int a, int b)
{
    if(b==0)
        return a;
    else
        return GCD(b, b%a);
}

int LCM(int a, int b)
{
    int result;
    result = (a*b) / GCD(a, b);
    return result;
}
int main()
{
    int (*p[2])(int,int)={GCD,LCM};
    int a,b,i;
    printf("����������������");
    scanf("%d%d", &a, &b);
    printf("����1��������Լ��������2�������С��������");
    scanf("%d", &i);
    printf("������Ϊ��%d\n",(*p[i])(a,b));
    return 0;
}