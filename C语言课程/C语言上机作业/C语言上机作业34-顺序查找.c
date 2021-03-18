# include <stdio.h>
int main()
{
    int a[10] = {1,5,66,8,55,9,32,65,8,7,215};
    int n,k,i;  //n是存放数组a中元素的个数，k是所要查找的数字，i是下标
    n = sizeof(a) / sizeof(int);  //n是数组中所有元素的个数
    printf("已定义的数组a为{1,5,66,8,55,9,32,65,8,7,215,343}\n");
    printf("请输入一个数字K:");
    scanf("%d", &k);
    for (i=0; i<n; ++i) //顺序查找
    {
        if (a[i] == k)
        {
            printf("数字%d所在数组中的下标为%d\n",k,i);
            break;
        }
    } 
    if (i==n)
    {
        printf("对不起，您所输入的数字%d不在此数组中\n",k);
    }
    return 0;
}