#include<stdio.h>
int fun(int a[],int N)  //N��ԭ���鳤��
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
    return j;   //j�ǲ�ͬ���ֵĸ���
}

void sort(int *a,int n)   //ð������
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
    int count=0,rep=0,i,j,t=0;    //countΪ������Ԫ�صĸ���,numΪԪ���ܸ���
    for (i=0; i<5; i++)
    {
        for (j=1; j<6; j++)
        {
            res[t++]=sec[i][j];   //��ά���鲿�ָ�ֵʱδ��ֵ���Զ���0
        }
    }
    sort(res,25);  //�����ж�ά�����Ԫ�طŵ�һ��һά�����ͨ��sort������������
    count=fun(res,25);     //ͨ��fun���������һά������������ͬ�����ָ�ɾ����
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