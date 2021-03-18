#include<stdio.h>
int fun(int a[],int N)  //N是原数组长度
{
    int i,j=1;
    for(i=1; i<N; i++) 
    {
        if(a[j-1] != a[i])  
        {
            a[j] = a[i]; 
            j++;
        }
    }
    return j;   //j是不同数字的个数
}

void sort(int *a,int n)   //冒泡排序
{
    int i,j,t;
    for (i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
}

int Union(int(*sec)[6],int res[25])
{
    int count=0,rep=0,i,j,t=0;    //count为并集中元素的个数,num为元素总个数
    for (i=0; i<5; i++)
    {
        for (j=1; j<6; j++)
        {
            res[t++]=sec[i][j];   //二维数组部分赋值时未赋值的自动赋0
        }
    }
    sort(res,25);  //将所有二维数组的元素放到一个一维数组里，通过sort函数进行排序
    count=fun(res,25);     //通过fun函数将这个一维数组里所有相同的数字给删除掉
    return count;
}

int main()
{
    int sec[5][6]={{4,12,35,3,9},{3,2,35,9},{5,35,12,0,1,9},{1,90},{2,9,0}};
    int res[25]={0};
    int count,i;
    count=Union(sec,res);
    for (i=0; i<count; i++)
        printf("%4d",res[i]);
    return 0;
}