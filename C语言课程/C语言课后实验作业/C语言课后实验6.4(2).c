#include<stdio.h>
void midsearch(int a[10])
{
    int low=0,high=9,flag=0,mid,t; //t����Ҫ��ѯ������i�Ǹ�����flag�ж���������������ѯ����
    printf("\n������Ҫ��ѯ������");
    scanf("%d",&t);
    while(low<=high)
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
        printf("��Ҫ��ѯ����%d����������±���%d\n",t,mid);
    else
        printf("��Ҫ��ѯ�����������鷶Χ�ڣ�\n");
}

int main()
{
    int a[10];
    int i;
    printf("����ذ�����˳����������10������\n"); 
    for (i=0; i<10; i++)
    {
        printf("�������%d������",i+1);
        scanf("%d",&a[i]);
    }
    printf("\n������������ǣ�\n");
    for (i=0; i<10; i++)
    {
        printf("%-4d",a[i]);
    }
    midsearch(a);
    return 0;
}