/*模拟一个简单的计算器，利用函数指针作为函数参数，对两个整数计算“最大公约数”、“最小公倍数”两种运算的一种，
通过主程序中输入两个整数和数字1-2分别对应“最大公约数”、“最小公倍数”运算。*/
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
    printf("请输入两个整数：");
    scanf("%d%d", &a, &b);
    printf("输入1则计算最大公约数，输入2则计算最小公倍数：");
    scanf("%d", &i);
    printf("计算结果为：%d\n",(*p[i])(a,b));
    return 0;
}