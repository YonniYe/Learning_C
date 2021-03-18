#include<stdio.h>
int t=0;    //不得已把t定义为了全局变量，这样aa[t]的值就能从countvalue中直接带到main函数里
int sushu(int n)
{
    int i,flag=1;
    for(i=2; i<=n/2; ++i)    //判断素数
    {
        if (n%i==0)
        {
            flag=0;    //能被整除的，就令flag=0。(flag=0的就不是素数)
            break;
        }
    }
    return flag;
}

int countvalue(int aa[])
{
    int flag,i,cnt=0;
    for(i=500;i<=800;i++)
    {
        flag=sushu(i);
        if(flag==1)
        {
            aa[t]=i;
            t++;
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int cnt,i,aa[300];
    for (i=0; i<300; i++)
    {
        aa[i]=500+i;
    }
    cnt=countvalue(aa);
    for (t=0; t<cnt; t++)
    {
        printf("%5d",aa[t]);
        if((t+1)%10==0)    //每输出10次输出换行
            printf("\n");
    }
    return 0;
}