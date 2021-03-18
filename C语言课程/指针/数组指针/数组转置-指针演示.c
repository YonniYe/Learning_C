#include <stdio.h>
void fun(int (*p1)[3],int (*p2)[3]);
int main()
{
    int p1[3][3]={{7,8,9},{4,5,6},{1,2,3}} ;
    int p2[3][3] = {0};     //p2用于储存转置后的数组
    int i = 0, j = 0;
    fun(p1,p2);
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",*(*(p2+i)+j));    //*(*(p+i)+j)完全等价p[i][j]
        }
    printf("\n");
    }        
    return 0;
}

void fun(int (*p1)[3],int (*p2)[3])     //观察一下这里如何定义形参，二维数组需要int (*p)[]
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            *(p2[j]+i) = *(p1[i]+j);    //指针用于通过地址传递数值
        }
    }
}