#include<stdio.h>
int count1,count2,count3;   //count1��������count2�Ǹ�����count3��0
void judge(int *p)
{
    int i;
    if(p[i]>0)
        count1++;
    else if(p[i]<0)
        count2++;
    else
        count3++;
}

int main()
{
    int i,a[10],*p=NULL;
    p=a;
    printf("��ֱ�����10��������\n");
    for (i=0; i<10; i++)
    {
        printf("�������%d������",i+1);
        scanf("%d",p+i);
    }
    for (i=0; i<10; i++)
    {
        judge(p[i]);
    }
    
    printf("��������Ϊ%d����������Ϊ%d��0�ĸ���Ϊ%d",count1,count2,count3);
    return 0;
}