/*��Ҫ��
1.�����³����ܸ�������Ĵ���
2.�����޸�����е�һ�������ݣ��������������ӱ���������Ԥ�����������������������䣬Ҳ����ɾȥ������䡣
�������ܡ�
���³����к���findreplace�Ĺ�������s1ָ����ַ��������¼��s1������s2ָ����ַ��������¼��s2�����ǿմ���������0����s1����s2�������ǿմ���
����s1���в���s2��������s3ָ����ַ����滻��s1�����ҵ�������s2�����Ӵ�������s1����û�г���s2�����Ӵ��������滻��ʹ��������0������������1��
���������������н����
�����ַ����� s1��Ϊ"This is a sample program and sample data."
            s2��Ϊ"sample"
            s3��Ϊ"real"
        �����This is a real program and real data.
�����д����Դ����*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
int findreplace(char *s1, char *s2, char *s3)
{
    int i,j,k=0,t=0;      //��ʼ��k=0
    char temp[80];
    if(*s1=='\0'||*s2=='\0')
        return 0;
    for(i=0;s1[i]!='\0';i++)    //����s1��
    {
        for(j=i, k=0; s1[j]&&s1[j]==s2[k]; j++, k++)    //j=i��ʼ
        {
            if(s2[k]=='\0') 
            {
                strcpy(temp,&s1[j]);    //��s1[j]�Ժ��һ��ӹ�ȥ
                strcpy(s1+i,s3);    
                i=i+strlen(s3);     //s2�ĳ�s3
                strcpy(s1+i,temp);
                t=1;
            }
        }
    }
    return t;
}
int main()
{
    char s1[80]="This is a sample program and sample data.";
    char s2[10]="sample",s3[10]="real";
    int t;
    t=findreplace(s1,s2,s3);    //t��int����
    if(t) 
        puts(s1);     //if(t)�����ж�t�ǲ�����(Ҳ����1)
    else 
        printf("not found");
    getch();    //�ȴ�������������ټ���ִ����������
    return 0;
}