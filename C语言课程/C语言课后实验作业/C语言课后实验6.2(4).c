#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int suiji(int x)    //���������
{
    int a;
    a=rand();
	x=a%80 + 1;    //��1-80�ķ�ΧΪ��
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
    int i,j,t,m,count=0;    //i���У�j���У�t���ڱ�ʾĳ��M[i][j]��ֵ��m���ڱ�ʾt������Ǹ����� ;count�Ǽ�����
    int M[4][4];
    srand(time(NULL));
    printf("�任ǰ�ĵ��������Ϊ��\n");    
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

    for (i=1; i<4; i++) //2-4��
    {
        for (j=0; j<3; j++) //1-3��
        {
            t=M[i][j];
            if (sushu(t)==0)    //���flagΪ0���Ͳ�����������ֵΪ0
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
    printf("�任��ĵ�����Ϊ��\n");    
    for (i=0; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            printf("%4d",M[i][j]);
        }
        printf("\n");
    }
    printf("�����������ǵ�Ԫ������������Ϊ%d",count);
    return 0;
}
