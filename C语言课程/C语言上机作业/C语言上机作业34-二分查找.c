#include<stdio.h>
int main()
{
    int a[10];
    int low=0,high=9,flag=0,i,mid,t; //t����Ҫ��ѯ������i�Ǹ�����flag���ж���������������ѯ����
    printf("�밴����˳����������10����\n"); 
    for ( i = 0; i < 10; i++)
    {
        printf("�������%d������",i+1);
        scanf("%d",&a[i]);
    }
    printf("����Ҫ��ѯ������");
    scanf("%d",&t);

    while(low<=high)    //ע��������С�ڵ��ڣ�����
    {
        mid=(low+high)/2;   //midָ�����ݿ������ڵ�������λ��
        if(t==a[mid])   //�ҵ��˾��ж�Ϊ�棬ʹflag==1
        {
            flag=1;
            break;
        }
        if(t>a[mid])    //�����Ͼ͸ı�����
            low=mid+1;
        else
            high=mid-1;
    }

    if(flag==1)
        printf("Ҫ��ѯ������%dλ��\n",mid+1);
    else
        printf("��Ҫ��ѯ�����������鷶Χ�ڣ�\n");
    return 0;
}