#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define m 5
#define n 5
int suiji(int x)
{
    int a;
    a=rand();
	x=a%100 + 1;    //���÷�Χ1-100
    return x;
}

void andian(int a[m][n])
{
    int i,j,k,max,t,count=0;  //k������ֵ���к�,count�жϰ��㣬t��ʾ�кţ�k��ʾ�к�
    for (i=0; i<m; i++)
    {
        for (j=0,k=0,max=a[i][k]; j<n; j++) //�ڵ�i�����ҳ����ֵ���ڵ��к�
        {
            if(a[i][j]>max)
            {
                max=a[i][j];
                k=j;
            }
        }
        for(t=0;t<n;t++)
        {
            if(a[t][k]<max)
                break;
            if(t==m)
            {
                printf("�к�%d���к�%d�ǰ���",i,k);
                count++;
            }
            if(0==count)
                printf("û�а���");
        }
    }
}

int main()
{
    int a[5][5];
    int x,i,j;
    srand(time(NULL));
    printf("������ɵ�����Ϊ��\n");    
    for (i=0; i<5; i++)
    {
        for (j=0; j<5; j++)
        {
            a[i][j]=suiji(x);
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
    andian(a);
    return 0;
}