#include <stdio.h>
int main()
{
    int len,*p0,*p1,n;
    int a[10],i;
    len=sizeof(a) / sizeof(int);
    p0=&a[0];   //ָ��������׵�ַ
    p1=&a[len-1];   //ָ�������β��ַ
    for (i=0; i<10; i++)
    {
        printf("������a[%d]��ֵ:",i);
        scanf("%d",&a[i]);
    }
    printf("����ǰ������:");
    for (i=0; i<10; i++)
    {
        printf("%3d",a[i]);
    }
    while(1)    //����ָ��ͬʱ���м��ƶ�ֱ������
    {
        n=*p1;
        *p1=*p0;
        *p0=n;
        p0++;
        p1--;
        if(p1<=p0)  //����Ԫ��Ϊ������ȡ�Ⱥţ�������С�ں�
            break;
    }
    printf("\n���ú������:");
    for (i=0; i<10; i++)
    {
        printf("%3d",a[i]);
    }
    return 0;
}