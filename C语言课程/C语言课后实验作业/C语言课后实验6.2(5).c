#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int suiji(int x)    //���������
{
    int a;
    a=rand();
	x=a%9+1;    //���÷�Χ1-9
    return x;
}

int main()
{
    int a[11][11]={0};
    int i,j,k,num; //i���У�j����,
    srand(time(NULL));
    for (k=0; k<10; k++)    //���10����(�����п��ܻ��м������ص�)
    {
        i=suiji(k);
        j=suiji(k);
        a[i][j]=-1;
    }
    printf("������ɵľ���Ϊ��\n");
    for (i=1; i<10; i++)
    {
        for (j=1; j<10; j++)
        {
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }

    printf("\n\n���ס��ķֲ�����Ϊ��\n");
    for (i=1; i<10; i++)
    {
        for (j=1; j<10; j++)
        {
            if(a[i][j]==0)  //�ڷǡ��ס�λ������ж���Χ8�������Ƿ����ף����׾��ü�������һ
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
            if(a[i][j]==-1) //�����еġ��ס���ֵ��-1��Ϊ15
                {
                    a[i][j]=15;
                    printf("%3c",a[i][j]);  //��%c��ʽ�������ӡ���ס�
                }
            else
                printf("%3d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}