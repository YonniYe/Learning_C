#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int suiji(int x)    //生成随机数
{
    int a;
    a=rand();
	x=a%9+1;    //设置范围1-9
    return x;
}

int main()
{
    int a[11][11]={0};
    int i,j,k,num; //i是行，j是列,
    srand(time(NULL));
    for (k=0; k<10; k++)    //随机10个雷(但是有可能会有几个雷重叠)
    {
        i=suiji(k);
        j=suiji(k);
        a[i][j]=-1;
    }
    printf("随机生成的矩阵为：\n");
    for (i=1; i<10; i++)
    {
        for (j=1; j<10; j++)
        {
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }

    printf("\n\n“雷”的分布矩阵为：\n");
    for (i=1; i<10; i++)
    {
        for (j=1; j<10; j++)
        {
            if(a[i][j]==0)  //在非“雷”位置逐个判断周围8个数中是否有雷，有雷就让计数器加一
            {
                num=0;
                if(a[i-1][j-1]==-1)
                    num++;
                if(a[i-1][j]==-1)
                    num++;
                if(a[i-1][j+1]==-1)
                    num++;
                if(a[i][j-1]==-1)
                    num++;
                if(a[i][j+1]==-1)
                    num++;
                if(a[i+1][j-1]==-1)
                    num++;
                if(a[i+1][j]==-1)
                    num++;
                if(a[i+1][j+1]==-1)
                    num++;
                a[i][j]=num;
            }
        }
    }

    for (i=1; i<10; i++)
    {
        for (j=1; j<10; j++)
        {
            if(a[i][j]==-1) //让所有的“雷”的值由-1变为15
                {
                    a[i][j]=15;
                    printf("%3c",a[i][j]);  //以%c形式输出，打印“雷”
                }
            else
                printf("%3d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}