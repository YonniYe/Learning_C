#include<stdio.h>
int main()
{
    int i,j,t,min;  //i��ʾ��������ĩβλ�ú�ִ�д�����j��ʾ����������ʼλ�ã�min��ʾ����������СԪ��λ��
    int a[10];
    for ( i = 0; i < 10; i++)
    {
        printf("�������%d������",i+1);
        scanf("%d",&a[i]);
    }
    printf("\n����ǰ��");
    for ( i = 0; i < 10; i++)   //�������ǰ���б�
    {
        printf("%-4d",a[i]);
    }
    printf("\n");
    //������ѡ������
    for (i = 0; i < 10; i++)
    {
        min=i;
        for (j = i+1; j < 10; j++)   //��"a[i+1]..a[10]"֮����СԪ�أ�������min
        {
            if (a[j]<a[min])
            {
                min=j;
            }
            
        }
        if(min != i)    //��min!=i���򽻻� a[i] �� a[min]�������󼴱�֤a[0]..a[i]֮��Ԫ������
        {
            t=a[i];
            a[i]=a[min];
            a[min]=t;
        }
    }
    printf("�����");
    for ( i = 0; i < 10; i++)   //����������б�
    {
        printf("%-4d",a[i]);
    }
    printf("\n");
    return 0;
}