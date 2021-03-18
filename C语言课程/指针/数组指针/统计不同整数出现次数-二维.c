#include<stdio.h>
void findcount(int *a, int N)
{
    int i,t;
    for (i=0; i<N; i++)
    {
        t=a[i];
        printf("统计输出 %d 出现次数 %d \n",i,t);
    }
    
}
int main()
{    
    int i,j,x,t;  //x表示a[i][j]的值
    int a[4][4]={{8,8,8,7},{6,8,5,7},{6,8,8,7},{8,8,7,7}};
    int num[11]={0};    //num表示统计的数字
    for(i=0; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            x=a[i][j];
            num[x]++;
        }
    }
    findcount(num,10);
    return 0;
}