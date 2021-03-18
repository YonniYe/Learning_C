#include<stdio.h>
int main()
{
    unsigned int x,y;    //一定要加unsigned！无符号类型能保存2倍于有符号类型的正整数数据！！
    int b[11]={0},a1[10]={0},a2[10]={0},a[20]={0};  //全部数组元素置0，a1[10]、a2[10]分别存放两个整数x、y的各项，a[20]表示总结果
    int i,j,jinwei,m;
    printf("请输入第一个整数：");
    scanf("%ld",&x);
    printf("请输入第二个整数：");
    scanf("%ld",&y);
    for (i = 0; i < 10; i++)
    {
        a1[i]=x%10;
        x=x/10;
    }
    for (j = 0; j<10; j++)
    {
        a2[j]=y%10;
        y=y/10;
    }
    
    for (j=1; j<=10; j++)       //j表示乘法的轮数
    {
        for (i=0, jinwei=0; i<10; i++)  //i从0开始，10位相乘
        {
            m=a2[j-1]*a1[i]+jinwei; //第一轮无进位，故初始为0
            b[i]=m%10;  //b[i]用于保留所乘的数的个位数，余下部分除以10记到jinwei
            jinwei=m/10;
        }
        b[10]=jinwei;   //上一个for循环到i=9结束，而b[10]多出来(如果有)，正好是最后一个jinwei
        for (i=0,jinwei=0; i<11; i++)     //加上上一次的结果，一轮一轮下来就是总值
        {
            a[20-j-i]=a[20-j-i]+b[i]+jinwei;    //注意这里的表达
            jinwei=a[20-j-i]/10;
            a[20-j-i]=a[20-j-i]%10;
        }
    }
    printf("以下是计算结果：\n");
    for (i = 0; i < 20; i++)
    {
        printf("%ld",a[i]);
    }
    return 0;
}