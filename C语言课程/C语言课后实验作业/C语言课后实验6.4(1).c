#include<string.h>
#include<stdio.h>
void upstr(int a[10])   //ð������
{
    int i,j,t;  //i��ʾ����Ĵ�����j�������±꣬t���м���
    for (i=0; i<9; i++)    
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
        printf("%-3d",a[i]);
    }
}

int main()
{
    int a[10];
    int i;
    for(i=0;i<10;i++)
    {
        printf("�������%d������",i+1);
        scanf("%d",&a[i]);
    }
    printf("\n����ǰ��");
    for (i=0; i<10; i++)
    {
        printf("%-3d",a[i]);
    }
    printf("\n");   
    upstr(a);
    return 0;
}