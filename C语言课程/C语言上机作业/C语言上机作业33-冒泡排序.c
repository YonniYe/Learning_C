#include<stdio.h>
int main()
{
    int i,j,t;
    int a[10];
    for (i=0; i<10; i++)
    {
        printf("�������%d������",i+1);
        scanf("%d",&a[i]);
    }
    printf("\n����ǰ��");
    for (i=0; i<10; i++)
    {
        printf("%-4d",a[i]);
    }
    printf("\n");    
    //������ð������
    for (i=0; i<9; i++)    //i��ʾ����Ĵ�����j�������±�
    {
        for (j=0; j<9-i; j++)
        {
            if (a[j]>a[j+1])    //���ǰ�ߴ��ں��ߣ��ͽ���˳��
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
            
        }
        
    }
    printf("�����");
    for (i=0; i<10; i++)
    {
        printf("%-4d",a[i]);
    }
    printf("\n");
    return 0;
}