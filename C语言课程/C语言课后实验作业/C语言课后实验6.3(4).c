#include<stdio.h>
#include<string.h>
int StrToInt(char s[]) 
{
    int i,result=0;
    for(i=0; i<strlen(s); ++i) 
    {
        if(s[i] >= '0' && s[i] <= '9')  //��if�����������š�-�����Ӷ����������result��
        {
            result=10 * result +(s[i]-'0'); //'0'��ʾ0��ASCII��ֵ��s[i]ͬ��s[i]-'0'���������������ֵ
        }
    }
    if(s[0] == '-') //����и��Ŵ��ڣ�������������ɸ���
        result = -result;
    return result;
}

int main()
{
    char a[50];
    int i,x;
    puts("������һ�������ֹ��ɵ��ַ�����");
    gets(a);
    x=StrToInt(a);
    printf("�ַ�����%s��ת���ɵ�������Ϊ%d",a,x);
}
