#include<stdio.h>
int max(int *a,int i)   //����ί����߷�
{
    int x;
    for (i = 0; i < 10; i++)
    {
        if(a[0] < a[i])
        a[0] = a[i];
    }
    x=a[0];
    return x;
}

int min(int *a,int i)   //����ί����ͷ�
{
    int x;
    for ( i = 0; i < 10; i++)
    {
        if(a[0]>a[i])
        a[0]=a[i];
    }
    x=a[0];
    return x;
}

int main()
{
    int i,sum=0;    //i���±꣬sum��ָδȥ����߷ֺ���ͷֵ��ܵ÷�
    float average;  //ƽ������float������
    int a[10];  //���ﶨ����ί����ķ�����������
    for(i=0;i<10;i++)
    {
        printf("�������%d����ί���ķ�����",i+1);
        scanf("%d",&a[i]);
    }
    printf("��ί��������߷�Ϊ%d\n",max(a,10));    
    printf("��ί��������ͷ�Ϊ%d\n",min(a,10));
    for (i = 0; i < 10; i++)
    {
        sum+=a[i];
    }
    average=(sum-max(a,10)-min(a,10))*1.0/8.0;
    printf("ȥ����߷֡���ͷֺ���õ�ƽ����Ϊ��%.2f",average);
    return 0;
}