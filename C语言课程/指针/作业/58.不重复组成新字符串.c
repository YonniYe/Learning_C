/*�������ܡ�
��һ���ַ������ҵ���һ��δ��������һ���ַ����е��ַ������ַ����д��ַ�֮ǰ�������ַ����һ���µ��ַ�����
�����Ҫ��
1����дvoid strsp(char *s1,char *s2,char *s3)�������������������������ҳ�s1ָ����ַ����е�һ��δ��s2ָ����ַ����г��ֵ��ַ���
��s1���и��ַ�ǰ�������ַ���Ϊһ�����ַ������Ƶ�s3ָ��������С� 
���磬s1�ַ���Ϊ��this is a test string����s2�ַ���Ϊ��a this������s1�����ҵ��ĵ�һ��δ������s2���е��ַ���'e'��s1�����ַ�'e'֮ǰ
�������ַ��ǡ�this is a t�������s3�ַ���Ϊ��this is a t����

2����дmain��������������������3���ַ����鲢�ò������ݳ�ʼ������2�����飬��3��������ʵ�ε���strsp�������������ַ��������ɵ�����
�����������Ļ

���������������н����
�������ݣ� s1�� "this is a test string"
        s2�� "a this"
    ����� this is a test string
            a this
            this is a t
*/
#include<stdio.h>
#include<string.h>
void strsp(char *s1,char *s2,char *s3)
{
    int len2,j;
    len2=strlen(s2);
    char *ps3=s3;
    char *ps2=s2;
    strcpy(s3,s1);    
    while (*ps3 != '\0')
    {
        for (j=0; j<len2; j++)
        {
            if(*ps3==*(ps2+j))
            {
                j=-1;   //���ж���j++����j���¸�ֵ�ܹؼ���
                ps3++;
            }
        }
        *ps3='\0';
    }
}

int main()
{
    char s1[50]="this is a test string";
    char s2[20]="a this";
    char s3[50];
    strsp(s1,s2,s3);
    puts(s3);
    return 0;
}