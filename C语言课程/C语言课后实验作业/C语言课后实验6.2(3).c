#include<stdio.h>
int main()
{
    int a,i,j,k;  //a是魔方阵的行数，为奇数 ; i是行；j是列；k用于计数
    int M[20][20];    //规定M大小(以20为例)
    printf("请输入魔方阵的阶数(必须是正奇数):");
    scanf("%d",&a);
    for (i=0; i<a; i++)   //初始化全为0
    {
        for (j=0; j<a; j++)
        {
            M[i][j]=0;
        }
    }
    M[0][(a-1)/2]=1;    //第一行的中间放1
    i=0;
    j=(a-1)/2;
    for(k=2;k<=(a*a);k++)
    {
        i=i-1;    //下一个数在当前数的上面一行
        j=j+1;    //下一个数在当前数的后面一列
        if((i<0)&&(j==a))   //第一种情况——如果当前数在第一行(i=0)最右侧(j=a-1)时,
        {
            i=i+2;  //下一个数在它下面一行(也就是令i=1)
            j=j-1;  //列数不变(也就是j=a-1)
        }
        else if((i<0)&&(j<a))   //第二种情况——如果当前数在第一行(i=0)，但不在最右侧(j<a-1)
        {
            i=a-1;  //下一个数在最后一行（列数在循环开始时已加过1了）
        }
        else if((i>=0)&&(j==a))    //第三种情况——如果当前数不在第一行(i>=0)，但在其他行的最右侧（第a列(j=a-1)）
        {
            j=0;    //下一个数在最左侧一列（行数在循环开始时已减过1了）
        } 
        else;
        if(M[i][j]==0)     //如果该元素为0,继续执行程序
            M[i][j]=k;
        else  //如果该元素不为0,就说明要填的数的位置已经被占,则下一个数放在当前数的下面
        {
            i=i+2;  //循坏开始i已经减过1了，加2让下一个数去当前数下一行
            j=j-1;  //同理，下一个数和当前数列数不变
            M[i][j]=k;
        }
    }
    for(i=0;i<a;i++)
    {
        for(j=0;j<a;j++)       
            printf("%4d",M[i][j]);
        printf("\n");   //每输出一行就换一次行
    }
    return 0;
}
