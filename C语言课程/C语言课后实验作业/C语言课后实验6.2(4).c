#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int suiji(int x)    //生成随机数
{
    int a;
    a=rand();
	x=a%80 + 1;    //以1-80的范围为例
    return x;
}

int sushu(int n)
{
    int i,flag;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
            flag=0;
            break;
        }
        else 
            flag=1;
    }
    return flag;
}

int main()
{
    int i,j,t,m,count=0;    //i是行；j是列；t用于表示某个M[i][j]的值；m用于表示t后面的那个素数 ;count是计数器
    int M[4][4];
    srand(time(NULL));
    printf("变换前的的随机数列为：\n");    
    for (i=0; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            M[i][j]=suiji(i);
            printf("%4d",M[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    for (i=1; i<4; i++) //2-4行
    {
        for (j=0; j<3; j++) //1-3列
        {
            t=M[i][j];
            if (sushu(t)==0)    //如果flag为0，就不是素数，赋值为0
                M[i][j]=0;
            else
            {
                for(m=t+1;m<80;m++)
                {
                    if (sushu(m)==1)
                    {
                        M[i][j]=m;
                        break;
                    }
                }
                count++;
            }
        }
    }
    printf("变换后的的数列为：\n");    
    for (i=0; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            printf("%4d",M[i][j]);
        }
        printf("\n");
    }
    printf("数组左下三角的元素中素数个数为%d",count);
    return 0;
}
