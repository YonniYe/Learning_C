#include <stdio.h>
#define N 80
int fun(int a[],int n)
{
    int i,j=1;
    for(i=1; i<n; i++)  //�����n��ԭ���鳤��
    {
        if(a[j-1] != a[i])  //�տ�ʼ�ǽ�a[0]��a[1]���бȽϣ�Ȼ��i������ֱ��a[0]��a[i]����ʱ���Ͱ�a[i]��ֵ��a[j]��j++��Ҳ����˵j�ǲ�ͬ���ֵĸ���
        {
            a[j] = a[i]; 
            j++;
        }
    }
    return j;
}

int main()
{    
    int i,n=21;
    int a[N]={2,2,2,3,4,4,5,6,6,6,6,7,7,8,9,9,10,10,10,10,11};
    printf("The original data:\n");
    for(i=0;i<n;i++) 
        printf("%3d",a[i]);
    n=fun(a,n);     //�ı������鳤��
    printf("\nThe data after deleted:\n");
    for(i=0;i<n;i++)    //��������a[]�ͳ���n���ı���
        printf("%3d",a[i]);
    printf("\n\n");
    return 0;
}