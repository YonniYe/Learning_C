#include <stdio.h>
void fun(int (*p1)[3],int (*p2)[3]);
int main()
{
    int p1[3][3]={{7,8,9},{4,5,6},{1,2,3}} ;
    int p2[3][3] = {0};     //p2���ڴ���ת�ú������
    int i = 0, j = 0;
    fun(p1,p2);
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",*(*(p2+i)+j));    //*(*(p+i)+j)��ȫ�ȼ�p[i][j]
        }
    printf("\n");
    }        
    return 0;
}

void fun(int (*p1)[3],int (*p2)[3])     //�۲�һ��������ζ����βΣ���ά������Ҫint (*p)[]
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            *(p2[j]+i) = *(p1[i]+j);    //ָ������ͨ����ַ������ֵ
        }
    }
}