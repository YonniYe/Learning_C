#include<stdio.h>
int t=0;    //�����Ѱ�t����Ϊ��ȫ�ֱ���������aa[t]��ֵ���ܴ�countvalue��ֱ�Ӵ���main������
int sushu(int n)
{
    int i,flag=1;
    for(i=2; i<=n/2; ++i)    //�ж�����
    {
        if (n%i==0)
        {
            flag=0;    //�ܱ������ģ�����flag=0��(flag=0�ľͲ�������)
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
        if((t+1)%10==0)    //ÿ���10���������
            printf("\n");
    }
    return 0;
}